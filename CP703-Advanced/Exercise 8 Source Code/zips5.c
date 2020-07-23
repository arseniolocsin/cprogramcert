#include <stdlib.h>
#include <zips.h>
#include <assert.h>

#define MY_FCLOSE( file  ) (file?(fclose(file),file=NULL):NULL)
#define MY_FREE( pointer ) (pointer?(free(pointer),pointer=NULL):NULL )

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
int ZIPS_read_recs_from_bin( char * binfile,
                             ZIPS_data_p_t * zips_ptr,
                             int * num_recs )
{
	ZIPS_data_t		*lzips_ptr	= NULL;
	FILE *			zips_bfile	= NULL;
	int				lnum_recs	= 0;
	int				success		= TRUE;
	
	assert( binfile );
	assert( zips_ptr );
	assert(num_recs );

	if ( ( zips_bfile = fopen( binfile, "rb") ) == NULL )
	{
		success = FALSE;
	}
	else if ( fread( &lnum_recs, sizeof(int), 1, zips_bfile ) != 1 )
	{
		success = FALSE;
	}
	else if ( ( lzips_ptr = malloc( lnum_recs * sizeof( ZIPS_data_t ) ) ) == NULL )
	{
		success = FALSE;
	}
	else if ( fread( lzips_ptr, sizeof(ZIPS_data_t), lnum_recs, zips_bfile ) != lnum_recs )
	{
		success = FALSE;
	}
	if ( success )
	{
		*num_recs = lnum_recs;
		*zips_ptr = lzips_ptr;
	}
	else
	{
		MY_FREE( lzips_ptr );
	}
	MY_FCLOSE( zips_bfile );

	return success;

}