#ifndef ZIPS_H_INCLUDED
#define ZIPS_H_INCLUDED
/******************************************************************************
 *
 * File: zips.h
 *
 * System: ZIPS 
 * 
 * Description: The include file for ZIPS  dependencies 
 *
 * Revision History
 * Date           Programmer Name     Description
 * -------------  ------------------  ----------------
 * 01-April-2005  Some Programmer     Original
 *****************************************************************************/

/******************************************************************************
 * includes
 ******************************************************************************/
#include <stdio.h>

/******************************************************************************
 * macros and constants
 ******************************************************************************/
#ifndef M_PI
#define M_PI (3.14159265)
#endif

#ifndef TRUE
#define TRUE           (1)
#endif

#ifndef FALSE
#define FALSE          (0)
#endif

#define ZIPS_STATE_LEN       (2)
#define ZIPS_CODE_NAME_LEN   (20)

/******************************************************************************
 * typedefs
 ******************************************************************************/
typedef int ZIPS_state_fips_code_t;
typedef int ZIPS_state_zip_code_t;
typedef char ZIPS_state_abbr_t[ZIPS_STATE_LEN+1];
typedef char ZIPS_code_name_t[ZIPS_CODE_NAME_LEN+1];
typedef double ZIPS_longitude_t;
typedef double ZIPS_latitude_t;
typedef int ZIPS_population_t;
typedef double ZIPS_allocation_t;

typedef struct ZIPS_data_tag
{
     ZIPS_state_fips_code_t  fips_code;
     ZIPS_state_zip_code_t   zip_code;
     ZIPS_state_abbr_t       state;
     ZIPS_code_name_t        name;
     ZIPS_longitude_t        longitude;
     ZIPS_latitude_t         latitude;
     ZIPS_population_t       population;
     ZIPS_allocation_t       allocation;
} ZIPS_data_t, * ZIPS_data_p_t;

/******************************************************************************
 * prototypes
 ******************************************************************************/
/***************************************************************************
 * Function: ZIPS_parse_zips_rec
 * Description: 
 * Input:
 *   str - string with zips data
 * Output:
 *   ptr - pointer to structure with fields set from contents 
 *         of str
 * Return:
 *   int - TRUE - parse string OK, set structure fields
 *         FALSE - parse string failed
 * Special Logic:
 *   If FALSE returned, parse_struct is NOT modified 
 ***************************************************************************/
extern int ZIPS_parse_zips_rec( char * str, ZIPS_data_p_t ptr );

/***************************************************************************
 * Function: ZIPS_print_recs
 * Description: print zips recs from an array
 * Input:
 *   arr - array of zips recs or pointer to zips rec
 *   num_recs - number of records in array
 * Output:
 *   None
 * Return:
 *   None
 * Special Logic:
 *   None
 ***************************************************************************/
extern void ZIPS_print_recs( ZIPS_data_p_t arr, int num_recs );

/***************************************************************************
 * Function: ZIPS_create_bin_from_ascii
 * Description: read zips recs from an ASCII file and creates a
 *     binary file of ZIPS_data_t records 
 * Input:
 *   ascii_file - ASCII file with zips records
 *   binary_file - binary file with zips records
 * Output:
 *   recs_read - number of records parsed and written to binary file
 *   recs_skipped - number of records that failed parsing, excluding comments
 * Return:
 *    TRUE - successfully read ascii file and created binary file
 *    FALSE - did NOT successfully read ascii file and created binary file
 * Special Logic:
 *    If TRUE returned, binary file was created.
 ***************************************************************************/
extern int ZIPS_create_bin_from_ascii( char * ascii_file, char * binary_file,
                                       int * recs_read, int * recs_skipped );
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
extern int ZIPS_read_recs_from_bin( char * binfile,
                                    ZIPS_data_p_t * zips_ptr,
                                    int * num_recs );

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
extern double ZIPS_compute_distance( ZIPS_data_p_t zip1, ZIPS_data_p_t zip2 );
#endif

