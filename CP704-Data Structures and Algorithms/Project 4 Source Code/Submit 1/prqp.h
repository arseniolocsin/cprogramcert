#ifndef PRQP_H    /* begin include sandwich          */
#define PRQP_H    /* second line of include sandwich */

/***************************************************************************** 
Header Files 
*****************************************************************************/ 
#include <prq.h>
#include <enq.h>


/***************************************************************************** 
Macros 
*****************************************************************************/ 


/***************************************************************************** 
Typedefs
*****************************************************************************/
typedef struct prq__control_s
{
	ENQ_ANCHOR_p_t * anchors;
	char *			 name;
	CDA_UINT32_t max_priority;
} PRQ__CONTROL_t, *PRQ__CONTROL_p_t;

/***************************************************************************** 
Function Prototypes 
*****************************************************************************/ 


#endif            /* end include sandwich            */