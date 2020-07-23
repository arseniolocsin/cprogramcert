/******************************************************************************
 *
 * File: linked_list.c
 *
 * System: abstract linked list
 * 
 * Description:  simple linked list library
 *   
 * Revision History
 * Date         Programmer Name     Description
 * -----------  ------------------  ----------------
 * 01-Apr-2005  Some Programmer     Original
 *****************************************************************************/

#include <stdlib.h>
#include <string.h>
#include <linked_list.h>

/*---------------------------------------------------------------------------*
 * item_s: internal list item type 
 *---------------------------------------------------------------------------*/
typedef struct item_s
{
    struct item_s * next;
    void * user_data;
} item_t;

/*---------------------------------------------------------------------------*
 * LINKED_LIST_s: internal list type
 *---------------------------------------------------------------------------*/
typedef struct LINKED_LIST_s
{
    item_t * head;
    item_t * tail;
    char list_name[LINKED_LIST_NAME_LEN+1];
} LINKED_LIST_t;

/*---------------------------------------------------------------------------*
 * LINKED_LIST_create_list 
 *---------------------------------------------------------------------------*/
extern LINKED_LIST_p_t LINKED_LIST_create_list(
        const char * list_name  /* <I> - list name or NULL */
)
{
    LINKED_LIST_p_t ptr = malloc( sizeof( LINKED_LIST_t) );
    if ( ptr )
    {
        ptr->head = NULL;
        ptr->tail = NULL;
        if ( list_name )
        {
            strncpy( ptr->list_name, list_name, LINKED_LIST_NAME_LEN );
            ptr->list_name[LINKED_LIST_NAME_LEN] = '\0';
        }
    }
    return ptr;
}
/*---------------------------------------------------------------------------*
 * LINKED_LIST_add_to_list 
 *---------------------------------------------------------------------------*/
extern void LINKED_LIST_add_to_list(
        LINKED_LIST_p_t list_head,   /* <I> the list */
        void * user_data             /* <I> pointer to user object */
)
{
    item_t * new_item = malloc( sizeof( item_t ) );
    if ( new_item == NULL )
        abort();

    new_item->user_data = user_data;
    new_item->next = NULL;

    if ( list_head->head == NULL )
    {
        list_head->head = new_item;
        list_head->tail = new_item;
    }
    else
    {
        list_head->tail->next = new_item;
        list_head->tail = new_item;
    }
}
/*---------------------------------------------------------------------------*
 * LINKED_LIST_operate_on_list 
 *---------------------------------------------------------------------------*/
extern void LINKED_LIST_operate_on_list(
        LINKED_LIST_p_t list_head,           /* <I> the list */
        void (*item_operate_proc)( void * )  /* <I> proc to apply to each list item */
)
{
    item_t * list_item = list_head->head;

    while( list_item )
    {
        item_operate_proc( list_item->user_data );
        list_item = list_item->next;
    }
}

/*---------------------------------------------------------------------------*
 * LINKED_LIST_find_item_in_list 
 *---------------------------------------------------------------------------*/
extern void * LINKED_LIST_find_item_in_list(
        LINKED_LIST_p_t list_head,                                  /* <I> the list */
        int (*item_find_proc)( void * user_data, void * key_data ), /* <I> find proc */
        void * key_data                                             /* <I> pass through data */
)
{
    item_t * list_item = list_head->head;

    while ( list_item && !item_find_proc( list_item->user_data, key_data ) )
       list_item = list_item->next;
    return list_item?list_item->user_data:NULL;
}

/*---------------------------------------------------------------------------*
 * LINKED_LIST_destroy_list 
 *---------------------------------------------------------------------------*/
extern void LINKED_LIST_destroy_list(
        LINKED_LIST_p_t * list_head,                  /* <I> the list */
        void (*item_destroy_proc)( void * user_data ) /* <I> destroy proc OR NULL */
)
{
    while( (*list_head)->head )
    {
        item_t * list_item = (*list_head)->head;
        (*list_head)->head = list_item->next;

        if ( item_destroy_proc )
            item_destroy_proc( list_item->user_data );

        free( list_item );
    }
    free( *list_head );
    *list_head = NULL;
}
