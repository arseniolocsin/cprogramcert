/****************************************************************************** 
File: stk.c
System: Stack Source Code
Programmer Name: Arsenio Locsin
******************************************************************************/

#include <stkp.h>

STK_ID_t STK_create_stack( size_t size )
{
	STK__CONTROL_p_t stack = CDA_NEW( STK__CONTROL_t );
	stack->stack = CDA_calloc( size, sizeof(void *) );
	stack->sptr = stack->stack;
	stack->size = size;
	return (STK_ID_t)stack;
}

void STK_push_item( STK_ID_t stack, void *item )
{
	if(!STK_is_stack_full(stack))
	{
		*stack->sptr = item;
		stack->sptr++;
	}	
}

void *STK_pop_item( STK_ID_t stack )
{
	void * r_code;

	CDA_ASSERT(!STK_is_stack_empty(stack));
	r_code = *(stack->sptr-1);
	stack->sptr--;
	return r_code;
}

void *STK_peek_item( STK_ID_t stack )
{
	CDA_ASSERT( stack->sptr != stack->stack );
	return *(stack->sptr - 1);
}

CDA_BOOL_t STK_is_stack_empty( STK_ID_t stack )
{
	CDA_BOOL_t rcode = stack->sptr == stack->stack ? CDA_TRUE : CDA_FALSE;
	return rcode;	
}

CDA_BOOL_t STK_is_stack_full( STK_ID_t stack )
{
	
	CDA_BOOL_t rcode = stack->sptr == stack->stack + stack->size ? CDA_TRUE : CDA_FALSE;
	return rcode;
}

void STK_clear_stack( STK_ID_t stack )
{
	stack->sptr = stack->stack;
}

STK_ID_t STK_destroy_stack( STK_ID_t stack )
{
	CDA_free( stack->stack );
	CDA_free( stack );
	return STK_NULL_ID;
}