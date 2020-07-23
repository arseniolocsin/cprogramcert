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
#define FIELDS_LONGITUDE	5
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
	int parse_success = TRUE;
	int field_count = 0;
	char lbuf[LONG_STRING + 1] = "";
	char * ptr = NULL;

	assert( buf );
	assert( zips_rec );

	strncpy( lbuf, buf, LONG_STRING );
	lbuf[LONG_STRING] = '\0';

	if (ptr = strchr( lbuf, '\n' ) )
		*ptr = '\0';

	ptr = strtok( lbuf, FIELD_SEPERATOR );

	while ( ptr)
	{
		field_count++;
		switch ( field_count )
		{
			case FIELDS_FIPS_CODE:
				{
					char * errptr = NULL;
					lzips_rec.fips_code = strtol( ptr, &errptr, 10 );
					if ( *errptr != '\0' )
						parse_success = FALSE;
				}
				break;
			case FIELDS_ZIP_CODE:
				{
					char * errptr = NULL;
					lzips_rec.zip_code = strtol( ptr, &errptr, 10 );
					if ( *errptr != '\0' )
						parse_success = FALSE;
				}
				break;
			case FIELDS_STATE_ABBR:
				strncpy( lzips_rec.state, ptr, ZIPS_STATE_LEN);
				lzips_rec.state[ZIPS_STATE_LEN] = '\0';
				break;
			case FIELDS_NAME:
				strncpy( lzips_rec.name, ptr, ZIPS_CODE_NAME_LEN);
				lzips_rec.state[ZIPS_CODE_NAME_LEN] = '\0';
				break;
			case FIELDS_LONGITUDE:
				{
					char * errptr = NULL;
					lzips_rec.longitude = strtod( ptr, &errptr );
					if ( *errptr != '\0' )
						parse_success = FALSE;
				}
				break;
			case FIELDS_LATITUDE:
				{
					char * errptr = NULL;
					lzips_rec.latitude = strtod( ptr, &errptr );
					if ( *errptr != '\0' )
						parse_success = FALSE;
				}
				break;
			case FIELDS_POPULATION:
				{
					char * errptr = NULL;
					lzips_rec.population = strtol( ptr, &errptr, 10 );
					if ( *errptr != '\0' )
						parse_success = FALSE;
				}
				break;
			case FIELDS_ALLOCATION:
				{
					char * errptr = NULL;
					lzips_rec.allocation = strtod( ptr, &errptr );
					if ( *errptr != '\0' )
						parse_success = FALSE;
				}
				break;
			default:
				parse_success = FALSE;
				break;
		}

		/* if the name field is next, special logic to handle spaces in name */
		if ( field_count+1 == FIELDS_NAME )
		{
			/* chew up any spaces between here and next double quote */
			ptr = parse_success ? ptr = strtok( NULL, "\"" ) : NULL;
			/* get name field with spaces */
			ptr = parse_success ? ptr = strtok( NULL, ",\"" ) : NULL;
		}
		else
		{
			ptr = parse_success ? ptr = strtok( NULL, FIELD_SEPERATOR ) : NULL;
		}
	}

	if ( field_count == FIELDS_COUNT && parse_success )
	{
		*zips_rec = lzips_rec;
		return TRUE;
	}

    return FALSE;
}