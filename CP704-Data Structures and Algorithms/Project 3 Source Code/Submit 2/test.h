/****************************************************************************** 
File: test.h
System: Test module header
Programmer Name: Arsenio Locsin
******************************************************************************/
#ifndef TESTP_H    /* begin include sandwich          */
#define TESTP_H    /* second line of include sandwich */

#include <stkp.h>
#include <srtp.h>
#include <cdap.h>
#include <stdio.h>

#define MAX_STACK_SIZE (1000)

/***************************************************************************** 
Macros 
*****************************************************************************/ 

/***************************************************************************** 
Typedefs
*****************************************************************************/ 


/***************************************************************************** 
Function Prototypes 
*****************************************************************************/ 

/*	Project 3 Functions*/
extern int compareIntegers(const void * left, const void * right);
extern int compareStrings(const void * left, const void * right);
extern void test_SRT_mergesort();
extern void test_SRT_poly_mergesort_strings();
extern void test_SRT_poly_mergesort_integers();
extern void test_STK();




/***************************************************************************** 
External Variable Declarations
*****************************************************************************/ 


#endif            /* end include sandwich            */