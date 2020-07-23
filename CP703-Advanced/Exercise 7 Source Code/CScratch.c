/******************************************************************************
*
* File: ex7.c
*
* System: C Programming Advanced, Exercise 7
* 
* Description: The program reads a binary file and creates an array of pointers
			   on the heap. The data is then sorted using qsort and the sorted
			   data is then displayed to stdout. The program then calculates
			   the distance between two specified zip codes.
*
* Revision History
* Date         Programmer Name     Description
* -----------  ------------------  ----------------
* 24-May-2005  Arsenio Locsin		Completed homework
*
 *****************************************************************************/
#include <stdlib.h>
#include <stdio.h>
#include <zips.h>
#include <search.h>

/***************************************************************************
 * constants
 ***************************************************************************/
#define LIMIT 10
/***************************************************************************
 * typedefs
 ***************************************************************************/

/***************************************************************************
 * prototypes
 ***************************************************************************/
static int compareStructArray(const void * left, const void * right);
static int comparePtrArray(const void * left, const void * right);
static int compareIntegers(const void * left, const void * right);
static int compareDoubles(const void * left, const void * right);
static int printIntegerArray(const int * integerArray, size_t numElements);
static int printDoubleArray(const double * doubleArray, size_t numElements);
extern void qsort_of(void * array, size_t numRecs, size_t elementSize, 
					 int compare(const void * left, const void * right));

/***************************************************************************
 * main function
 ***************************************************************************/
int main( void )
{
	int returnValue = FALSE;
	size_t numElements = 0;
	int integerArray[]= {10,5,3,7};
	double doubleArray[] = { 2.010, 2.005, 2.003, 2.007};
	size_t i = 0;

	/*************************************************************************
	* Variable list for Array of Structures
	**************************************************************************/
	ZIPS_data_p_t  zipsArray = NULL;
	ZIPS_data_p_t  * ptrArray = NULL;
	int num_recs = 0;
	void * fromPtr = NULL;
	void * toPtr = NULL;
	char * binary_file = "zips.bin";
	
	/**************************************************************************
	* Start Sort of Array of Integers Code
	**************************************************************************/
	numElements = sizeof(integerArray) / sizeof(int);
	puts("Show unsorted integer array");
	printIntegerArray(integerArray, numElements);
	qsort_of( integerArray, numElements, sizeof(int), compareIntegers);
	puts("Show sorted integer array");
	printIntegerArray(integerArray, numElements);
	/**************************************************************************
	* End Sort of Array of Integers Code
	**************************************************************************/

	/**************************************************************************
	* Start Sort of Array of Doubles Code
	**************************************************************************/
	numElements = sizeof(doubleArray) / sizeof(double);
	puts("Show unsorted array of doubles");
	printDoubleArray(doubleArray, numElements);
	qsort_of( doubleArray, numElements, sizeof(double), compareDoubles);
	puts("Show sorted array of doubles");
	printDoubleArray(doubleArray, numElements);
	/**************************************************************************
	* End Sort of Array of Doubles Code
	**************************************************************************/

	/**************************************************************************
	* Start Sort Array of Structures and Array of Pointers Code
	**************************************************************************/

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
		puts("\n==============================================");
		puts("Show unsorted array of structures.");
		ZIPS_print_recs(zipsArray, LIMIT);
		qsort_of(zipsArray, (size_t)num_recs, sizeof(*zipsArray), compareStructArray);
		puts("\nDisplay sorted array of structure.");
		ZIPS_print_recs(zipsArray, LIMIT);
		puts("==============================================");

		/* Create the array of pointers whose element points to an element in 
		   the array of structures.*/
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
		/* Create a new array of structures because the existing array of 
		   structures used previously is already sorted. */
		returnValue = ZIPS_read_recs_from_bin( binary_file,
											&zipsArray,
											&num_recs );
		
		for(i = 0; i < (size_t)num_recs; i++)
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
		puts("Display unsorted array of pointers to structures.");

		for( i = 0; i < LIMIT; i++)
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
		qsort_of( ptrArray, (size_t) num_recs, sizeof(ZIPS_data_t*), comparePtrArray);

		/* Write the data from the array of pointers by calling the 
		   ZIPS_print_rec function. The array is sorted.*/
		puts("\nDisplay sorted array of pointer to structure.");

		for( i = 0; i < LIMIT; i++)
		{		
			ZIPS_print_recs( ptrArray[i], 1);			
		}
			
		puts("********************************************************");
	}
	
	/* Free any memory allocated on the heap.*/
	free(zipsArray);
	zipsArray = NULL;
	free(ptrArray);
	ptrArray = NULL;
	/**************************************************************************
	* End Sort Array of Structures and Array of Pointers Code
	**************************************************************************/

	return returnValue;
}

static int compareStructArray(const void * left, const void * right)
{
	int returnValue = 0;
	ZIPS_data_t leftStruct = *(ZIPS_data_t*)left;
	ZIPS_data_t rightStruct = *(ZIPS_data_t*)right;

	if(leftStruct.zip_code < rightStruct.zip_code) returnValue = -1;
	if(leftStruct.zip_code == rightStruct.zip_code) returnValue = 0;
	if(leftStruct.zip_code > rightStruct.zip_code) returnValue = 1;

	return returnValue;
}

static int comparePtrArray(const void * left, const void * right)
{
	int returnValue = 0;
	ZIPS_data_p_t leftPtr= *(ZIPS_data_p_t*)left;
	ZIPS_data_p_t rightPtr= *(ZIPS_data_p_t*)right;

	if(leftPtr->zip_code < rightPtr->zip_code) returnValue = -1;
	if(leftPtr->zip_code == rightPtr->zip_code) returnValue = 0;
	if(leftPtr->zip_code > rightPtr->zip_code) returnValue = 1;

	return returnValue;
}

static int compareIntegers(const void * left, const void * right)
{
	int returnValue = 0;
	int leftValue = *(int *)left;
    int rightValue = *(int *)right;

	if(leftValue < rightValue) returnValue = -1;
	if(leftValue == rightValue) returnValue = 0;
	if(leftValue > rightValue) returnValue = 1;

	return returnValue;
}

static int compareDoubles(const void * left, const void * right)
{
	int returnValue = TRUE;
	double leftValue = *(double *)left;
	double rightValue = *(double *)right;

	if(leftValue < rightValue) returnValue = -1;
	if(leftValue == rightValue) returnValue = 0;
	if(leftValue > rightValue) returnValue = 1;

	return returnValue;
}

static int printIntegerArray(const int * integerArray, size_t numElements)
{
	size_t i = 0;
	
	for(i = 0; i < numElements; i++)
	{
		printf("%i ", integerArray[i]);
	}

	puts("\n");
	
	return TRUE;
}

static int printDoubleArray(const double * doubleArray, size_t numElements)
{
	size_t i = 0;
	
	for(i = 0; i < numElements; i++)
	{
		printf("%.3f ", doubleArray[i]);
	}
	
	puts("\n");

	return TRUE;
}