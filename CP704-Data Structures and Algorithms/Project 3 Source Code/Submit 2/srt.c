/****************************************************************************** 
File: srt.c
System: Sort Module Source Code
Programmer Name: Arsenio Locsin
******************************************************************************/

#include <cda.h>
#include <stk.h>
#include <srt.h>

#define OFFSETVALUE(ptr, index, element_size) ((char *)ptr + (index * element_size))
#define MAX_STACK_SIZE (1000)

static void copyElement(char * source, char * dest, size_t element_size)
{
	memcpy(dest, source, element_size);
}

void SRT_mergesort(	void *array, size_t num_elements,
					size_t element_size, SRT_CMP_PROC_p_t cmp_proc )			  
{
	if(num_elements > 1)
	{
		size_t	lowIndex		= 0;
		size_t	highIndex		= 0;
		size_t	tempIndex		= 0;
		size_t	lowNumElements	= 0;
		size_t	highNumElements = 0;
		char *	lowArray;
		char *	highArray;
		char *	tempArray;
		int		compareResult	= 0;

		/*Divide the array into two array. */
		
		// Set the pointer to the lower array
		lowArray = array;
		
		// Get the number of elements in the low array
		lowNumElements = num_elements/2;

		//Get the number of element in the high array
		highNumElements = num_elements - lowNumElements;
		
		// set the pointer to the high array
		highArray = lowArray + (lowNumElements * element_size);

		// Sort both arrays
		SRT_mergesort(lowArray, lowNumElements, element_size, cmp_proc);
		SRT_mergesort(highArray, highNumElements, element_size, cmp_proc);

		/*	Merge the two arrays. Compare the element of the low array to an 
			element in the high array. If the value of the low array element
			is greater than the value of the high array element, add the
			low array element value to the temporary array.*/

		tempArray = CDA_malloc(num_elements * element_size);

		for(lowIndex = 0, highIndex = 0, tempIndex = 0;
			lowIndex < lowNumElements && highIndex < highNumElements;
			tempIndex++)
		{
			compareResult = cmp_proc( OFFSETVALUE(lowArray, lowIndex, element_size), 
									  OFFSETVALUE(highArray, highIndex, element_size)
									);

			if(compareResult < 0)
			{
				copyElement( OFFSETVALUE(lowArray, lowIndex, element_size), 
							 OFFSETVALUE(tempArray, tempIndex, element_size),
							 element_size
						    );				
				lowIndex++;
			}
			else
			{
				copyElement( OFFSETVALUE(highArray, highIndex, element_size),
								  OFFSETVALUE(tempArray, tempIndex, element_size),
								  element_size
								);
				highIndex++;
			}
		}

		while(lowIndex < lowNumElements)
		{
			copyElement( OFFSETVALUE(lowArray, lowIndex, element_size), 
						 OFFSETVALUE(tempArray, tempIndex, element_size), 
						 element_size
					    );
			tempIndex++;
			lowIndex++;
		}

		while(highIndex < highNumElements)
		{
			copyElement( OFFSETVALUE(highArray, highIndex, element_size), 
						 OFFSETVALUE(tempArray, tempIndex, element_size), 
						 element_size
					   );
			tempIndex++;
			highIndex++;		
		}

		for(tempIndex = 0; tempIndex < num_elements; tempIndex++)
		{
			/*memcpy(	OFFSETVALUE(array, tempIndex, element_size), 
					OFFSETVALUE(tempArray, tempIndex, element_size), 
					element_size);*/

			copyElement( OFFSETVALUE(tempArray, tempIndex, element_size), 
						 OFFSETVALUE(array, tempIndex, element_size), 
						 element_size
					   );
							
		}
		CDA_free(tempArray);
	}
}

void SRT_poly_mergesort	(	void				**array,
							size_t				num_elements,
							SRT_CMP_PROC_p_t	cmp_proc
						)
{
	/*	This function sorts an array of pointers using a stack as the temporary
		array. */
	

	/*	Perform the sort only if there is more than one element to sort. */
	if(num_elements > 1)
	{
		void**	lowArray		= NULL;
		void**	highArray		= NULL;
		size_t	lowNumElements	= 0;
		size_t	highNumElements = 0;
		size_t	lowIndex		= 0;
		size_t	highIndex		= 0;
		int		returnCompare	= 0;
		void *	temp;

		/*	If a stack doesn't exist, create a stack. */
		STK_ID_t stack = STK_create_stack(MAX_STACK_SIZE);

		/*	Divide the source array into two arrays, a low array and a high 
			array.*/
			
		//	Set the pointer to the lower array
		lowArray = array;

		//	Get the number of elements in the low array
		lowNumElements = num_elements / 2;

		//	Get the number of element in the high array
		highNumElements = num_elements - lowNumElements;

		//	Set the pointer to the high array
		highArray = array + lowNumElements;

		//	Sort both arrays
		SRT_poly_mergesort( (void**)lowArray, lowNumElements, cmp_proc);
		SRT_poly_mergesort( (void**)highArray, highNumElements, cmp_proc);

		/*	Merge the two arrays. Compare the element of the low array to an 
			element in the high array.  */
		lowIndex = highIndex = 0;
		while( lowIndex < lowNumElements && highIndex < highNumElements )
		{
			returnCompare = cmp_proc( &lowArray[lowIndex], &highArray[highIndex] );

			/*	If the return value is less than 0, then the low array value is less 
				than the high array value. Push the address of the low array value
				onto the stack and increment the low array counter. Otherwise, 
				push the address of the high array value onto the stack and 
				increment the high array counter. */
			if( returnCompare < 0 )
			{
				STK_push_item( stack, (void *)(lowArray[lowIndex]) );
				lowIndex++;
			}
			else
			{
				STK_push_item( stack, (void *)(highArray[highIndex]) );
				highIndex++;
			}
		}

		/*	Push the addresses of any remaining elements in the low array onto 
			the stack. If all the addresses of the elements in the low array 
			are on the stack, push the addresses of the remaining elements in
			the high array onto the stack.*/
		while( lowIndex < lowNumElements )
		{
			STK_push_item( stack, (void *)(lowArray[lowIndex]) );
			lowIndex++;
		}

		while( highIndex < highNumElements )
		{
			STK_push_item( stack, (void *)(highArray[highIndex]) );
			highIndex++;
		}


		/*	Starting the last item on the array and working towards the first
			item in the array, push each item off the stack and into the array.
			The array contains sorted values. */
		lowIndex = num_elements;
		while( lowIndex > 0)
		{
			lowIndex--;
			temp = STK_pop_item( stack );
			lowArray[lowIndex] = (void *)temp;
			temp = NULL;
		}
	}
}