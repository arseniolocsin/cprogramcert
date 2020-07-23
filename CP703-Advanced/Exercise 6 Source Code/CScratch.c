/******************************************************************************
*
* File: ex6.c
*
* System: C Programming Advanced, Exercise 6
* 
* Description: The program reads a binary file and creates an array of pointers
			   on the heap. The data is then sorted using qsort and the sorted
			   data is then displayed to stdout. The program then calculates
			   the distance between two specified zip codes.
*
* Revision History
* Date         Programmer Name     Description
* -----------  ------------------  ----------------
* 11-May-2005  Arsenio Locsin		Completed homework
*
 *****************************************************************************/
#include <stdlib.h>
#include <stdio.h>
#include <zips.h>
#include <search.h>

/***************************************************************************
 * constants
 ***************************************************************************/
#define ROWS 5
/***************************************************************************
 * typedefs
 ***************************************************************************/

/***************************************************************************
 * prototypes
 ***************************************************************************/
static int compareStructures(const void * left, const void * right);
static int comparebSearch(const void * key, const void * array);
/***************************************************************************
 * main function
 ***************************************************************************/
int main( void )
{
	int returnValue = FALSE;
	ZIPS_data_p_t  zipsArray = NULL;
	ZIPS_data_p_t  * ptrArray = NULL;
	int num_recs = 0;
	int i = 0;
	void * fromPtr = NULL;
	void * toPtr = NULL;
	int zipCodes[ROWS][2]  = { {33147, 87729},
							   {98101, 97217},
							   {55767, 99362},
							   {99999, 36026},
							   {36026, 99999}
							 };
	double distance = 0;
	char * binary_file = "zips.bin";

	/* Read the data from the binary file by calling the
	   ZIPS_read_recs_from_bin function. */
	returnValue = ZIPS_read_recs_from_bin( binary_file,
										   &zipsArray,
										   &num_recs );
	
	/* If the function was able to read the binary file, create an array
	   of pointers and initialize each array element to an element in
	   the zip code array.*/
	
	if(returnValue)
	{
		ptrArray = malloc(num_recs * sizeof(ZIPS_data_p_t));
	}
	else
	{
		puts("Could not read binary file.");
		returnValue = FALSE;
	}

	if(NULL == ptrArray)
	{
		puts("Could not create the pointer array.");
		returnValue = FALSE;	
	}
	else
	{
		for(i = 0; i < num_recs; i++)
		{
			ptrArray[i] = &zipsArray[i];
		}
		returnValue = TRUE;
	}

	if(returnValue)
	{
		/* Write the data from the array of pointers by calling the 
		   ZIPS_print_rec function. The array is unsorted.*/
		puts("\n********************************************************");
		puts("Display unsorted array");
		puts("********************************************************");

		for( i = 0; i < num_recs; i++)
		{		
			ZIPS_print_recs( ptrArray[i], 1);			
		}
	}
	else
	{
		fprintf(stderr, "Error reading the binary file %s.\n", binary_file);
		returnValue = FALSE;
	}

	if(returnValue)
	{
		/*Sort the zip code array by passing the array of pointers to the qsort function.*/
		qsort( ptrArray, (size_t) num_recs, sizeof(ZIPS_data_t*), compareStructures);

		/* Write the data from the array of pointers by calling the 
		   ZIPS_print_rec function. The array is sorted.*/
		puts("\n\nDisplay sorted records");
		for( i = 0; i < num_recs; i++)
		{		
			ZIPS_print_recs( ptrArray[i], 1);			
		}

		/* Calculate and display the distance between two zip codes.*/
		puts("\n\nDistances between specified zip codes.");
		for(i = 0; i < ROWS; i++)
		{
			void * from = &zipCodes[i][0];
			void * to = &zipCodes[i][1];

			fromPtr = bsearch( from, 
							ptrArray, 
							num_recs,
							sizeof(ZIPS_data_t*), 
							comparebSearch );
		
			toPtr  =  bsearch( to, 
							ptrArray, 
							num_recs,
							sizeof(ZIPS_data_t*), 
							comparebSearch);

			if(NULL == fromPtr )
			{
				printf("Could not find the starting zip code %d.\n", zipCodes[i][0]);
				returnValue = FALSE;
			}

			if(NULL == toPtr )
			{
				printf("Could not find the destination zip code %d.\n", zipCodes[i][1]);
				returnValue = FALSE;
			}

			if(NULL != fromPtr && NULL != toPtr)
			{
				/* Display the distance between specified zip codes.*/
				distance = ZIPS_compute_distance( *(ZIPS_data_p_t*)fromPtr, 
												  *(ZIPS_data_p_t*)toPtr );

				printf("Distance from %i to %i is %0.2f miles\n", zipCodes[i][0], 
																  zipCodes[i][1], distance);
				returnValue = TRUE;
			}

			fromPtr = NULL;
			toPtr = NULL;
			from = NULL;
			to = NULL;
		}
	}
	
	/* Free any memory allocated on the heap.*/
	free(zipsArray);
	zipsArray = NULL;
	free(ptrArray);
	ptrArray = NULL;

	return returnValue;
}

static int compareStructures(const void * left, const void * right)
{
	int returnValue = 0;
	ZIPS_data_p_t leftStruct= *(ZIPS_data_p_t*)left;
	ZIPS_data_p_t rightStruct= *(ZIPS_data_p_t*)right;

	if(leftStruct->zip_code < rightStruct->zip_code) returnValue = -1;
	if(leftStruct->zip_code == rightStruct->zip_code) returnValue = 0;
	if(leftStruct->zip_code > rightStruct->zip_code) returnValue = 1;

	return returnValue;
}

static int comparebSearch(const void * key, const void * array)
{
	int returnValue = 0;
	int keyValue = *(int *)key;
    ZIPS_data_p_t arrayValue = *(ZIPS_data_p_t *)array;

	if(keyValue < arrayValue->zip_code) returnValue = -1;
	if(keyValue == arrayValue->zip_code) returnValue = 0;
	if(keyValue > arrayValue->zip_code) returnValue = 1;

	return returnValue;
}