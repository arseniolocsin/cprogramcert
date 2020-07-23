/****************************************************************************** 
File: enq.c
System: Doubly Linked List Source Code
Programmer Name: Arsenio Locsin
******************************************************************************/
#include <stdio.h>
#include <cda.h>
#include <enq.h>
#include <enqp.h>

ENQ_ANCHOR_p_t ENQ_create_list( const char *name )
{
	ENQ_ANCHOR_p_t list = CDA_NEW( ENQ_ANCHOR_t );
	list->flink = list;
	list->blink = list;
	list->name = CDA_NEW_STR_IF( name );
	return list;
}

ENQ_ITEM_p_t ENQ_create_item( const char *name, size_t size )
{
	ENQ_ITEM_p_t item = (ENQ_ITEM_p_t)CDA_malloc( size );
	CDA_ASSERT( size >= sizeof(ENQ_ITEM_t) );
	item->flink = item;
	item->blink = item;
	item->name = CDA_NEW_STR_IF( name );
	return item;
}

CDA_BOOL_t ENQ_is_item_enqed( ENQ_ITEM_p_t item )
{
	CDA_BOOL_t rcode = (item->flink == item ? CDA_FALSE : CDA_TRUE);
	return rcode;
}

CDA_BOOL_t ENQ_is_list_empty( ENQ_ANCHOR_p_t list )
{
	CDA_BOOL_t rcode = CDA_FALSE;

	CDA_ASSERT(list->flink != NULL);
	CDA_ASSERT(list->blink != NULL);

	/*	The list is empty if list.flink and list.blink is equal to list.
		Return CDA_TRUE if the list is empty, CDA_FALSE otherwise*/
	if(list->flink==list && list->blink==list)
		rcode = CDA_TRUE;

	return rcode;
}

ENQ_ITEM_p_t ENQ_add_head( ENQ_ANCHOR_p_t list, ENQ_ITEM_p_t item)
{
	/* Check that the passed pointers are not NULL. Then check if the item is 
	   already enquequed.  */
	CDA_ASSERT( list != NULL );
	CDA_ASSERT( item != NULL );
	CDA_ASSERT(!ENQ_is_item_enqed(item));
		
	/*	If the passed pointers are good and the item is unenqued, check if list
		is empty by calling ENQ_is_list_empty. If the list is empty, set the 
		item as the first item after the anchor.*/
	if( ENQ_is_list_empty(list) )
	{
		list->flink = item;
		list->blink = item;
		item->blink = list;
		item->flink = list;
	}	
	else
	/*	If the list contains items, add the item to the head of the list.*/		
	{
		item->flink = list->flink;
		item->blink = list;
		list->flink->blink = item;
		list->flink = item;	
	}

	/*Return the pointer to the item*/
	return item;
}

ENQ_ITEM_p_t ENQ_add_tail( ENQ_ANCHOR_p_t list, ENQ_ITEM_p_t item)
{
	/* Check that the passed pointers are not NULL. Then check if the item is 
	   already enqueued.  */
	CDA_ASSERT( list != NULL );
	CDA_ASSERT( item != NULL );
	CDA_ASSERT(!ENQ_is_item_enqed(item));
		
	/*	If the passed pointers are good and the item is unenqued, check if list 
		is empty by calling ENQ_is_list_empty.
	*/

	if( ENQ_is_list_empty(list) )
	{
		list->flink = item;
		list->blink = item;
		item->blink = list;
		item->flink = list;
	}	
	else
	{
		item->flink = list;
		item->blink = list->blink;
		list->blink->flink = item;
		list->blink = item;	
	}
	
	/*Return the pointer to the item*/
	return item;
}

ENQ_ITEM_p_t ENQ_add_after( ENQ_ITEM_p_t item,ENQ_ITEM_p_t after)
{
	CDA_ASSERT( NULL != item );
	CDA_ASSERT( NULL != after );
	CDA_ASSERT(!ENQ_is_item_enqed( item ));

	item->flink = after->flink;
	item->blink = after;	
	after->flink->blink = item;
	after->flink = item;
	
	return item;
}

ENQ_ITEM_p_t ENQ_add_before( ENQ_ITEM_p_t item, ENQ_ITEM_p_t before)
{
	CDA_ASSERT( NULL != item );
	CDA_ASSERT( NULL != before );
	CDA_ASSERT(!ENQ_is_item_enqed( item ));

	item->flink = before;
	item->blink = before->blink;
	before->blink->flink = item;
	before->blink = item;	

	return item;	
}
	
ENQ_ITEM_p_t ENQ_deq_item( ENQ_ITEM_p_t item )
{
	item->blink->flink = item->flink;
	item->flink->blink = item->blink;
	item->flink = item;
	item->blink = item;
	return item;
}

ENQ_ITEM_p_t ENQ_deq_head( ENQ_ANCHOR_p_t list )
{
	ENQ_ITEM_p_t rVal = NULL;

	if(!ENQ_is_list_empty(list))
	{
		rVal = list->flink;
		list->flink->flink->blink = list;
		list->flink = list->flink->flink;
		rVal->flink = rVal;
		rVal->blink = rVal;

		if(!ENQ_is_item_enqed(rVal))
			printf("\nThe head item called \"%s\" was removed from the list.\n", ENQ_GET_ITEM_NAME(rVal));
		else
		{
			puts("\nAn error occurred removing the head from the list.\n");
			rVal = NULL;
		}
	}
	else
		rVal = list;
	
	return rVal;
}

ENQ_ITEM_p_t ENQ_deq_tail( ENQ_ANCHOR_p_t list )
{

	ENQ_ITEM_p_t rVal = NULL;

	if(!ENQ_is_list_empty(list))
	{
		rVal = list->blink;
		list->blink->blink->flink = list;
		list->blink = list->blink->blink;
		rVal->flink = rVal;
		rVal->blink = rVal;

		if(!ENQ_is_item_enqed(rVal))
			printf("\nThe tail item called \"%s\" was removed from the list.\n", ENQ_GET_ITEM_NAME(rVal));
		else
		{
			puts("\nAn error occurred removing the head from the list.\n");
			rVal = NULL;
		}
	}
	else
		rVal = list;

	return rVal;
}

ENQ_ITEM_p_t ENQ_destroy_item( ENQ_ITEM_p_t item )
{
	ENQ_deq_item( item );
	CDA_free( item->name );
	CDA_free( item );
	return NULL;
}

ENQ_ANCHOR_p_t ENQ_empty_list( ENQ_ANCHOR_p_t list )
{
	while ( !ENQ_is_list_empty( list ) )
		ENQ_destroy_item( list->flink );
	return list;
}

ENQ_ANCHOR_p_t ENQ_destroy_list( ENQ_ANCHOR_p_t list )
{
	ENQ_empty_list( list );
	CDA_free( list->name );
	CDA_free( list );
	return NULL;
}