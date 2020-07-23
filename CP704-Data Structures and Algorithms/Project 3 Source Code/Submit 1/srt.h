/****************************************************************************** 
File: srt.h
System: Sort module header
Programmer Name: Arsenio Locsin
******************************************************************************/
#ifndef SRT_H    /* begin include sandwich          */
#define SRT_H    /* second line of include sandwich */

#include <stddef.h>

/***************************************************************************** 
Macros 
*****************************************************************************/ 

/***************************************************************************** 
Typedefs
*****************************************************************************/ 
typedef int				SRT_CMP_PROC_t( const void *data1, const void *data2);
typedef SRT_CMP_PROC_t	*SRT_CMP_PROC_p_t;


/***************************************************************************** 
Function Prototypes 
*****************************************************************************/ 
extern void SRT_mergesort(	void				*array,
							size_t				num_elements,
							size_t				element_size,
							SRT_CMP_PROC_p_t	cmp_proc
						);

extern void SRT_poly_mergesort(	void				**array,
								size_t				num_elements,
								SRT_CMP_PROC_p_t	cmp_proc
							  );

#endif            /* end include sandwich            */
