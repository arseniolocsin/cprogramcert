/****************************************************************************** 
File: test.c
System: Stack Source Code
Programmer Name: Arsenio Locsin
******************************************************************************/

#include <test.h>


/******************************************************************************
Start project 4 test code
******************************************************************************/

/******************************************************************************
End project 4 test code
******************************************************************************/



/******************************************************************************
Start project 3 test code
******************************************************************************/
void test_SRT_mergesort()
{

	CDA_INT32_t  intArray[] = {2267, -11, 9, 5, 8, 2345, 3, 2299, 4, 2298};
	int i = 0;
	
	puts("Start mergesort test.");

	puts("\nUnsorted array: ");

	for( i = 0; i < CDA_CARD(intArray); i++) printf(" %i", intArray[i] );	
	
	//qsort(intArray, CDA_CARD(intArray), sizeof(CDA_INT32_t), compareIntegers);
	SRT_mergesort(intArray, CDA_CARD(intArray), sizeof(CDA_INT32_t), compareIntegers);
	
	puts("\n\nSorted array: ");

	for(i = 0; i < CDA_CARD(intArray); i++) printf(" %i", intArray[i]);

	puts("\n\nEnd mergesort test.");
	
}

void test_STK()
{	
	/*	Create an array of strings.*/
	char * stringArray[6];
	size_t numElements = CDA_CARD(stringArray);
	size_t iCounter = 0;
	stack = STK_create_stack( MAX_STACK_SIZE );

	stringArray[0] = ( "Barney" );
	stringArray[1] = ( "Fred" );
	stringArray[2] = ( "Wilma" );
	stringArray[3] = ( "Betty" );
	stringArray[4] = ( "Pebbles" );
	stringArray[5] = ( "Bam Bam" );
	
	puts("Stack routine test.\n\nPush Test");

	while(iCounter < numElements)
	{
		printf("\nArray Item: %s\n",stringArray[iCounter]);
		STK_push_item(stack, stringArray[iCounter]);
		printf("Item on the stack: %s \n", (char *)STK_peek_item(stack));
		if(0 == strcmp(STK_peek_item(stack), stringArray[iCounter]))
			puts("Item was successfully put on the stack");
		else
			printf("**FAILURE: Could not put %s on the stack.\n", stringArray[iCounter]);

		iCounter++;
	}

	puts("\n\nPop Test");
	while(!STK_is_stack_empty(stack))
	{
		printf("Popping %s\n", STK_pop_item(stack) );
		printf( "The next item to pop is %s.\n", (char *)STK_peek_item(stack) );
	}

	STK_destroy_stack(stack);
}

void test_SRT_poly_mergesort_strings()
{
	char * stringArray[6];
	
	/*	Create an array of strings.*/
	

	char * qStringArray[] = {	"Barney",
								"Fred",
								"Wilma",
								"Betty",
								"Pebbles",
								"Bam Bam"
							};
	size_t numElements = CDA_CARD(stringArray);
	size_t iCounter = 0;
	
	stringArray[0] = ( "Barney" );
	stringArray[1] = ( "Fred" );
	stringArray[2] = ( "Wilma" );
	stringArray[3] = ( "Betty" );
	stringArray[4] = ( "Pebbles" );
	stringArray[5] = ( "Bam Bam" );
	
	/*	Create another array of string that will be used in the qsort test
		to bench test the compare functions. */
	
	/*	Display the name values in the qsort data structure */
	puts("\nUnsorted qsort array.");
	
	for( iCounter = 0; iCounter < numElements; iCounter++)
	{
		printf( "\t%s\n", qStringArray[iCounter] );
	}

	/*	Use qsort to sort the qsort data structure.*/
	qsort(qStringArray, CDA_CARD(qStringArray), sizeof(char *), compareStrings);

	/*	Display the sorted qsort data structure. */
	puts("\n***Sorted qsort array.***");
	
	for( iCounter = 0; iCounter < numElements; iCounter++)
	{
		printf( "%s ", qStringArray[iCounter] );
	}
	/*	If the sorted qsort data structure is correct, then the compare functions
		operate correctly. */

	/*	Display the original array.*/
	puts("\n\nUnsorted source array.");
	
	for( iCounter = 0; iCounter < numElements; iCounter++)
	{
		printf( "\t%s\n", stringArray[iCounter] );
	}
	/*	Use SRT_poly_mergesort to sort the data structure.*/
	stack = STK_create_stack( MAX_STACK_SIZE );		
	SRT_poly_mergesort( (void**)stringArray, numElements, compareStrings );

	/*	Display the sorted data structure.*/
	puts("\n***Sorted source array.***");
	
	for( iCounter = 0; iCounter < numElements; iCounter++)
	{
		printf( "%s ", stringArray[iCounter] );
	}
	/*	if the sorted data structure is correct, then the polymergesort function
		operates correctly. */

	STK_destroy_stack(stack);
}

int compareIntegers(const void * left, const void * right)
{
	int returnValue = 0;
	double leftValue = *(CDA_INT32_t *)left;
	double rightValue = *(CDA_INT32_t *)right;

	if(leftValue < rightValue) returnValue = -1;
	//if(leftValue == rightValue) returnValue = 0;
	if(leftValue > rightValue) returnValue = 1;

	return returnValue;
}

int compareStrings(const void * left, const void * right)
{
	int returnValue = 0;
	/*char * pLeftValue = CDA_NEW_STR_IF(left);
	char * pRightValue = CDA_NEW_STR_IF(right);*/
	returnValue = strcmp(*(char **)left, *(char **)right);
	return returnValue;
}

//void test_SRT_poly_mergesort_integers()
//{
//	/*	Create an array of integers.*/
//	int iarr[] = {5,1,7,9};
//	int *piarr[] = { &iarr[0], &iarr[1], &iarr[2], &iarr[3] };
//	int *qpiarr[] = { &iarr[0], &iarr[1], &iarr[2], &iarr[3] };
//	
//	size_t numElements = CDA_CARD(iarr);
//	size_t iCounter = 0;
//	
//	/*	Use qsort to sort the qsort integer.*/
//	puts("\nUnsorted qsort integer array.");
//	
//	for( iCounter = 0; iCounter < numElements; iCounter++)
//	{
//		printf( "\t%i\n", *qpiarr[iCounter] );
//	}
//
//	qsort(qpiarr, CDA_CARD(qpiarr), sizeof(int *), compareIntegers);
//
//	/*	Display the sorted qsort data structure. */
//	puts("\n***Sorted qsort integer array.***");
//	
//	for( iCounter = 0; iCounter < numElements; iCounter++)
//	{
//		printf( "%i ", *qpiarr[iCounter] );
//	}
//	/*	If the sorted qsort data structure is correct, then the compare functions
//		operate correctly. */
//
//
//	/*	Display the original array.*/
//
//	numElements = CDA_CARD(piarr);
//
//	puts("\nUnsorted integer array.");
//	
//	for( iCounter = 0; iCounter < numElements; iCounter++)
//	{
//		printf( "\t%i\n", *piarr[iCounter] );
//	}
//	/*	Use SRT_poly_mergesort to sort the data structure.*/
//	stack = STK_create_stack( MAX_STACK_SIZE );		
//	SRT_poly_mergesort( (void**)piarr, numElements, compareIntegers );
//
//	/*	Display the sorted data structure.*/
//	puts("\n***Sorted integer array.***");
//	
//	for( iCounter = 0; iCounter < numElements; iCounter++)
//	{
//		printf( "%i ", *piarr[iCounter] );
//	}
//
//	STK_destroy_stack(stack);
//}
//static int compareStructArray(const void * left, const void * right)
//{
//	int returnValue = 0;
//	ZIPS_data_t leftStruct = *(ZIPS_data_t*)left;
//	ZIPS_data_t rightStruct = *(ZIPS_data_t*)right;
//
//	if(leftStruct.zip_code < rightStruct.zip_code) returnValue = -1;
//	if(leftStruct.zip_code == rightStruct.zip_code) returnValue = 0;
//	if(leftStruct.zip_code > rightStruct.zip_code) returnValue = 1;
//
//	return returnValue;
//}
//
//static int comparePtrArray(const void * left, const void * right)
//{
//	int returnValue = 0;
//	ZIPS_data_p_t leftPtr= *(ZIPS_data_p_t*)left;
//	ZIPS_data_p_t rightPtr= *(ZIPS_data_p_t*)right;
//
//	if(leftPtr->zip_code < rightPtr->zip_code) returnValue = -1;
//	if(leftPtr->zip_code == rightPtr->zip_code) returnValue = 0;
//	if(leftPtr->zip_code > rightPtr->zip_code) returnValue = 1;
//
//	return returnValue;
//}


/******************************************************************************
End project 3 test code
******************************************************************************/