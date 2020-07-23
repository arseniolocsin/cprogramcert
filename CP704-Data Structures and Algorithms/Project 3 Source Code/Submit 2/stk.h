/****************************************************************************** 
File: stk.h
System: Stack module header
Programmer Name: Arsenio Locsin
******************************************************************************/
#ifndef STK_H    /* begin include sandwich          */
#define STK_H    /* second line of include sandwich */

#include <cda.h>
#include <stkp.h>
//#include <srtp.h>
#include <srt.h>

/***************************************************************************** 
Macros 
*****************************************************************************/ 
#define STK_NULL_ID (NULL)

/***************************************************************************** 
Typedefs
*****************************************************************************/ 
typedef struct stk__control_s *STK_ID_t;

/***************************************************************************** 
Function Prototypes 
*****************************************************************************/ 
extern STK_ID_t STK_create_stack( size_t size );
extern void STK_push_item( STK_ID_t stack, void *item );
extern void *STK_pop_item( STK_ID_t stack );
extern void *STK_peek_item( STK_ID_t stack );
extern CDA_BOOL_t STK_is_stack_empty( STK_ID_t stack );
extern CDA_BOOL_t STK_is_stack_full( STK_ID_t stack );
extern void STK_clear_stack( STK_ID_t stack );
extern STK_ID_t STK_destroy_stack( STK_ID_t stack );

#endif            /* end include sandwich            */
