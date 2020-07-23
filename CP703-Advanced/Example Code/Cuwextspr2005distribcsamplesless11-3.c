C:\uwext\spr2005\distrib\csamples\less11-3.c.html/*************************************************************************
 * FILE:  less11-3.c
 *
 * DESCRIPTION: Program to demonstrate qsort algorithm
 *
 **************************************************************************/
#include <stdio.h>
#include <stdlib.h>

void qsort_of( int * array, int count );
static void swap( int * lo_elm,  int * hi_elm );
static void prnt_ints( char * str, int p[], int num );

int num_swaps = 0;
int num_cycles = 0;
int num_parts = 0;

static print_ints( char * msg, int * array, int count )
{
    int inx = 0;
    printf( msg );
    for ( inx = 0; inx < count-1; inx++ )
       printf( "%.3d <> ", array[inx] );
    printf( "%.3d\n", array[inx] );
}

static void swap( int * lo_obj, int * hi_obj )
{
    if ( lo_obj != hi_obj )
    {
        int tmp = *lo_obj;
        *lo_obj = *hi_obj;
        *hi_obj = tmp;
        num_swaps++;
    }
}

int main( void )
{
#define CARD( aaa ) (sizeof(aaa)/sizeof(*(aaa)))

    int inx = 0;
    int nums[10];

    for ( inx = 0; inx < CARD(nums); inx++)
        nums[inx] = rand( )%1000;

    print_ints( "Before sort: ", nums, CARD(nums) );
    qsort_of( nums, CARD(nums) );
    print_ints( "After sort:  ", nums, CARD(nums) );
    printf( "num_cycles %d :: num_swaps %d\n", num_cycles, num_swaps );
}

/*
 * The qsort_of function uses the qsort algorithm (also known as
 * divide and conquer) to sort an array of integers.  The standard
 * library version of this function sorts arrays generically and is the
 * one you should use in practice.  Please refer to the Data Structures
 * and Program Design in C, Section 7.8 for details.
 */
static int partition( int * array, int count );
void qsort_of( int * array, int count )
{
    if ( count > 1 )
    {
        /* partition divides array in to two buckets
         * then call qsort_of to recursively sort each bucket */
        int pivot = partition( array, count );
        qsort_of( array, pivot );
        qsort_of( &array[pivot+1], count - (pivot+1) );
    }
}


/*******************************************************************************
 * partition - partitions array in to two buckets.  The partition position
 *    defines the index of division between buckets.  Objects to the left are 
 *    lower in value then the partition.  Objects to the right are higher in 
 *    value then the partition. 
 * Input:  array 
 * Output: count
 * Returns: partition position
 ******************************************************************************/
static int partition( int * array, int count )
{
    int pivot = 0;
    int inx = 0;

    /* arbitrarily choose middle object as pivot 
     * and move it to head of the array. */
    swap( &array[0], &array[count/2] );

    /* loop through the rest of the array
     * looking for objects smaller then pivot 
     * object.   If found move object to 
     * pivot - really lastsmall position */

    for ( inx = 1; inx < count; num_cycles++,inx++ )
    {
        if ( array[inx] < array[0] )
        {
            swap( &array[++pivot], &array[inx] );
        }
    }

    /* move pivot to partition position */
    swap( &array[0], &array[pivot] );
    return pivot;
}
