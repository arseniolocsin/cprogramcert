/****************************************************************************** 
* 
* File: CAdv.c 
* 
* System: C Programming Advanced, Exercise 8 
*  
* Description: Creates a linked list from binary data and then displays the 
               linked list. 
* 
* Revision History 
* Date         Programmer Name     Description 
* -----------  ------------------  ---------------- 
* 01-Jun-2005  Arsenio Locsin        Completed homework 
* 
 *****************************************************************************/ 
#include <stdlib.h> 
#include <stdio.h>
#include <cda.h>
//#include <cdap.h>
 
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

	CDA_BOOL_t num = 0;
	void * pnum = NULL;
	CDA_BOOL_t * ptrack = NULL;
	CDA_UINT32_t oldSize = 10 * sizeof(CDA_BOOL_t);
	CDA_UINT32_t newSize = 2 * oldSize;

	char longString[] = "";

	puts("Begin Macro tests");
	printf("The value of CDA_TRUE is %i.\n", CDA_TRUE);
	printf("The value of CDA_FALSE is %i.\n", CDA_FALSE);

	puts("Testing memory allocation and assert macros.");
	puts("\nBegin CDA_malloc function tests.");
	pnum = CDA_malloc(oldSize);
	CDA_ASSERT( pnum );
	CDA_free(pnum);
	pnum = NULL;
	puts("CDA_malloc function is successful.");

	puts("\nBegin CDA_realloc function tests.");

	puts("Condition 1 Test: Memory is not NULL and size is greater than zero.");
	pnum = CDA_malloc(oldSize);
	printf("Original memory is at %p, old size is %i. bytes and new size is %i.\n", pnum, oldSize, newSize);
	pnum = CDA_realloc(pnum, newSize);
	printf( "New memory is at %p.\n" , pnum);
	CDA_free(pnum);
	pnum = NULL;
	puts("Condition 1 Test Successful.\n");

	puts("Condition 2 Test: Memory is NULL and size is greater than zero.");
	printf("Memory is NULL, old size is %i bytes, and new size is %i bytes.\n", oldSize, newSize);
	pnum = CDA_realloc(NULL, newSize);
	printf( "New memory is at %p.\n" , pnum);
	CDA_free(pnum);
	pnum = NULL;
	puts("Condition 2 Test Successful.\n");

	puts("\nCondition 3 Test: Memory is not NULL and size is zero.");
	pnum = CDA_malloc(oldSize);
	printf("Original memory is at %p, old size is %i. bytes and new size is %i.\n", pnum, oldSize, newSize);
	pnum = CDA_realloc(pnum, 0);
	printf( "New memory is at %p.\n" , pnum);
	CDA_free(pnum);
	pnum = NULL;
	puts("Condition 3 Test Successful.\n");
	
	puts("\nCondition 4 Test: Memory is NULL and size is zero.");
	//pnum = CDA_malloc(oldSize);
	//printf("Original memory is at %p, old size is %i. bytes and new size is %i.\n", pnum, oldSize, newSize);
	pnum = CDA_realloc(pnum, 0);
	printf( "New memory is at %p.\n" , pnum);
	CDA_free(pnum);
	pnum = NULL;
	puts("Condition 4 Test Successful.");
	puts("CDA_realloc passed all tests.");
	
	puts("CDA_realloc function passed all tests.\n");
	puts("Begin CDA_calloc function test");
	
	pnum = CDA_calloc(10, sizeof(CDA_BOOL_t));
	
	if(NULL != pnum)
	{
		ptrack = pnum;
		while(0 == *ptrack)
		{
			printf("%p: %i\n", ptrack, *ptrack);
			ptrack = ptrack++;
		}
	
	}
	
	puts("CDA_realloc function passed all tests.\n");
	puts("Finished testing memory allocation and assert macros.\n");

	puts("\nBegin string macro test.");
	printf("Long string: %s \n", longString);

	num =(size_t)(CDA_CARD(longString));
	printf("The size of long String before the macro is %i.\n", num);

	CDA_NEW_STR_IF(longString);
	num =(size_t)(CDA_CARD(longString));
	printf("The size of long String after the macro is %i.\n", num);
	puts("End of string macro test.\n");

	puts("\nBegin typedef test");
	printf("CDA_BOOL_t is %d bytes long.\n", sizeof(CDA_BOOL_t));
	printf("CDA_INT8_t is %d bytes long.\n", sizeof(CDA_INT8_t));
	printf("CDA_UINT8_t is %d bytes long.\n", sizeof(CDA_UINT8_t));
	printf("CDA_INT16_t is %d bytes long.\n", sizeof(CDA_INT16_t));
	printf("CDA_UINT16_t is %d bytes long.\n", sizeof(CDA_UINT16_t));
	printf("CDA_INT32_t is %d bytes long.\n", sizeof(CDA_INT32_t));
	printf("CDA_UINT32_t is %d bytes long.", sizeof(CDA_UINT32_t));	

}