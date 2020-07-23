/******************************************************************************
 *
 * File: ex3.c
 *
 * System: C Programming Advanced, Exercise 3
 * 
 * Description: This program tests the ZIPS_parse_zips_rec function.
 *
 * Revision History
 * Date         Programmer Name     Description
 * -----------  ------------------  ----------------
 * 18-Apr-2005  Arsenio Locsin		Completed ZIPS_parse_zips_rec function in
									zips3.c
 *****************************************************************************/
#include <stdlib.h>
#include <stdio.h>
#include <zips.h>

/***************************************************************************
 * constants
 ***************************************************************************/

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
    ZIPS_data_t zips_rec;
    char * zips_str = "\"44\",\"02804\",\"RI\",\"ASHAWAY\",71.783745,41.423054,2472,0.002463 ";

    if ( ZIPS_parse_zips_rec( zips_str, &zips_rec ) )
    {
        printf( "Parsed this string: %s\n", zips_str );
        ZIPS_print_recs( &zips_rec, 1 );
    }
    else
    {
        fprintf( stderr, "Failed to parse string >>%s<<\n", zips_str );
    }

    return EXIT_SUCCESS;
}
