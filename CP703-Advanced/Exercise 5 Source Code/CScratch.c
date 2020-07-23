/******************************************************************************
*
* File: ex5.c
*
* System: C Programming Advanced, Exercise 5
* 
* Description: This program tests the ZIPS_read_recs_from_bin function.
*
* Revision History
* Date         Programmer Name     Description
* -----------  ------------------  ----------------
* 30-Apr-2005  Arsenio Locsin		Completed homework
*
 *****************************************************************************/
#include <stdlib.h>
#include <stdio.h>
#include <zips.h>

/***************************************************************************
 * constants
 ***************************************************************************/
#define MY_DEBUG 0		/* 0 for test mode
						   1 for homework mode */

/***************************************************************************
 * typedefs
 ***************************************************************************/

/***************************************************************************
 * prototypes
 ***************************************************************************/

/***************************************************************************
 * main function
 ***************************************************************************/
int main( void )
{
	int readCounter = 0;
	int skipCounter = 0;
	int returnValue = 0;
	ZIPS_data_p_t  zipsArray = NULL;
	int num_recs = 0;

#if MY_DEBUG == 1

	//char * ascii_file = "zips_short03.txt";
	//char * ascii_file = "zips02.txt";
	char * ascii_file = "zips_various.txt";
	char * binary_file = "zips.bin";

	puts("Homework Mode");

	returnValue = ZIPS_create_bin_from_ascii( ascii_file, binary_file,
									          &readCounter, &skipCounter );

	if ( returnValue )
	{
		printf( "Created %s from %s.\n", binary_file, ascii_file );
		printf( "Read %d records, skipped %d records.\n", readCounter, skipCounter );
	}
	else
	{
		fprintf( stderr, "Error creating%s.\n", binary_file );
		returnValue = FALSE;
	}

	if(returnValue)
	{
		/* Read the data from the binary file by calling the
		   ZIPS_read_recs_from_bin function. */
		returnValue = ZIPS_read_recs_from_bin( binary_file,
											   &zipsArray,
											   &num_recs );
	}

	if(returnValue)
	{
		printf("Number of records: %d\n", num_recs);

		/* Display the record by calling the ZIPS_print_rec function. */
		ZIPS_print_recs( zipsArray, num_recs);

		/* Free the memory allocated on the heap in the ZIPS_read_rec_from_bin
		   function and set the pointer to NULL. Is there a way to design
		   the program so that the memory is freed in the function used? */
		free(zipsArray);
		zipsArray = NULL;
	}
	else
	{
		fprintf(stderr, "Error reading the binary file %s.\n", binary_file);
		returnValue = FALSE;
	}

#else
	
	#define ROWS 8

	int i = 0;
	char *testFiles[ROWS] [3] =
	{
		{"zips_short.txt", "zips_short.bin", "20 read, 0 skipped"},
		{"zips_various.txt", "zips_various.bin", "10 read, 27 skipped"},
		{"zips_comments_only.txt", "zips_comments_only.bin", "No binary file"},
		{"zips_long.txt", "zips_long.bin", "500 read, 0 skipped"},
		{"zips_short_1.txt", "zips_short_1.bin", "1 read, 0 skipped"},
		{"zips.txt", "zips.bin", "29470 read, 0 skipped"},
		{"zips_empty.txt", "zips_empty.bin", "Empty file"},
		{"none.txt", "none.bin", "File doesn't exist"}	
	};
	puts("******************************************************************");
	puts("* Test Mode ");
	puts("******************************************************************");

	for(i=0; i < ROWS; i++) 
	{		
		printf("\nTest File: %s\n", testFiles[i] [0]);
		printf("Binary File: %s\n", testFiles[i] [1]);
		printf("Expected Result: %s\n", testFiles[i] [2]);

		returnValue = ZIPS_create_bin_from_ascii(testFiles[i] [0], 
												 testFiles[i] [1], 
												 &readCounter, 
												 &skipCounter);			

		if(returnValue)
		{
			returnValue = ZIPS_read_recs_from_bin( testFiles[i] [1],
											   &zipsArray,
											   &num_recs );

			printf("Number of records: %d\n", num_recs);

			/* Display the record by calling the ZIPS_print_rec function. */
			ZIPS_print_recs( zipsArray, num_recs);

			/* Free the memory allocated on the heap in the ZIPS_read_rec_from_bin
			function and set the pointer to NULL. Is there a way to design
			the program so that the memory is freed in the function used? */
			free(zipsArray);
			zipsArray = NULL;
			readCounter = 0;
			skipCounter = 0;
		}
		else
		{
			fprintf(stderr, "Error reading the binary file %s.\n", testFiles[i] [1]);
			returnValue = FALSE;
		}
	}

#endif

	return returnValue;
}