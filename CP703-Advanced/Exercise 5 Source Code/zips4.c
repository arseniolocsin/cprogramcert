/***************************************************************************
 *
 * File: zips4.c
 *
 * System: C Programming Advanced, Exercise 4
 * 
 * Description: 
 *
 * External Functions:
 *     ZIPS_create_bin_from_ascii
 *
 * Revision History
 * Date         Programmer Name     Description
 * -----------  ------------------  ----------------
 * 30-Apr-2005  Arsenio Locsin		Copied instructor's implementation
 *****************************************************************************/
#include <stdlib.h>
#include <zips.h>
#include <assert.h>

/*****************************************************************************
* Function: init_bin_file
* Description: open/create binary file and write 4 byte header
* Input: binary_file - binary file with zips records
* Output: none
* Return: file pointer
* Special Logic: none
*****************************************************************************/
static FILE * init_bin_file( char * binary_file )
{
	FILE * bin_fptr = NULL;
	int num_written = 0;
	bin_fptr = fopen( binary_file, "wb");
	if ( bin_fptr && fwrite ( &num_written, sizeof( int), 1, bin_fptr ) != 1 )
	{
		
		fclose( bin_fptr );
		bin_fptr = NULL;
	}
	return bin_fptr;

}

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
int ZIPS_create_bin_from_ascii( char * ascii_file, char * binary_file,
                                int * recs_read, int * recs_skipped )
{	
	int result = TRUE;
	ZIPS_data_t zips_rec;
	FILE * ascii_fptr = NULL;
	FILE * bin_fptr = NULL;
	char buf[BUFSIZ + 1] = "";

	assert( ascii_file );
	assert( binary_file );
	assert( recs_read );
	assert( recs_skipped );

	if ( (ascii_fptr = fopen( ascii_file, "r" ) ) == NULL )
	
		result = FALSE;

		while( result && fgets( buf, BUFSIZ, ascii_fptr ) )
		{
#ifdef MY_DEBUG
			printf( "from file==>%s<==\n", buf);
#endif
			if ( buf[0] != '#' )
			{
				if (ZIPS_parse_zips_rec( buf, &zips_rec ) )
				{
#ifdef MY_DEBUG
					ZIPS_print_recs( &zips_rec, 1 );		
#endif
					/* at least 1 valid record parsed before creating binary file */
					if ( bin_fptr == NULL )
						bin_fptr = init_bin_file( binary_file );

					/* file open failed or can't write record */
					if ( bin_fptr == NULL ||
						fwrite( &zips_rec, sizeof( ZIPS_data_t ), 1, bin_fptr ) != 1 )
						result = FALSE;
					/* file write success */
					else
						(*recs_read)++;
				}
				
			}
			else
			{
				(*recs_skipped)++;
			}
		}
	
	/* input file is corrupt or didn't write records to binary file */
	if ( (ascii_fptr != NULL && !feof( ascii_fptr )) || bin_fptr == NULL )
		result = FALSE;

	/* all OK, rewind file and set count */
	else if (result )
	{
#ifdef MY_DEBUG
		printf( "Recs Read ==>%d\n", *recs_read );
#endif
		rewind( bin_fptr );
		if ( fwrite( recs_read, sizeof( int ), 1, bin_fptr ) != 1)
			result = FALSE;
	}
	
	if ( ascii_fptr )
		fclose( ascii_fptr );

	if ( bin_fptr )
		fclose( bin_fptr );

	return result;
}