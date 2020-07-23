/******************************************************************************
 *
 * File: cdc.c
 *
 * System: Core module source code
 * 
 * Description:  Source code for functions declared in the header file
 *   
 * Revision History
 * Date         Programmer Name     Description
 * -----------  ------------------  ----------------
 * 30-June-2005  Arsenio Locsin     Original
 * 08-July-2005	 Arsenio Locsin		Modified according to instructor comments
 *									and tested new code
 * 10-July-2005  Arsenio Locsin		Modified realloc function
 *****************************************************************************/
//#include <cda.h>
#include <cdap.h>

void *CDA_malloc( size_t size )
{
    void *mem = malloc( size );

    if ( mem == NULL && size > 0 )
        abort();

    return mem;
}


void *CDA_calloc( size_t num, size_t size )
{
	void *mem = calloc( num, size);

	if ( mem == NULL && ((num * size) > 0))
		abort();
	
	return mem;
}

void *CDA_realloc( void *memblock, size_t size )
{
	void *mem = realloc( memblock, size);

    /*If the address of the memory block passed is NULL and the size requested 
	  is greater than zero, then realloc works like malloc. When malloc returns
	  NULL, then malloc fails. Therefore, realloc fails when the return value is
	  NULL and the size is greater than 0 because realloc is now working like
	  malloc and malloc fails when size passed to malloc is greater than zero
	  and the malloc function returns NULL.*/
	if(NULL == mem && 0 < size)
		abort();

	return mem;
}

void CDA_free( void *mem )
{
    if ( mem != NULL )
        free( mem );

}
