/*******************************************************************
cda.cpp - Contains the code for the CDA module.
*******************************************************************/

#include <cda.h>

/*******************************************************************
CDA_malloc
*******************************************************************/
void* CDA_malloc(size_t size)
{
    void* newMemory = malloc(size);

	if((NULL == newMemory) && (size > 0))
	{
		abort();
	}

    return newMemory;
}


/*******************************************************************
CDA_calloc
*******************************************************************/
void* CDA_calloc(size_t elementCount, size_t elementSize)
{
    void* newMemory = calloc(elementCount, elementSize);

	if((NULL == newMemory) && ((elementCount * elementSize) > 0))
	{
		abort();
	}

    return newMemory;
}


/*******************************************************************
CDA_realloc
*******************************************************************/
void* CDA_realloc(void* previousMemory, size_t newSize)
{
    void* newMemory = realloc(previousMemory, newSize);

	if((NULL == newMemory) && (newSize > 0))
	{
		abort();
	}

    return newMemory;
}


/*******************************************************************
CDA_free
*******************************************************************/
void CDA_free(void* memory)
{
    free(memory);
}
