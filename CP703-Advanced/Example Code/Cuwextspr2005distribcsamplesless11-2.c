/*************************************************************************
 * FILE:  less11-2.c
 *
 * DESCRIPTION: Program to demonstrate qsort and binary search
 *
 **************************************************************************/
#include <stdio.h>
#include <stdlib.h>

static void print_ints( int int_arr[], int num );
static int comp_ints( const void * left, const void * right );
static int * search_ints( int * array, int num, int num_to_find );

int main( void )
{
    int int_arr[] = { 15, 3, 14, 26, 37, 48, 10, 12, 1, 91 };
    int * val = NULL;

    print_ints( int_arr, 10 );

    qsort( int_arr, 10, sizeof(int), comp_ints );

    print_ints( int_arr, 10 );

    val = search_ints( int_arr, 10, 3  );

    printf( "found the %d!!\n", *val );
}

/*************************************************************************
 * search_ints - searches the integer array for the integer to find
 * Input:
 *      int_arr : the array to search
 *      num : number of integers in the array
 *      num_to_find: the number to find in the array
 * Return:
 *      pointer to found integer OR NULL if number not found
 ************************************************************************/
static int * search_ints( int * array, int count, int num_to_find )
{
    int * val = NULL;
    int top = count;
    int bottom = 0;

    while( bottom <= top && val == NULL)
    {
        int middle = (bottom + top)/ 2;

        if ( array[middle] == num_to_find ) {
            val = array+middle;
        }
        else if ( array[middle] < num_to_find ) {
            bottom = middle +1;
        }
        else {
            top = middle  - 1;
        }
    }

    return val;
}

/*************************************************************************
 * print_ints - prints an array of integers
 * Input:
 *      int_arr : the array to search
 *      num : number of integers in the array
 ************************************************************************/
static void print_ints( int int_arr[], int num )
{
    int inx;
    printf( "the int arr ==> " );
    for ( inx = 0; inx < num ; inx ++ )
        printf( "%d  ", int_arr[inx] );
    puts( "" );
}

/*************************************************************************
 * comp_ints - compares two integers for the qsort function.
 * Input:
 *      left : void pointer to an integer
 *      right : void pointer to another integer
 * Return:
 *      0 : there equal
 *     -1 : left < right
 *      1 : left > right
 ************************************************************************/
static int comp_ints( const void * left, const void * right )
{
/* 
   This isn't ANSI but common: return *(int *)left - *(int *)right;
*/
    int lleft = *(int *)left;
    int lright = *(int *)right;
    return (lleft < lright) ? -1 : (lleft > lright) ? 1 : 0;
}
