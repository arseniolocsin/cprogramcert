/***************************************************************************
 *
 * File: zips.c
 *
 * System: ZIPS 
 * 
 * Description: 
 *
 * External Functions:
 *  ZIPS_print_recs
 *  ZIPS_compute_distance
 *
 * Revision History
 * Date         Programmer Name     Description
 * -----------  ------------------  ----------------
 * 01-Apr-2005  Some Programmer     Original
 *****************************************************************************/
#include <stdlib.h>
#include <math.h>
#include <zips.h>

/***************************************************************************
 * Function: ZIPS_print_recs
 * Description: print zips recs from an array
 * Input:
 *   arr - array of zips recs
 *   num_recs - number of records in array
 * Output:
 *   None
 * Return:
 *   None
 * Special Logic:
 *   fips_code and factor are intentionally omitted from print.
 ***************************************************************************/
extern void ZIPS_print_recs( ZIPS_data_p_t zips_arr, int num_recs )
{
    int inx = 0;
    for ( inx = 0 ; inx < num_recs ; inx++ )
    {
        printf( "==> %05d %2s %s %.4f %.4f %d\n",
                 zips_arr[inx].zip_code,
                 zips_arr[inx].state,
                 zips_arr[inx].name,
                 zips_arr[inx].longitude,
                 zips_arr[inx].latitude,
                 zips_arr[inx].population );
    }
}
/***************************************************************************
 * Function: ZIPS_compute_distance
 * Description: compute distance between two ZIPS records
 * Input:
 *   zip1 - one ZIPS records
 *   zip2 - another ZIPS records
 * Output:
 *   None
 * Return:
 *   distance between the zips
 * Special Logic:
 *   None
 ***************************************************************************/
extern double ZIPS_compute_distance( ZIPS_data_p_t zip1, ZIPS_data_p_t zip2 )
{
#define DEG2RAD      ((M_PI)/180)
#define EARTHRADIUS  (3960)
#define EARTHCIRCUM  (2*(EARTHRADIUS)*(M_PI))
    double lat1 = 0;
    double lat2 = 0;
    double long_miles1 = 0;
    double long_miles2 = 0;
    double lat_miles  = 0;
    double miles = 0;


    lat1 = cos( zip1->latitude * DEG2RAD ) * EARTHCIRCUM;
    lat2 = cos( zip2->latitude * DEG2RAD ) * EARTHCIRCUM;
    long_miles1 = lat1 * fabs( zip1->longitude - zip2->longitude) / 360.0;
    long_miles2 = lat2 * fabs( zip1->longitude - zip2->longitude) / 360.0;
    lat_miles  = EARTHCIRCUM * fabs( zip1->latitude - zip2->latitude ) / 360.0;

    lat_miles  *=  lat_miles;
    miles = long_miles1 - ((long_miles1 - long_miles2)/2.0);
    miles *= miles;
    miles = sqrt( lat_miles + miles );

    return miles;
}