/****************************************************************************** 
File: test.c
System: Stack Source Code
Programmer Name: Arsenio Locsin
******************************************************************************/

#include <test.h>
#include <stk.h>
#include <srt.h>
#include <prqp.h>

/******************************************************************************
Start project 4 test code
******************************************************************************/
static void test_EmptyQueue( PRQ_ID_t queue)
{
	puts("\nIs the queue empty?");

	if(PRQ_is_queue_empty(queue))
		puts("Empty priority queue.");
	else
		puts("Priority queue still contains items.");
}

void test_PRQ_full()
{
	/*	Create a priority queue of four items and add an item called Fred to 
		the head of the third priority queue. */

	/*	Data for priority queue 0. */
	char * pHead0 = "This is the head for priority queue 0.";
	char * pItem0 = "This is the item for priority queue 0.";
	char * pTail0 = "This is the tail for priority queue 0.";
	PRQ_ITEM_p_t pheadItem0 = NULL;
	PRQ_ITEM_p_t pheadPRQ0 = NULL;
	PRQ_ITEM_p_t pitemItem0 = NULL;
	PRQ_ITEM_p_t pitemPRQ0 = NULL;
	PRQ_ITEM_p_t ptailItem0 = NULL;
	PRQ_ITEM_p_t ptailPRQ0 = NULL;

	/*	Data for priority queue 2. */
	char * pHead2 = "Priority queue 2: head";
	char * pItem2 = "Priority queue 2: item";
	char * pTail2 = "Priority queue 2: tail";
	PRQ_ITEM_p_t pheadItem2 = NULL;
	PRQ_ITEM_p_t pheadPRQ2 = NULL;
	PRQ_ITEM_p_t pitemItem2 = NULL;
	PRQ_ITEM_p_t pitemPRQ2 = NULL;
	PRQ_ITEM_p_t ptailItem2 = NULL;
	PRQ_ITEM_p_t ptailPRQ2 = NULL;
	PRQ_ITEM_p_t premoveHead2 = NULL;
	PRQ_ITEM_p_t premoveTail2 = NULL;
	
	/*	Data for priority queue 4. */
	char * pHead4 = "Head: priority queue 4";
	char * pItem4 = "Item: priority queue 4";
	char * pTail4 = "Tail: priority queue 4";
	PRQ_ITEM_p_t pheadItem4 = NULL;
	PRQ_ITEM_p_t pheadPRQ4 = NULL;
	PRQ_ITEM_p_t pitemItem4 = NULL;
	PRQ_ITEM_p_t pitemPRQ4 = NULL;
	PRQ_ITEM_p_t ptailItem4 = NULL;
	PRQ_ITEM_p_t ptailPRQ4 = NULL;
	
	/*	Other required variables */
	PRQ_ITEM_p_t destroyedItem = NULL;
	PRQ_ITEM_p_t item = NULL;
	PRQ_ITEM_p_t pItem = NULL;
	void * pdqData = NULL;

	PRQ_ID_t queue = PRQ_NULL_ID;

	puts( "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" );
	puts( "*******Full Priority Queue Test*******" );
	puts( "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" );
	
	/*	Create the priority queue */
	queue = PRQ_create_queue("Queue", 4);
	
	/* Test the PRQ_remove_item function on an empty queue */
	puts( "Test the PRQ_remove_item function on an empty queue." );
	puts( "Removing a NULL item" );
	item = PRQ_remove_item(queue);
	if(NULL == item)
		puts("Success removing a NULL empty from an empty queue.");
	else
		printf("FAILURE: item = %p.\n", item);

	test_EmptyQueue(queue);

	/*	Add items to priority queue 2. */	
	/*	Add an item to priority queue 2. */
	puts(" \nCreate and add an item to priority queue 2.");
	pitemItem2 = PRQ_create_item( pItem2, 2);
	pitemPRQ2 = PRQ_add_item( queue, pitemItem2 );
	if( NULL != pitemItem2 && NULL != pitemPRQ2 )
	{
		puts("Success creating and adding an item to priority queue 2." );
		printf("Item data \"%s\" was added to priority queue %i.\n", PRQ_GET_DATA( pitemPRQ2 ), pitemPRQ2->priority);
	}
	else
		puts("FAILURE: creating and adding an item to priority queue 2." );

	test_EmptyQueue(queue);

	/*	Add a head item to priority queue 2. */
	puts(" \nCreate and add an item to the head of the priority queue 2.");
	pheadItem2 = PRQ_create_item( pHead2, 2);
	pheadPRQ2 = PRQ_enq_pri_head( queue, pheadItem2 );
	if( NULL != pheadItem2 && NULL != pheadPRQ2 )
	{
		puts("Success creating and adding a head item to priority queue 2." );
		printf("Head data \"%s\" was added to priority queue %i.\n", PRQ_GET_DATA( pheadPRQ2 ), pheadPRQ2->priority);
	}
	else
		puts("FAILURE: creating and adding a head item to priority queue 2." );
	
	/*	Add a tail item to priority queue 2. */
	puts(" \nCreate and add an item to the tail of the priority queue 2.");
	ptailItem2 = PRQ_create_item( pTail2, 2);
	ptailPRQ2 = PRQ_add_item( queue, ptailItem2 );
	if( NULL != ptailItem2 && NULL != ptailPRQ2 )
	{
		puts("Success creating and adding a tail item to priority queue 2." );
		printf("Tail data \"%s\" was added to priority queue %i.\n", PRQ_GET_DATA( ptailPRQ2 ), ptailPRQ2->priority);
	}
	else
		puts("FAILURE: creating and adding a tail item to priority queue 2." );

	/*	Add items to priority queue 0 */
	/*	Add an item to priority queue 0. */
	puts( "\n\n************************************************************" );
	puts( "Adding items to priority queue 0" );
	puts( "************************************************************" );
	puts("Create and add an item to priority queue 0.");
	pitemItem0 = PRQ_create_item( pItem0, 0);
	pitemPRQ0 = PRQ_add_item( queue, pitemItem0 );
	if( NULL != pitemItem0 && NULL != pitemPRQ0 )
	{
		puts("Success creating and adding an item to priority queue 0." );
		printf("Item data \"%s\" was added to priority queue %i.\n", PRQ_GET_DATA( pitemPRQ0 ), pitemPRQ0->priority);
	}
	else
		puts("FAILURE: creating and adding an item to priority queue 0." );

	test_EmptyQueue(queue);

	/*	Add a head item to priority queue 0. */
	puts(" \nCreate and add an item to the head of the priority queue 0.");
	pheadItem0 = PRQ_create_item( pHead0, 0);
	pheadPRQ0 = PRQ_enq_pri_head( queue, pheadItem0 );
	if( NULL != pheadItem0 && NULL != pheadPRQ0 )
	{
		puts("Success creating and adding a head item to priority queue 0." );
		printf("Head data \"%s\" was added to priority queue %i.\n", PRQ_GET_DATA( pheadPRQ0 ), pheadPRQ0->priority);
	}
	else
		puts("FAILURE: creating and adding a head item to priority queue 0." );
	
	/*	Add a tail item to priority queue 0. */
	puts(" \nCreate and add an item to the tail of the priority queue 0.");
	ptailItem0 = PRQ_create_item( pTail0, 0);
	ptailPRQ0 = PRQ_add_item( queue, ptailItem0 );
	if( NULL != ptailItem0 && NULL != ptailPRQ0 )
	{
		puts("Success creating and adding a tail item to priority queue 0." );
		printf("Tail data \"%s\" was added to priority queue %i.\n", PRQ_GET_DATA( ptailPRQ0 ), ptailPRQ0->priority);
	}
	else
		puts("FAILURE: creating and adding a tail item to priority queue 0." );


	/*	Add items to priority queue 4 */
	/*	Add an item to priority queue 4. */
	puts( "\n\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" );
	puts( "Adding items to priority queue 4" );
	puts( "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" );
	puts("Create and add an item to priority queue 4.");
	pitemItem4 = PRQ_create_item( pItem4, 4);
	pitemPRQ4 = PRQ_add_item( queue, pitemItem4 );
	if( NULL != pitemItem4 && NULL != pitemPRQ4 )
	{
		puts("Success creating and adding an item to priority queue 4." );
		printf("Item data \"%s\" was added to priority queue %i.\n", PRQ_GET_DATA( pitemPRQ4 ), pitemPRQ4->priority);
	}
	else
		puts("FAILURE: creating and adding an item to priority queue 4." );

	test_EmptyQueue(queue);

	/*	Add a head item to priority queue 0. */
	puts(" \nCreate and add an item to the head of the priority queue 4.");
	pheadItem4 = PRQ_create_item( pHead4, 4);
	pheadPRQ4 = PRQ_enq_pri_head( queue, pheadItem4 );
	if( NULL != pheadItem4 && NULL != pheadPRQ4 )
	{
		puts("Success creating and adding a head item to priority queue 4." );
		printf("Head data \"%s\" was added to priority queue %i.\n", PRQ_GET_DATA( pheadPRQ4 ), pheadPRQ4->priority);
	}
	else
		puts("FAILURE: creating and adding a head item to priority queue 4." );
	
	/*	Add a tail item to priority queue 0. */
	puts(" \nCreate and add an item to the tail of the priority queue 4.");
	ptailItem4 = PRQ_create_item( pTail4, 4);
	ptailPRQ4 = PRQ_add_item( queue, ptailItem4 );
	if( NULL != ptailItem4 && NULL != ptailPRQ4 )
	{
		puts("Success creating and adding a tail item to priority queue 4." );
		printf("Tail data \"%s\" was added to priority queue %i.\n", PRQ_GET_DATA( ptailPRQ4 ), ptailPRQ4->priority);
	}
	else
		puts("FAILURE: creating and adding a tail item to priority queue 4." );

	/*	Dequeue the tail item in priority queue 2 */
	item = PRQ_deq_item(ptailItem2);
	printf("The data for the dequeued item from priority queue %i is %s.\n", PRQ_GET_PRIORITY(item), PRQ_GET_DATA(item) );
	 
	/* Add the dequeued item to priority queue 0 */
	item->priority = 0;
	pItem = PRQ_add_item(queue, item);
	
	/*  Destroy the item in priority 4 */
	puts( "\nDequeue and destroy the item in priority 4" );
	destroyedItem = PRQ_destroy_item( pitemItem4 );
	
	/*  Destroy the item in priority 0 */
	puts( "\nDequeue and destroy the item in priority 0" );
	destroyedItem = PRQ_destroy_item( pitemItem0 );

	/*	Dequeue each item in the priority queue and display each dequeued item */
	/*while( !PRQ_is_queue_empty( queue ) )
	{
		item = PRQ_remove_item( queue );
		printf( "Item removed: %s\n", PRQ_GET_DATA( item) );
	
	}*/
	/*	Empty the queue*/
	test_EmptyQueue(queue);

	puts("\nEmpty the queue.");
	queue = PRQ_empty_queue(queue, test_destroyItem);
	
	test_EmptyQueue(queue);

}

void test_PRQ_destroyQueueFull()
{
	/*	Create and destroy the queue*/
		/*	Data for priority queue 0. */
	char * pHead0 = "This is the head for priority queue 0.";
	char * pItem0 = "This is the item for priority queue 0.";
	char * pTail0 = "This is the tail for priority queue 0.";
	PRQ_ITEM_p_t pheadItem0 = NULL;
	PRQ_ITEM_p_t pheadPRQ0 = NULL;
	PRQ_ITEM_p_t pitemItem0 = NULL;
	PRQ_ITEM_p_t pitemPRQ0 = NULL;
	PRQ_ITEM_p_t ptailItem0 = NULL;
	PRQ_ITEM_p_t ptailPRQ0 = NULL;

	/*	Data for priority queue 2. */
	char * pHead2 = "Priority queue 2: head";
	char * pItem2 = "Priority queue 2: item";
	char * pTail2 = "Priority queue 2: tail";
	PRQ_ITEM_p_t pheadItem2 = NULL;
	PRQ_ITEM_p_t pheadPRQ2 = NULL;
	PRQ_ITEM_p_t pitemItem2 = NULL;
	PRQ_ITEM_p_t pitemPRQ2 = NULL;
	PRQ_ITEM_p_t ptailItem2 = NULL;
	PRQ_ITEM_p_t ptailPRQ2 = NULL;
	
	/*	Data for priority queue 4. */
	char * pHead4 = "Head: priority queue 4";
	char * pItem4 = "Item: priority queue 4";
	char * pTail4 = "Tail: priority queue 4";
	PRQ_ITEM_p_t pheadItem4 = NULL;
	PRQ_ITEM_p_t pheadPRQ4 = NULL;
	PRQ_ITEM_p_t pitemItem4 = NULL;
	PRQ_ITEM_p_t pitemPRQ4 = NULL;
	PRQ_ITEM_p_t ptailItem4 = NULL;
	PRQ_ITEM_p_t ptailPRQ4 = NULL;
	
	/*	Other required variables */
	PRQ_ITEM_p_t item = NULL;
	PRQ_ID_t queue = PRQ_NULL_ID;
	PRQ_ID_t destroyedQueue = PRQ_NULL_ID;

	puts( "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" );
	puts( "*******Destroy a Full Priority Queue Test*******" );
	puts( "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" );
	
	/*	Create the priority queue */
	queue = PRQ_create_queue("Queue", 4);
	
	/* Test the PRQ_remove_item function on an empty queue */
	puts( "Test the PRQ_remove_item function on an empty queue." );
	puts( "Removing a NULL item" );
	item = PRQ_remove_item(queue);
	if(NULL == item)
		puts("Success removing a NULL empty from an empty queue.");
	else
		printf("FAILURE: item = %p.\n", item);

	test_EmptyQueue(queue);

	/*	Add items to priority queue 2. */	
	/*	Add an item to priority queue 2. */
	puts(" \nCreate and add an item to priority queue 2.");
	pitemItem2 = PRQ_create_item( pItem2, 2);
	pitemPRQ2 = PRQ_add_item( queue, pitemItem2 );
	if( NULL != pitemItem2 && NULL != pitemPRQ2 )
	{
		puts("Success creating and adding an item to priority queue 2." );
		printf("Item data \"%s\" was added to priority queue %i.\n", PRQ_GET_DATA( pitemPRQ2 ), pitemPRQ2->priority);
	}
	else
		puts("FAILURE: creating and adding an item to priority queue 2." );

	test_EmptyQueue(queue);

	/*	Add a head item to priority queue 2. */
	puts(" \nCreate and add an item to the head of the priority queue 2.");
	pheadItem2 = PRQ_create_item( pHead2, 2);
	pheadPRQ2 = PRQ_enq_pri_head( queue, pheadItem2 );
	if( NULL != pheadItem2 && NULL != pheadPRQ2 )
	{
		puts("Success creating and adding a head item to priority queue 2." );
		printf("Head data \"%s\" was added to priority queue %i.\n", PRQ_GET_DATA( pheadPRQ2 ), pheadPRQ2->priority);
	}
	else
		puts("FAILURE: creating and adding a head item to priority queue 2." );
	
	/*	Add a tail item to priority queue 2. */
	puts(" \nCreate and add an item to the tail of the priority queue 2.");
	ptailItem2 = PRQ_create_item( pTail2, 2);
	ptailPRQ2 = PRQ_add_item( queue, ptailItem2 );
	if( NULL != ptailItem2 && NULL != ptailPRQ2 )
	{
		puts("Success creating and adding a tail item to priority queue 2." );
		printf("Tail data \"%s\" was added to priority queue %i.\n", PRQ_GET_DATA( ptailPRQ2 ), ptailPRQ2->priority);
	}
	else
		puts("FAILURE: creating and adding a tail item to priority queue 2." );

	/*	Add items to priority queue 0 */
	/*	Add an item to priority queue 0. */
	puts( "\n\n************************************************************" );
	puts( "Adding items to priority queue 0" );
	puts( "************************************************************" );
	puts("Create and add an item to priority queue 0.");
	pitemItem0 = PRQ_create_item( pItem0, 0);
	pitemPRQ0 = PRQ_add_item( queue, pitemItem0 );
	if( NULL != pitemItem0 && NULL != pitemPRQ0 )
	{
		puts("Success creating and adding an item to priority queue 0." );
		printf("Item data \"%s\" was added to priority queue %i.\n", PRQ_GET_DATA( pitemPRQ0 ), pitemPRQ0->priority);
	}
	else
		puts("FAILURE: creating and adding an item to priority queue 0." );

	test_EmptyQueue(queue);

	/*	Add a head item to priority queue 0. */
	puts(" \nCreate and add an item to the head of the priority queue 0.");
	pheadItem0 = PRQ_create_item( pHead0, 0);
	pheadPRQ0 = PRQ_enq_pri_head( queue, pheadItem0 );
	if( NULL != pheadItem0 && NULL != pheadPRQ0 )
	{
		puts("Success creating and adding a head item to priority queue 0." );
		printf("Head data \"%s\" was added to priority queue %i.\n", PRQ_GET_DATA( pheadPRQ0 ), pheadPRQ0->priority);
	}
	else
		puts("FAILURE: creating and adding a head item to priority queue 0." );
	
	/*	Add a tail item to priority queue 0. */
	puts(" \nCreate and add an item to the tail of the priority queue 0.");
	ptailItem0 = PRQ_create_item( pTail0, 0);
	ptailPRQ0 = PRQ_add_item( queue, ptailItem0 );
	if( NULL != ptailItem0 && NULL != ptailPRQ0 )
	{
		puts("Success creating and adding a tail item to priority queue 0." );
		printf("Tail data \"%s\" was added to priority queue %i.\n", PRQ_GET_DATA( ptailPRQ0 ), ptailPRQ0->priority);
	}
	else
		puts("FAILURE: creating and adding a tail item to priority queue 0." );


	/*	Add items to priority queue 4 */
	/*	Add an item to priority queue 4. */
	puts( "\n\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" );
	puts( "Adding items to priority queue 4" );
	puts( "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" );
	puts("Create and add an item to priority queue 4.");
	pitemItem4 = PRQ_create_item( pItem4, 4);
	pitemPRQ4 = PRQ_add_item( queue, pitemItem4 );
	if( NULL != pitemItem4 && NULL != pitemPRQ4 )
	{
		puts("Success creating and adding an item to priority queue 4." );
		printf("Item data \"%s\" was added to priority queue %i.\n", PRQ_GET_DATA( pitemPRQ4 ), pitemPRQ4->priority);
	}
	else
		puts("FAILURE: creating and adding an item to priority queue 4." );

	test_EmptyQueue(queue);

	/*	Add a head item to priority queue 0. */
	puts(" \nCreate and add an item to the head of the priority queue 4.");
	pheadItem4 = PRQ_create_item( pHead4, 4);
	pheadPRQ4 = PRQ_enq_pri_head( queue, pheadItem4 );
	if( NULL != pheadItem4 && NULL != pheadPRQ4 )
	{
		puts("Success creating and adding a head item to priority queue 4." );
		printf("Head data \"%s\" was added to priority queue %i.\n", PRQ_GET_DATA( pheadPRQ4 ), pheadPRQ4->priority);
	}
	else
		puts("FAILURE: creating and adding a head item to priority queue 4." );
	
	/*	Add a tail item to priority queue 0. */
	puts(" \nCreate and add an item to the tail of the priority queue 4.");
	ptailItem4 = PRQ_create_item( pTail4, 4);
	ptailPRQ4 = PRQ_add_item( queue, ptailItem4 );
	if( NULL != ptailItem4 && NULL != ptailPRQ4 )
	{
		puts("Success creating and adding a tail item to priority queue 4." );
		printf("Tail data \"%s\" was added to priority queue %i.\n", PRQ_GET_DATA( ptailPRQ4 ), ptailPRQ4->priority);
	}
	else
		puts("FAILURE: creating and adding a tail item to priority queue 4." );

	/*	Destroy the queue*/
	test_EmptyQueue(queue);

	puts("\nDestroy the queue.");
	destroyedQueue = PRQ_destroy_queue(queue, NULL);
}

void test_PRQ_destroyQueueEmpty()
{
	PRQ_ID_t queue = PRQ_NULL_ID;
	PRQ_ID_t destroyedQueue = PRQ_NULL_ID;

	puts( "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" );
	puts( "*******Destroy an empty Priority Queue Test******" );
	puts( "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" );
	
	/*	Create the priority queue */
	queue = PRQ_create_queue("Queue", 4 );

	test_EmptyQueue(queue);
	destroyedQueue = PRQ_destroy_queue( queue, NULL );
}


void test_PRQ_dq()
{
	/*	Create a priority queue of four items and add an item called Fred to 
		the head of the third priority queue. */

	char * pHead = "This is the head.";
	char * pTail = "This is the tail.";
	void * pdqData = NULL;

	PRQ_ID_t queue = PRQ_create_queue("Queue", 4);
	PRQ_ITEM_p_t pBarney = NULL;
	PRQ_ITEM_p_t tail = NULL;
	PRQ_ITEM_p_t dTail = NULL;

	puts( "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" );
	puts( "*******Dequeue Priority Queue Test*******" );
	puts( "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" );
	
	test_EmptyQueue(queue);
	
	puts(" \n\nCreate and add an item.");
	pBarney = PRQ_create_item( pTail, 2);
	tail = PRQ_add_item( queue, pBarney );

	test_EmptyQueue(queue);

	dTail = PRQ_deq_item( tail );
	printf("Item removed from list: %s\n", PRQ_GET_DATA(dTail));

	test_EmptyQueue(queue);
}

void test_PRQ_BigPriority()
{
	/*	Create a priority queue of four items and add an item called Fred to 
		the head of the third priority queue. */

	char * pHead = "This is the head.";
	char * pTail = "This is the tail.";
	void * pdqData = NULL;	
	PRQ_ID_t queue = PRQ_create_queue("Queue", 2 );
	PRQ_ITEM_p_t pBarney = NULL;
	PRQ_ITEM_p_t tail = NULL;
	PRQ_ITEM_p_t dTail = NULL;

	puts( "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" );
	puts( "*******Add an item with a higher priority to Priority Queue Test******" );
	puts( "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" );

	test_EmptyQueue(queue);
	
	puts(" \n\nCreate and add an item.");
	pBarney = PRQ_create_item( pTail, 4);
	tail = PRQ_add_item( queue, pBarney );

	puts("FAILURE: test_PRQ_BigPriority");
}

void test_PRQ_removeItem()
{
	/*	Create a priority queue of four items and add an item called Fred to 
		the head of the third priority queue. */

	char * pHead = "This is the head.";
	char * pTail = "This is the tail.";
	void * pdqData = NULL;

	PRQ_ID_t queue = PRQ_create_queue("Queue", 4);
	PRQ_ITEM_p_t pFred = NULL;
	PRQ_ITEM_p_t pBarney = NULL;
	PRQ_ITEM_p_t head = NULL;
	PRQ_ITEM_p_t tail = NULL;
	PRQ_ITEM_p_t dHead = NULL;
	PRQ_ITEM_p_t dTail = NULL;
	PRQ_ITEM_p_t item = NULL;

	puts( "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" );
	puts( "*******Remove an item from the Priority Queue Test*******" );
	puts( "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" );
	
	puts(" \nCreate and add an item.");
	pBarney = PRQ_create_item( pTail, 4);
	tail = PRQ_add_item( queue, pBarney );

	test_EmptyQueue(queue);

	puts(" \nCreate and add an item to the head of the priority queue.");
	pFred = PRQ_create_item( pHead, 2);
	head = PRQ_enq_pri_head( queue, pFred );

	printf("Head data \"%s\" was added to priority queue %i.\n", PRQ_GET_DATA(head), pFred->priority);

	test_EmptyQueue(queue);

	puts("\nTest PRQ_remove_item function.");
	dTail = PRQ_remove_item( queue );
	printf("Item removed from list: %s\n", PRQ_GET_DATA(dTail));
	test_EmptyQueue(queue);

	puts("\nEmpty the queue.");
	queue = PRQ_empty_queue(queue, NULL);
	
	test_EmptyQueue(queue);

}

void test_destroyItem( PRQ_ITEM_p_t item)
{
	PRQ_ITEM_p_t rcode = NULL;
	printf("\nItem in destroy proc: %s\n", PRQ_GET_DATA( item ) );
	rcode = PRQ_destroy_item(item);

	if(NULL == rcode)
		puts( "The item was destroyed.");
	else
		puts("FAILURE: The item still exists.");

}
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
	STK_ID_t stack;

	stringArray[0] = ( "Barney" );
	stringArray[1] = ( "Fred" );
	stringArray[2] = ( "Wilma" );
	stringArray[3] = ( "Betty" );
	stringArray[4] = ( "Pebbles" );
	stringArray[5] = ( "Bam Bam" );

	if(stack = STK_NULL_ID)
		stack = STK_create_stack( MAX_STACK_SIZE );

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
	static STK_ID_t stack;
	
	stack = STK_create_stack( MAX_STACK_SIZE );	

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