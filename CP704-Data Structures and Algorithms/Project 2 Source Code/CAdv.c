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

#include <enq.h>
 
/*************************************************************************** 
 * constants 
 ***************************************************************************/ 
 
 
/*************************************************************************** 
 * typedefs 
 ***************************************************************************/ 


/*************************************************************************** 
 * prototypes 
 ***************************************************************************/ 

CDA_BOOL_t testDequeueHead();
void testDisplayList(ENQ_ANCHOR_p_t list);
void testDisplayListBackwards(ENQ_ANCHOR_p_t list);
void testAddItemBefore();
void testAddItemAfter();
int testHeadTail();

/*************************************************************************** 
 * main function 
 ***************************************************************************/ 
int main( void ) 
{
	if(testDequeueHead())
		puts("\nDequeue Head Test Result: SUCCESS!!.\n");
	else
		puts("\nDequeue Head Test Result: FAILED!!.\n");
	
	testAddItemBefore();
	testAddItemAfter();

	if(testHeadTail())
	{
		puts("Add and remove head and tail test successful");
	}
	else
	{
		puts("FAILURE--add and remove head and tail test.");
	}
}

CDA_BOOL_t testDequeueHead()
{
	CDA_BOOL_t rVal = CDA_FALSE;
	ENQ_ANCHOR_p_t pList = ENQ_create_list("Dequeue Head Test");
	ENQ_ITEM_p_t pHeadItem = ENQ_create_item("Head", sizeof(ENQ_ITEM_t));
	ENQ_ITEM_p_t pItem1 = ENQ_create_item("Item 1", sizeof(ENQ_ITEM_t));
	ENQ_ITEM_p_t pItem2 = ENQ_create_item("Item 2", sizeof(ENQ_ITEM_t));
	ENQ_ITEM_p_t pTailItem = ENQ_create_item("Tail", sizeof(ENQ_ITEM_t));
	ENQ_ITEM_p_t pReturnItem = NULL;
	ENQ_ITEM_p_t dqHead = NULL;
	ENQ_ITEM_p_t dqItem = NULL;
	ENQ_ITEM_p_t dqTail = NULL;

	puts("\nStart Dequeue Head Test\n");

	/* Add a head and a tail to the list. */
	if(NULL != pList)
	
		pReturnItem = ENQ_add_head(pList, pHeadItem);
		pReturnItem = ENQ_add_tail(pList, pTailItem);
		pReturnItem = ENQ_add_after(pItem1, pHeadItem );
		pReturnItem = ENQ_add_after(pItem2, pItem1 );
		rVal = CDA_TRUE;

	/* Display the list before removing the head.*/
	if(rVal)
	{
		printf("This is the %s list before removing the head item.\n", ENQ_GET_LIST_NAME(pList));
		testDisplayList(pList);
	}
	else
		rVal = CDA_FALSE;

	/* Remove the head */
	if(rVal)
	{
		dqHead = ENQ_deq_head(pList);
	}

	/* Display the list after removing the head.*/
	if( rVal && NULL != dqHead )
	{
		printf("\nThis is the %s list after removing the head item.\n", ENQ_GET_LIST_NAME(pList));
		testDisplayList(pList);
	}
	else
		rVal = CDA_FALSE;

	/* Remove the tail item */
	if(rVal)
		dqTail = ENQ_deq_tail(pList);
	
	/* Display the list after removing the tail.*/
	if(rVal && NULL != dqTail )
		{
			printf("\nThis is the %s list after removing the tail item.\n", ENQ_GET_LIST_NAME(pList));
			testDisplayList(pList);
		}
		else
			rVal = CDA_FALSE;

	/* Remove item 1 and display the list after removing item 1.*/
	if(rVal)
	{
		dqItem = ENQ_deq_item(pItem1);
		printf("\nThis is the %s list after removing the item 1.\n", ENQ_GET_LIST_NAME(pList));
		testDisplayList(pList);
	}
	
	/* Add the tail to the head of the list. */
	pReturnItem = ENQ_add_head(pList, pTailItem);

	/* Add the head to the tail of the list. */
	pReturnItem = ENQ_add_tail(pList, pHeadItem);

	/* Add item 1 after item 2. */
	pReturnItem = ENQ_add_after(pItem1, pItem2);

	/* Display the list */
	printf("\nThis is the %s list after adding some new items.\n", ENQ_GET_LIST_NAME(pList));
	testDisplayList(pList);
	puts("\nEnd Dequeue Head Test");
	return rVal;
}

void testDisplayList(ENQ_ANCHOR_p_t list)
{
	ENQ_ITEM_p_t pCurrentItem = ENQ_GET_NEXT(list);
	
	while(pCurrentItem != list)
	{
		printf("Item Name: %s\n", ENQ_GET_ITEM_NAME(pCurrentItem));
		pCurrentItem = ENQ_GET_NEXT(pCurrentItem);
	}
}

void testDisplayListBackwards(ENQ_ANCHOR_p_t list)
{
	ENQ_ITEM_p_t pCurrentItem = ENQ_GET_PREV(list);
	
	while(pCurrentItem != list)
	{
		printf("Item Name: %s\n", ENQ_GET_ITEM_NAME(pCurrentItem));
		pCurrentItem = ENQ_GET_PREV(pCurrentItem);
	}
}

void testAddItemBefore()
{
	ENQ_ANCHOR_p_t pList = NULL;
	ENQ_ITEM_p_t pHeadItem = NULL;
	ENQ_ITEM_p_t pBeforeItem = NULL;
	ENQ_ITEM_p_t pAfterItem = NULL;
	ENQ_ITEM_p_t pTailItem = NULL;
	ENQ_ITEM_p_t pReturnItem = NULL;

	puts("\nStart Add Item Before Test.\n");
	
	// Create the list
	pList = ENQ_create_list( "My Add Item Before" );

	if(NULL != pList)
	{
		printf("The list was successfully created at this address: ");
		printf("%p\n", pList);
	}
	else
	{
		puts("An error occurred creating this list.");
	}

	/*	Create an unenqueued item and add this item to the head of the list.*/
	pHeadItem = ENQ_create_item("Head", sizeof(ENQ_ITEM_t));
	pReturnItem = ENQ_add_head(pList, pHeadItem);

	/*	Create an unenqueued item and add this item to the tail of the list.*/
	pTailItem = ENQ_create_item("Tail", sizeof(ENQ_ITEM_t));
	pReturnItem = ENQ_add_tail(pList, pTailItem);

	/*	Create an unenqueued item and add this item after the head of the list.*/
	pAfterItem = ENQ_create_item("After Head", sizeof(ENQ_ITEM_t));
	pReturnItem = ENQ_add_after(pAfterItem, pHeadItem);

	/*	Display the list before adding item	*/
	printf("\nThis is the %s list before adding a new item.\n", ENQ_GET_LIST_NAME(pList));
	testDisplayList(pList);

/*	Create an unenqueued item and add this item after the tail of the list.*/
	pBeforeItem = ENQ_create_item("Before Tail", sizeof(ENQ_ITEM_t));
	pReturnItem = ENQ_add_before( pBeforeItem, pTailItem );

	// Test if the list is empty
	if( ENQ_is_list_empty(pList))
	
		printf("The list at %p is empty.\n", pList);
	
	else
	{
		printf("\nThis is the %s list after adding a new item.\n", ENQ_GET_LIST_NAME(pList));
		testDisplayList(pList);

		printf("\nThis is the %s list backwards.\n", ENQ_GET_LIST_NAME(pList));
		testDisplayListBackwards(pList);
	}

	// Destroy the list
	pList = ENQ_destroy_list(pList);

	if(NULL == pList)
	{
		puts("\nThe list was successfully destroyed.");
	}
	else
	{
		printf("The anchor item %s still exists.", pList->name);
	}

	puts("\nAdd Item Before Test Result: SUCCESS!!.\n");
}

void testAddItemAfter()
{
	ENQ_ANCHOR_p_t pList = NULL;
	ENQ_ITEM_p_t pHeadItem = NULL;
	ENQ_ITEM_p_t pAfterItem = NULL;
	ENQ_ITEM_p_t pTailItem = NULL;
	ENQ_ITEM_p_t pReturnItem = NULL;

	puts("\nStart Add Item Test.\n");
	
	// Create the list
	pList = ENQ_create_list( "My List" );

	if(NULL != pList)
	{
		printf("The list was successfully created at this address: ");
		printf("%p\n", pList);
	}
	else
	{
		puts("An error occurred creating this list.");
	}

	/*	Create an unenqueued item and add this item to the head of the list.*/
	pHeadItem = ENQ_create_item("Head", sizeof(ENQ_ITEM_t));
	pReturnItem = ENQ_add_head(pList, pHeadItem);

	/*	Create an unenqueued item and add this item to the tail of the list.*/
	pTailItem = ENQ_create_item("Tail", sizeof(ENQ_ITEM_t));
	pReturnItem = ENQ_add_tail(pList, pTailItem);

	/*	Display the list before adding item	*/
	puts("This is the list before adding a new item.");
	testDisplayList(pList);
	
	/*	Create an unenqueued item and add this item after the head of the list.*/
	pAfterItem = ENQ_create_item("After Head", sizeof(ENQ_ITEM_t));
	pReturnItem = ENQ_add_after(pAfterItem, pHeadItem );
	
	// Test if the list is empty
	if( ENQ_is_list_empty(pList))
	
		printf("The list at %p is empty.\n", pList);
	
	else
	{
		puts("\nThis is the list after adding a new item.");
		testDisplayList(pList);
	}

	// Destroy the list
	pList = ENQ_destroy_list(pList);

	if(NULL == pList)
	{
		puts("The list was successfully destroyed.");
	}
	else
	{
		printf("The anchor item %s still exists.", pList->name);
	}

	puts("\nAdd Item Test Result: SUCCESS!!.\n");
}

int testHeadTail()
{
	int rVal = CDA_FALSE;
	ENQ_ANCHOR_p_t pList = NULL;
	ENQ_ITEM_p_t pHeadItem = NULL;
	ENQ_ITEM_p_t pTailItem = NULL;
	ENQ_ITEM_p_t pReturnItem = NULL;
	
	// Create the list
	pList = ENQ_create_list( "My List" );

	if(NULL != pList)
	{
		printf("The list was successfully created at this address: ");
		printf("%p\n", pList);
		printf("The list name is %s.\n", ENQ_GET_LIST_NAME( pList ));
		printf("The item name in the list %s.\n", ENQ_GET_ITEM_NAME( pList ));
		printf("The head of the list is %s.\n", ENQ_GET_ITEM_NAME(ENQ_GET_HEAD(pList)));
		printf("The tail of the list is %s.\n", ENQ_GET_ITEM_NAME(ENQ_GET_TAIL(pList)));
		rVal = CDA_TRUE;
	}
	else
	{
		puts("An error occurred creating this list.");
	}

	/*	Create an unenqueued item and add this item to the head of the list.*/
	puts("\nCreate an item that will be the head of the list.");
	pHeadItem = ENQ_create_item("Head", sizeof(ENQ_ITEM_t));
	pReturnItem = ENQ_add_head(pList, pHeadItem);
	printf("The name of the head item is %s.\n", ENQ_GET_ITEM_NAME (pHeadItem));

	/*	Create an unenqueued item and add this item to the tail of the list.*/
	puts("\nCreate an item that will be the tail of the list.");
	pTailItem = ENQ_create_item("Tail", sizeof(ENQ_ITEM_t));
	pReturnItem = ENQ_add_tail(pList, pTailItem);
	printf("The name of the tail item is %s.\n", ENQ_GET_ITEM_NAME(ENQ_GET_TAIL(pList)));
	
	printf("The head of the list is %s.\n", ENQ_GET_ITEM_NAME(ENQ_GET_HEAD(pList)));
	printf("The tail of the list is %s.\n", ENQ_GET_ITEM_NAME(ENQ_GET_TAIL(pList)));
		

	// Test if the list is empty
	if( ENQ_is_list_empty(pList))
	
		printf("The list at %p is empty.\n", pList);
	
	else
		testDisplayList(pList);

	// Destroy the list
	pList = ENQ_destroy_list(pList);

	if(NULL == pList)
	{
		puts("The list was successfully destroyed.");
		rVal = CDA_TRUE;
	}
	else
	{
		printf("The anchor item %s still exists.", pList->name);
		rVal = CDA_FALSE;
	}

	return rVal;
}

