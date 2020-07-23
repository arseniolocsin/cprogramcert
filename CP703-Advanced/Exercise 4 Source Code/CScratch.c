/******************************************************************************
 *
 * File: ex4.c
 *
 * System: C Programming Advanced, Exercise 4
 * 
 * Description: This program tests the ZIPS_create_bin_from_ascii function.
 *
 * Revision History
 * Date         Programmer Name     Description
 * -----------  ------------------  ----------------
 * 24-Apr-2005  Arsenio Locsin		Created program
 *****************************************************************************/
#include <stdlib.h>
#include <stdio.h>
#include <zips.h>

/***************************************************************************
 * constants
 ***************************************************************************/
#define ROWS 8
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
   	FILE * textFP = NULL;
	FILE * binaryFP = NULL;
	int readCounter = 0;
	int skipCounter = 0;
	int returnValue = 0;
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

	for(i=0; i < ROWS; i++) 
	{		
		printf("\nTest File: %s\n", testFiles[i] [0]);
		printf("Binary File: %s\n", testFiles[i] [1]);
		printf("Expected Result: %s\n", testFiles[i] [2]);
		returnValue = ZIPS_create_bin_from_ascii(testFiles[i] [0], 
												 testFiles[i] [1], 
												 &readCounter, 
												 &skipCounter);	
	}

    return EXIT_SUCCESS;
}