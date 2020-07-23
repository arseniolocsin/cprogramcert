/***************************************************************************
 *
 * File: zips3.c
 *
 * System: C Programming Advanced, Exercise 3
 * 
 * Description: 
 *
 * External Functions:
 *     ZIPS_parse_zips_rec
 *
 * Revision History
 * Date         Programmer Name     Description
 * -----------  ------------------  ----------------
 * 01-Apr-2005  Some Programmer     Original
 *****************************************************************************/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <zips.h>

#define FIELDS_FIPS_CODE	1
#define FIELDS_ZIP_CODE		2
#define FIELDS_STATE_ABBR	3
#define FIELDS_NAME			4
#define FIELDS_LONGTITUDE	5
#define FIELDS_LATITUDE		6
#define FIELDS_POPULATION	7
#define FIELDS_ALLOCATION	8
#define FIELDS_COUNT		8

#define FIELD_SEPERATOR		" ,\""

/***************************************************************************
 * Function: ZIPS_parse_zips_rec
 * Description:  parse the input buffer zips information and
 *              initialize the structure fields
 * Input:
 *    buf - char array that contains zips information 
 * Output:
 *    zips_rec - pointer to zips record
 * Return:
 *    TRUE - translated buffer without error
 *    FALSE - error translating buffer
 * Special Logic:
 *   If FALSE returned, parse_struct is NOT modified 
 ***************************************************************************/
extern int ZIPS_parse_zips_rec( char * buf, ZIPS_data_p_t zips_rec )
{
#define	LONG_STRING	1024
	ZIPS_data_t lzips_rec;
    return FALSE;
}


