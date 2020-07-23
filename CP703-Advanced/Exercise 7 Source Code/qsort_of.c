 /*****************************************************************************
 * File: qsort_of.c
 *
 * System: C Programming Advanced, Exercise 7
 * 
 * Description: Another implementation of a qsort algorithm
 *
 * Revision History
 * Date         Programmer Name     Description
 * -----------  ------------------  ----------------
 * 24-May-2005  Arsenio Locsin		Completed coding
 *****************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

void qsort_of(void * array, size_t numRecs, size_t elementSize, 
			  int compare(const void * left, const void * right));

static void swap( char * lo_obj, char * hi_obj, size_t elementSize);

static size_t partition( void * array, size_t count, size_t elementSize, 
						 int compare(const void * left, const void * right) );

static void swap( char * lo_obj, char * hi_obj, size_t width )
{
	char * tmp = malloc(width);
    
	if ( lo_obj != hi_obj )
    {
		memcpy(tmp, lo_obj, width);
		memcpy(lo_obj, hi_obj, width);
		memcpy(hi_obj, tmp, width);
    }
	
	free(tmp);
	tmp = NULL;
}

void qsort_of(void * array, size_t numRecs, size_t elementSize, 
			  int compare(const void * left, const void * right))
{
	if ( numRecs > 1 )
    {
        size_t pivot = partition( array, numRecs, elementSize, compare );
        qsort_of(array, pivot, elementSize, compare );
        qsort_of((char *)array + ((pivot + 1) * elementSize), numRecs - (pivot+1), elementSize, compare );
    }
}

static size_t partition( char * array, size_t count, size_t elementSize, 
						 int compare(const void * left, const void * right) )
{
    size_t pivot = 0;
    size_t inx = 0;

    swap( array, array + ((count/2)* elementSize), elementSize );

	for ( inx = 1; inx < count; inx++ )
    {
		if( 0 > compare(array + (inx * elementSize), array))
        {
            swap( array + ((++pivot)* elementSize), array+ (inx * elementSize), elementSize );
        }
    }

    swap(array, array + (pivot * elementSize), elementSize );
 
	return pivot;
}