/*******************************************************************************
 * File: ex8.c
 * Student: locsin
 * Date Submitted: Tue May 31 21:45:46 2005
 ******************************************************************************/
/****************************************************************************** 
* 
* File: ex8.c 
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
#include <zips.h> 
#include <linked_list.h> 
 
/*************************************************************************** 
 * constants 
 ***************************************************************************/ 
 
 
/*************************************************************************** 
 * typedefs 
 ***************************************************************************/ 
 
/*************************************************************************** 
 * prototypes 
 ***************************************************************************/ 
void showData(void* myData); 
void freeData(void* myData); 
 
/*************************************************************************** 
 * main function 
 ***************************************************************************/ 
int main( void ) 
{ 
    int returnValue = FALSE; 
    LINKED_LIST_p_t linkedList = NULL; 
    char myList[] = "My List"; 
    ZIPS_data_p_t  zipsArray = NULL; 
    int num_recs = 0, i= 0; 
    char * binary_file = "zips.bin";     
     
    /* Call the ZIPS_read_recs_from_bin function to get an array of 
       ZIPS_data_t records.*/ 
    returnValue = ZIPS_read_recs_from_bin( binary_file, 
                                           &zipsArray, 
                                           &num_recs ); 
 
    if(returnValue) 
    {         
        /* Create the linked list. */ 
        linkedList = LINKED_LIST_create_list(myList); 
 
        /* Link each record from the array in the list. */ 
        for( i = 0; i < num_recs; i++) 
        {         
            LINKED_LIST_add_to_list(linkedList, &zipsArray[i]); 
        }         
 
        /* Display the records.*/ 
        LINKED_LIST_operate_on_list(linkedList,  showData);     
 
        /* Free allocated space for the linked list. */ 
        LINKED_LIST_destroy_list(&linkedList, freeData); 
    } 
     
    /* Free any memory allocated on the heap.*/ 
    free(zipsArray); 
    zipsArray = NULL;     
     
    return returnValue; 
} 
 
void showData(void* myData) 
{ 
    ZIPS_print_recs(myData, 1); 
} 
 
void freeData(void* myData) 
{ 
    puts("\nDeleting this record."); 
    ZIPS_print_recs(myData, 1); 
}
/*******************************************************************************
 * End File: ex8.c
 ******************************************************************************/
