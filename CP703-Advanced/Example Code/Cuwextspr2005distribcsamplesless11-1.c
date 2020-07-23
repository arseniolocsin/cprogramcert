C:\uwext\spr2005\distrib\csamples\less11-1.c.html/*************************************************************************
 * FILE: less11-1.c
 *
 * DESCRIPTION: Program to demonstrate simple sort and search
 *              This sort and search represents the worst case and
 *              least efficient approach.
 *
 **************************************************************************/
#include <stdio.h>

static void print_ints( int int_arr[], int num );
static void swap_ints( int * left, int * right );
static void selection_sort_ints( int * arr, int num );
static int search_ints( int * int_arr, int num, int num_to_find );

int main( void )
{
    int int_arr[10] = { 5, 3, 4, 6, 7, 8, 10, 2, 1, 9 };
    int val = -1;

    print_ints( int_arr, 10 );

    selection_sort_ints( int_arr, 10 );

    print_ints( int_arr, 10 );

    val = search_ints( int_arr, 10, 3 );

    printf( "found the %d!!\n", val );
}


static void selection_sort_ints( int * int_arr, int num )
{
    int inx = 0, jnx = 0;
    int item = -1;
    int num_cycles = 0, num_swaps = 0;

    for ( inx = 0; inx < num; inx++ )
    {
      item = inx;
      for ( jnx = inx+1; jnx < num; jnx++ )
      {
         num_cycles++;
         if ( int_arr[jnx] < int_arr[item] )
         {
            item = jnx;
         }
      }
      if ( item != inx )
      {
        num_swaps++;
        swap_ints( &int_arr[inx], &int_arr[item] );
      }
    }
    printf( "num_cycles %d :: num_swaps %d\n", num_cycles, num_swaps );
}

static void print_ints( int int_arr[], int num )
{
    int inx;
    printf( "the int arr ==> " );
    for ( inx = 0; inx < num ; inx ++ )
        printf( "%d  ", int_arr[inx] );
    puts( "" );
}

static void swap_ints( int * left, int * right )
{
    int tmp;
    tmp   = * right;
    * right = * left;
    * left  = tmp;
}

static int search_ints( int * int_arr, int num, int num_to_find )
{
    int inx = 0;
    int val = 0;

    val = -1;
    for ( inx = 0; inx < num && val == -1 ; inx++ )
    {
      if ( int_arr[inx] == num_to_find )
        val = num_to_find;
    }
    return val;
}
