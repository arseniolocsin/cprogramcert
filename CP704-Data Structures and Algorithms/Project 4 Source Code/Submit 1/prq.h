#ifndef PRQ_H    /* begin include sandwich          */
#define PRQ_H    /* second line of include sandwich */

#include <stdlib.h>
#include <cdap.h>
#include <enq.h>

#define PRQ_NULL_ID (NULL)

/***************************************************************************** 
Macros 
*****************************************************************************/ 
#define PRQ_GET_DATA(item)		((item)->data) 
#define PRQ_GET_PRIORITY(item)	((item)->priority)


/***************************************************************************** 
Typedefs
*****************************************************************************/
typedef void PRQ_DESTROY_PROC_t( void *data );
typedef PRQ_DESTROY_PROC_t *PRQ_DESTROY_PROC_p_t;
typedef struct prq__control_s *PRQ_ID_t;

typedef struct prq_item_s
{
	ENQ_ITEM_t enq_item;
	void *data;
	CDA_UINT32_t priority;
} PRQ_ITEM_t, *PRQ_ITEM_p_t;




/***************************************************************************** 
Function Prototypes 
*****************************************************************************/ 
extern PRQ_ID_t PRQ_create_queue(const char *name, CDA_UINT32_t max_priority );
extern PRQ_ITEM_p_t PRQ_create_item( void *data, CDA_UINT32_t priority );
extern PRQ_ITEM_p_t PRQ_enq_pri_head( PRQ_ID_t queue, PRQ_ITEM_p_t item);
extern PRQ_ITEM_p_t PRQ_add_item( PRQ_ID_t queue, PRQ_ITEM_p_t item );
extern PRQ_ITEM_p_t PRQ_deq_pri_head( PRQ_ID_t queue, CDA_UINT32_t priority );
extern PRQ_ITEM_p_t PRQ_deq_item( PRQ_ITEM_p_t item);
extern PRQ_ITEM_p_t PRQ_remove_item( PRQ_ID_t queue );
extern PRQ_ITEM_p_t PRQ_destroy_item( PRQ_ITEM_p_t item );
extern CDA_BOOL_t PRQ_is_queue_empty( PRQ_ID_t queue );
extern PRQ_ID_t PRQ_empty_queue( PRQ_ID_t queue, PRQ_DESTROY_PROC_p_t destroy_proc );
extern PRQ_ID_t PRQ_destroy_queue( PRQ_ID_t queue, PRQ_DESTROY_PROC_p_t destroy_proc );


#endif            /* end include sandwich            */