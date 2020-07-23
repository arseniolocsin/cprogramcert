/***************************************************************************
 *
 * File: zips5.c
 *
 * System: C Programming Advanced, Exercise 5
 * 
 * Description: 
 *
 * External Functions:
 *     ZIPS_read_recs_from_bin
 *
 * Revision History
 * Date         Programmer Name     Description
 * -----------  ------------------  ----------------
 * 02-May-2005  Arsenio Locsin		Finished writing the function
 *****************************************************************************/
#include <stdlib.h>
#include <zips.h>
#include <assert.h>

/***************************************************************************
 * Function: ZIPS_read_recs_from_bin
 * Description: read zips recs from a binary file
 * Input:
 *  datafile - binary file with zips records
 * Output:
 *   zips_ptr - pointer to array of zips records
 *   num_recs - pointer to integer representing number of records in array
 * Return:
 *    TRUE - read the records without error
 *    FALSE - some error encountered
 * Special Logic:
 *    if this function returns TRUE, memory has been allocated and
 *    assigned to zips_ptr
 *
 ***************************************************************************/
int ZIPS_read_recs_from_bin( char * binfile,
                             ZIPS_data_p_t * zips_ptr,
                             int * num_recs )
{
	int returnValue = FALSE;
	FILE * binaryFP = NULL;
	ZIPS_data_t * tempBuffer = NULL;
	int tempNumRecs = 0;
	int i = 0;
	
	assert( binfile );

	binaryFP = fopen( binfile, "rb");

	if( binaryFP )
	{
		puts("Opened binary file");
		returnValue = TRUE;
	}
	else
	{
		printf("Could not open binary file %s.\n", binfile);
		returnValue = FALSE;
	}

	if(returnValue)
	{
		/* Get the number of records in the binary file */
		fread(&tempNumRecs, sizeof(int), 1, binaryFP);

		/* Allocate memory on the heap for the buffer to contain the records 
		   read from the binary file.*/
		tempBuffer = malloc(tempNumRecs * sizeof(ZIPS_data_t));

		if(NULL != tempBuffer)
		{
			for(i = 0; i < tempNumRecs; i++)
			{				
				fread(&tempBuffer[i], sizeof(ZIPS_data_t), 1, binaryFP);
			}
			*num_recs = tempNumRecs;
			
			/* Set the value of the output parameter to the array of zips record 
			   to the address of the buffer that contains the records from the 
			   binary file.*/
			*zips_ptr = tempBuffer;
		}
		else
		{
			puts("Could not resize the buffer.");
			returnValue = FALSE;
		}
	}
	fclose(binaryFP);
	binaryFP = NULL;
	return returnValue;
}