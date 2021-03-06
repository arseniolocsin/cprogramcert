/****************************************************************************** 
File: enq.h
System: Doubly Linked List module header
Programmer Name: Arsenio Locsin
******************************************************************************/
#ifndef ENQ_H    /* begin include sandwich          */
#define ENQ_H    /* second line of include sandwich */

#include <cda.h>
#include <stdio.h>

/***************************************************************************** 
Macros 
*****************************************************************************/ 
#define ENQ_GET_HEAD( list ) ( (list)->flink )
#define ENQ_GET_TAIL( list ) ( (list)->blink )
#define ENQ_GET_NEXT( item ) ( (item)->flink )
#define ENQ_GET_PREV( item ) ( (item)->blink )
#define ENQ_GET_LIST_NAME( list ) ((const char *)((list)->name))
#define ENQ_GET_ITEM_NAME( item ) ((const char *)((item)->name))

/***************************************************************************** 
Typedefs
*****************************************************************************/ 
typedef struct enq_item_s
{
	struct enq_item_s *flink;
	struct enq_item_s *blink;
	char *name;
} ENQ_ITEM_t, *ENQ_ITEM_p_t;

typedef ENQ_ITEM_t ENQ_ANCHOR_t, *ENQ_ANCHOR_p_t;

/***************************************************************************** 
Function Prototypes 
*****************************************************************************/ 
extern ENQ_ANCHOR_p_t ENQ_create_list( const char *name );
extern ENQ_ITEM_p_t ENQ_create_item( const char *name, size_t size );
extern CDA_BOOL_t ENQ_is_item_enqed( ENQ_ITEM_p_t item );
extern CDA_BOOL_t ENQ_is_list_empty( ENQ_ANCHOR_p_t list );
extern ENQ_ITEM_p_t ENQ_add_head( ENQ_ANCHOR_p_t list, ENQ_ITEM_p_t item);
extern ENQ_ITEM_p_t ENQ_add_tail( ENQ_ANCHOR_p_t list, ENQ_ITEM_p_t item);
extern ENQ_ITEM_p_t ENQ_add_after( ENQ_ITEM_p_t item, ENQ_ITEM_p_t after);
extern ENQ_ITEM_p_t ENQ_add_before( ENQ_ITEM_p_t item, ENQ_ITEM_p_t before);
extern ENQ_ITEM_p_t ENQ_deq_item( ENQ_ITEM_p_t item );
extern ENQ_ITEM_p_t ENQ_deq_head( ENQ_ANCHOR_p_t list );
extern ENQ_ITEM_p_t ENQ_deq_tail( ENQ_ANCHOR_p_t list );
extern ENQ_ITEM_p_t ENQ_destroy_item( ENQ_ITEM_p_t item );
extern ENQ_ANCHOR_p_t ENQ_empty_list( ENQ_ANCHOR_p_t list );
extern ENQ_ANCHOR_p_t ENQ_destroy_list( ENQ_ANCHOR_p_t list );

#endif            /* end include sandwich            */


