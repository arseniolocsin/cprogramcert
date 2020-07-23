#ifndef LINKED_LIST_H_INCLUDED
#define LINKED_LIST_H_INCLUDED
/******************************************************************************
 *
 * File: LINKED_LIST.h
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


#define LINKED_LIST_NAME_LEN (40)

typedef struct LINKED_LIST_s * LINKED_LIST_p_t;

/*---------------------------------------------------------------------------*
 * LINKED_LIST_create_list 
 * Description: create abstract singly linked list
 *---------------------------------------------------------------------------*/
extern LINKED_LIST_p_t LINKED_LIST_create_list(
        const char * list_name  /* <I> - list name or NULL */
);
/*---------------------------------------------------------------------------*
 * LINKED_LIST_destroy_list 
 * Description: deletes abstract list memory - 
 *    given list head, a desctroy proc is applied to each item's data
 *    Pass item_destroy_proc == NULL, to ignore destroy proc 
 *---------------------------------------------------------------------------*/
extern void LINKED_LIST_destroy_list(
        LINKED_LIST_p_t * list_head,                   /* <I> the list */
        void (*item_destroy_proc)( void * user_data ) /* <I> destroy proc OR NULL */
);
/*---------------------------------------------------------------------------*
 * LINKED_LIST_operate_on_list 
 *---------------------------------------------------------------------------*/
extern void LINKED_LIST_operate_on_list(
        LINKED_LIST_p_t list_head,            /* <I> the list */
        void (*item_operate_proc)( void * )  /* <I> proc to apply to each list item */
);

/*---------------------------------------------------------------------------*
 * LINKED_LIST_find_item_in_list 
 * Description: finds an item in the list.  The item_find_proc returns
 *       TRUE, when list item is found. key_data is passed through
 *       to item_find_proc.
 * Returns:  item pointer when item found, otherwise NULL
 *---------------------------------------------------------------------------*/
extern void * LINKED_LIST_find_item_in_list(
        LINKED_LIST_p_t list_head,                                   /* <I> the list */
        int (*item_find_proc)( void * user_data, void * key_data ), /* <I> find proc */
        void * key_data                                             /* <I> pass through data */
);

/*---------------------------------------------------------------------------*
 * LINKED_LIST_add_to_list 
 * Description: add user object to list
 *---------------------------------------------------------------------------*/
extern void LINKED_LIST_add_to_list(
        LINKED_LIST_p_t list_head,  /* <I> the list */
        void * user_data           /* <I> pointer to user object */
);

#endif