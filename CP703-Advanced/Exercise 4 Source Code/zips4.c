/***************************************************************************
 *
 * File: zips4.c
 *
 * System: C Programming Advanced, Exercise 4
 * 
 * Description: 
 *
 * External Functions:
 *     ZIPS_parse_zips_rec
 *
 * Revision History
 * Date         Programmer Name     Description
 * -----------  ------------------  ----------------
 * 26-Apr-2005  Arsenio Locsin		Completed the ZIPS_create_bin_from_ascii function
 *****************************************************************************/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <zips.h>

#define MAXCHAR 1024

/***************************************************************************
 * Function: ZIPS_create_bin_from_ascii
 * Description: read zips recs from an ASCII file and creates a
 *     binary file of ZIPS_data_t records 
 * Input:
 *   ascii_file - ASCII file with zips records
 *   binary_file - binary file with zips records
 * Output:
 *   recs_read - number of records parsed and written to binary file
 *   recs_skipped - number of records that failed parsing, excluding comments
 * Return:
 *    TRUE - successfully read ascii file and created binary file
 *    FALSE - did NOT successfully read ascii file and created binary file
 * Special Logic:
 *    If TRUE returned, binary file was created.
 ***************************************************************************/
int ZIPS_create_bin_from_ascii( char * ascii_file, char * binary_file,
                                int * recs_read, int * recs_skipped )
{	
	int returnValue = FALSE;
	ZIPS_data_t zips_rec;
	FILE * textFP = NULL;
	FILE * binaryFP = NULL;
	size_t numWrite = 0;
	char textBuffer[MAXCHAR];
	int readCounter = 0;
	int skippedCounter = 0;
	int totalRecords = 0;

	/* End the program if any of the pointers are null. */
	assert( ascii_file );
	assert( binary_file );

	textFP = fopen(ascii_file, "r");
	
	if(NULL == textFP)
	{
		puts("Could not open specified file. Program will end now.");
		return EXIT_FAILURE;
	}
	
	binaryFP = fopen(binary_file, "wb");

	if(NULL == binaryFP)
	{
		puts("Could not open binary file. Program will end now.");
		return EXIT_FAILURE;
	}

	/* Create a space in the binary file for the number of records read. */
	numWrite = fwrite(&recs_read, sizeof(int), 1, binaryFP);

	if(!numWrite)
	{
		puts("Could not write to the binary file. Program will end now.");
		return EXIT_FAILURE;	
	}

	while( NULL != fgets(textBuffer, MAXCHAR, textFP))
	{
		/* Parse the line if the line doesn't begin with a comment character*/
		if(textBuffer[0] != '#')
		{
			returnValue = ZIPS_parse_zips_rec( textBuffer, &zips_rec );

			/* If the line was successfully parsed, write the information to the
			binary file and increment the recs_read counter. If the line could
			not be parsed, increment the recs_skipped counter.*/

			if(!returnValue)
			{	
				skippedCounter++;
			}
			else
			{
				fwrite(&zips_rec, sizeof(zips_rec), 1, binaryFP);
				readCounter++;			
			}
		}
	}
	
	totalRecords = readCounter + skippedCounter;

	if( totalRecords)
	{
		rewind(binaryFP);
		numWrite = fwrite(&recs_read, sizeof(int), 1, binaryFP);
		puts("The binary file was successfully created.");
		returnValue = TRUE;	
		
		if(1 == totalRecords)
		{
			puts("One record was read.");		
		}
		else
		{
			printf( "%i records were read.\n", totalRecords);
		}
		
		switch(readCounter)
		{
			case 0:
				puts("No records were added to the binary file.");
				break;

			case 1:
				puts("There was one record written to the binary file.");
				break;

			default:
				printf("There was %i records written to the binary file.\n", readCounter);
				break;		
		}

		switch(skippedCounter)
		{
			case 0:
				puts("No records were skipped.");
				break;

			case 1:
				puts("There was one record that was skipped.");
				break;

			default:
				printf("There was %i records skipped.", skippedCounter);
				break;
		}
		*recs_read = readCounter;
		*recs_skipped = skippedCounter;
	}
	else
	{	
		puts("Could not create binary file.");
		returnValue = FALSE;
	}

	/* Close file pointers */ 
 	fclose(textFP);
	fclose(binaryFP);

	/* If an error occurs, delete the binary file */
	if(!returnValue)
	{
		remove( binary_file);
	}

	return returnValue;
}