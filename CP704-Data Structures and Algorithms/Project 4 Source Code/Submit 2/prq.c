/****************************************************************************** 
File: prq.c
System: Priority Queue Module Source Code
Programmer Name: Arsenio Locsin
******************************************************************************/
#include <prqp.h>

PRQ_ID_t PRQ_create_queue(	const char *name, CDA_UINT32_t max_priority )
{
	PRQ_ID_t newQueue = PRQ_NULL_ID;
	CDA_UINT32_t iCounter = 0;

	/*	Create a queue object. */
	newQueue = CDA_malloc( sizeof(PRQ_ID_t)  );
	newQueue->name = CDA_NEW_STR_IF(name);
	newQueue->max_priority = max_priority;

	/*	Create the array of pointers. */
	newQueue->anchors = CDA_malloc( sizeof(ENQ_ANCHOR_p_t) * (max_priority + 1) );

	/*	Create an anchor object for element in the array. */
	for(iCounter = 0; iCounter <= max_priority; iCounter++)
		newQueue->anchors[iCounter]= ENQ_create_list(NULL);

	/*	Return the queue object ID. */
	return newQueue;
}

PRQ_ID_t PRQ_destroy_queue( PRQ_ID_t queue, PRQ_DESTROY_PROC_p_t destroy_proc )
{
	CDA_UINT32_t iCounter = 0;

	PRQ_empty_queue( queue, destroy_proc );

	for(iCounter = 0; iCounter < ( queue->max_priority  + 1); iCounter ++)
		ENQ_destroy_list( queue->anchors[iCounter] );
	
	CDA_free(queue->anchors);
	CDA_free( queue->name);
	CDA_free( queue );

	return PRQ_NULL_ID;
}

PRQ_ITEM_p_t PRQ_remove_item( PRQ_ID_t queue )
{
	int iCounter = (int)queue->max_priority;
	PRQ_ITEM_p_t item = NULL;
	CDA_BOOL_t	foundItem = CDA_FALSE;

	CDA_ASSERT( queue != PRQ_NULL_ID);

	/*	Find the highest priority queue with an item. */
	while( iCounter >= 0 && !foundItem )
	{
	
		if( !ENQ_is_list_empty( queue->anchors[iCounter] ))
		{
			/*	After finding the highest priority queue with an item, remove 
				the head of the queue. */
			item = PRQ_deq_pri_head( (PRQ_ID_t)queue->anchors[iCounter], iCounter );
			foundItem = CDA_FALSE;
		}

		iCounter--;
	}

	/*	Return the head of the queue*/
	return item;
}

CDA_BOOL_t PRQ_is_queue_empty( PRQ_ID_t queue )
{
	CDA_BOOL_t rcode = CDA_TRUE;
	CDA_UINT32_t maxPriority = queue->max_priority;
	CDA_UINT32_t iCounter = 0;
	
	for( iCounter = 0; 
		 iCounter <= maxPriority && rcode == CDA_TRUE; 
		 iCounter++
	   )
	{
		rcode = ENQ_is_list_empty( queue->anchors[iCounter] );
	}

	return rcode;
}

PRQ_ITEM_p_t PRQ_enq_pri_head( PRQ_ID_t queue, PRQ_ITEM_p_t item)
{
	CDA_UINT32_t priority = 0;
	ENQ_ANCHOR_p_t anchor = NULL;
	ENQ_ITEM_p_t rcode = NULL;
		
	/*	Find the queue whose priority matches the priority of the
		item. */
	priority = PRQ_GET_PRIORITY(item);
	anchor = queue->anchors[priority];
	
	/*	Add the item to head of the queue.*/
	rcode = ENQ_add_head( anchor, (ENQ_ITEM_p_t) item);

	/*	Return the item.*/
	return (PRQ_ITEM_p_t) rcode;
}

PRQ_ITEM_p_t PRQ_deq_pri_head( PRQ_ID_t queue, CDA_UINT32_t priority )
{
	PRQ_ITEM_p_t rcode = PRQ_NULL_ID;
	ENQ_ITEM_p_t head = NULL;
	ENQ_ITEM_p_t anchor = queue->anchors[priority];

	/*	If the queue is not empty, return the head of the queue.*/
	if( !PRQ_is_queue_empty( queue ) )
	{
		head = ENQ_deq_head( anchor );
		rcode = ( PRQ_ITEM_p_t ) head;
	}
	/*	Otherwise return NULL because the queue is already empty. */
	
	return rcode;
}

PRQ_ITEM_p_t PRQ_create_item( void *data, CDA_UINT32_t priority )
{
	PRQ_ITEM_p_t item = NULL;

	item = (PRQ_ITEM_p_t)ENQ_create_item( NULL,	sizeof(PRQ_ITEM_t) );

	item->data = data;
	item->priority = priority;
	return item;
}

PRQ_ITEM_p_t PRQ_add_item( PRQ_ID_t queue, PRQ_ITEM_p_t item )
{
	CDA_UINT32_t priorityNum = 0;
	ENQ_ITEM_p_t enqItem = NULL;
	
	CDA_ASSERT( queue != PRQ_NULL_ID );
	CDA_ASSERT( item != NULL );
	
	priorityNum = PRQ_GET_PRIORITY(item);

    /*	Throw an assertion if the priority on the item is greater than the 
		maximum priority in the queue object. */
	CDA_ASSERT( (item->priority) <= (queue->max_priority + 1) );

	/*	Get the list whose priority matches the priority in the item.*/
	enqItem = ENQ_add_tail( queue->anchors[priorityNum], (ENQ_ITEM_p_t)item );
	
	return (PRQ_ITEM_p_t)enqItem;
}

PRQ_ID_t PRQ_empty_queue( PRQ_ID_t queue, PRQ_DESTROY_PROC_p_t destroy_proc )
{
	ENQ_ANCHOR_p_t anchor = NULL;
	PRQ_ITEM_p_t item = NULL;
	CDA_UINT32_t iCounter = 0;
	CDA_UINT32_t maxPriority = queue->max_priority;

	for(iCounter = 0;
		iCounter <= maxPriority;
		iCounter++
		)
	{
		anchor = queue->anchors[iCounter];

		while ( !ENQ_is_list_empty( anchor ) )
		{
			item = (PRQ_ITEM_p_t)ENQ_GET_HEAD( anchor );

			if ( destroy_proc != NULL )
				destroy_proc( item->data );
			
			ENQ_destroy_item( (ENQ_ITEM_p_t)item );
		}
	}
	return queue;
}

PRQ_ITEM_p_t PRQ_destroy_item( PRQ_ITEM_p_t item )
{
	ENQ_destroy_item( (ENQ_ITEM_p_t)item );

	return NULL;
}

PRQ_ITEM_p_t PRQ_deq_item( PRQ_ITEM_p_t item )
{
	PRQ_ITEM_p_t rcode = PRQ_NULL_ID;
	
	CDA_ASSERT ( item != NULL );
	( ENQ_ITEM_p_t ) rcode = ENQ_deq_item( (ENQ_ITEM_p_t) item );

	/*	Return the dequeued item. */
	return rcode;
}