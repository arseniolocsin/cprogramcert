/******************************************************************************
*
* File: cda.h
*
* System: Core module header
* 
* Description:  Core module declarations for macros, typedefs, prototypes, and
*				external variable declarations
*   
* Revision History
* Date         Programmer Name		Description
* -----------  ------------------	----------------
* 30-June-2005  Arsenio Locsin		Original
* 08-July-2005	Arsenio Locsin		Modified according to instructor comments
*									and tested new code
******************************************************************************/

#ifndef CDA_H    /* begin include sandwich          */
#define CDA_H    /* second line of include sandwich */


/*************************************************************************** 
 * header files 
 ***************************************************************************/ 
#include <assert.h>
#include <string.h>
#include <stdlib.h>

/*************************************************************************** 
 * macros 
 ***************************************************************************/ 
#define CDA_TRUE              (1)
#define CDA_FALSE             (0)
#define CDA_NEW( type )       ((type *)CDA_malloc( sizeof(type) ))
#define CDA_ASSERT( exp )     (assert( (exp) ))
#define CDA_NEW_STR( str )    (strcpy( (char *)CDA_malloc( strlen( (str) ) + 1 ), (str) ))
#define CDA_NEW_STR_IF( str ) ((str) == NULL ? NULL : CDA_NEW_STR( (str) ))
#define CDA_CARD( arr )       (sizeof((arr))/sizeof(*(arr)))

 
/*************************************************************************** 
 * typedefs 
 ***************************************************************************/ 
typedef int             CDA_BOOL_t;
typedef signed char     CDA_INT8_t;
typedef unsigned char   CDA_UINT8_t;
typedef	short			CDA_INT16_t;
typedef	unsigned short	CDA_UINT16_t;
typedef	long			CDA_INT32_t;
typedef	unsigned long	CDA_UINT32_t;


/*************************************************************************** 
 * prototypes 
 ***************************************************************************/ 
extern void *CDA_malloc( size_t size );
extern void *CDA_calloc( size_t num, size_t size );
extern void *CDA_realloc( void *memblock, size_t size );
extern void CDA_free( void *mem );

#endif            /* end include sandwich            */