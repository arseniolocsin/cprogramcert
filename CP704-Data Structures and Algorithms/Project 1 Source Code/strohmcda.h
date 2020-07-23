/*******************************************************************
cda.h - The private header file for the CDA module.
*******************************************************************/

#ifndef CDA_H
#define CDA_H

/*******************************************************************
Include statements.
*******************************************************************/

#include <stdlib.h>
#include <assert.h>
#include <string.h>

/*******************************************************************
Macro defintitions.
*******************************************************************/

#define CDA_FALSE   (0)
#define CDA_TRUE    (1)

#define CDA_ASSERT(exp) \
    ( assert(exp) )

#define CDA_CARD(arr) \
    ( sizeof(arr) / sizeof(arr[0]) )

#define CDA_NEW(type) \
    ( (type*)CDA_malloc(sizeof(type)) )

#define CDA_NEW_STR(string) \
    ( strcpy((char*)CDA_malloc(strlen(string) + 1), (string) ) )

#define CDA_NEW_STR_IF(string) \
    ( (NULL == (string)) ? NULL : (CDA_NEW_STR(string)) )

/*******************************************************************
Type definitions.
*******************************************************************/

typedef int             CDA_BOOL_t;
typedef signed char     CDA_INT8_t;
typedef unsigned char   CDA_UINT8_t;
typedef signed short    CDA_INT16_t;
typedef unsigned short  CDA_UINT16_t;
typedef signed int      CDA_INT32_t;
typedef unsigned int    CDA_UINT32_t;

/*******************************************************************
Function prototypes.
*******************************************************************/

void* CDA_malloc(size_t size);

void* CDA_calloc(size_t elementCount, size_t elementSize);

void* CDA_realloc(void* previousMemory, size_t newSize);

void CDA_free(void* ptr);

#endif  /* #ifndef CDA_H */
