/*******************************************************************************************************************************************************************
*Title			: Multiplication
*Description		: This function performs multiplication of two given large numbers and store the result in the resultant list.
*Prototype		: int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);
*Input Parameters	: head1: Pointer to the first node of the first double linked list.
			: tail1: Pointer to the last node of the first double linked list.
			: head2: Pointer to the first node of the second double linked list.
			: tail2: Pointer to the last node of the second double linked list.
			: headR: Pointer to the first node of the resultant double linked list.
*Output			: Status (SUCCESS / FAILURE)
*******************************************************************************************************************************************************************/
#include "apc.h"
#include <stdio.h>
#include<stdlib.h>

int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR,Dlist **tailR)
{
	/* Definition goes here */
    //check if list is empty
    if(*head1 == NULL || *head2 == NULL)
	return FAILURE;
    Dlist *temp1 = *tail1;
    Dlist *temp2 = *tail2;
    Dlist *tempR=(*tailR);
    Dlist *tempR_stat = *tailR;
    
    while(temp2!=NULL)
    {
       temp1 = *tail1;
       tempR = tempR_stat;
       
       while (temp1!=NULL)
       {
          //if result is empty
	  if(*headR == NULL)
	  {
             //create node
	   Dlist *new = malloc(sizeof(Dlist));
	  if(new == NULL)
	  {
	      return FAILURE;
	  }
	   new->data = temp1->data * temp2->data;
	       *headR = new;
	      *tailR = new;
	      tempR = new;
	      tempR_stat = *tailR;
	      
	      
	  }
	  
	  else if(tempR==NULL)
	  {
	      //create node
	   Dlist *new = malloc(sizeof(Dlist));
	   if(new == NULL)
	   return FAILURE;
	   
	   
	   
        
	    new->next = (*headR);
	    (*headR)->prev = new;
	    (*headR) = new;
	    tempR = new;
	    new->data = (temp1->data * temp2->data)+(tempR->next)->data/10;
	   (tempR->next)->data = (tempR->next)->data % 10;
	 
	    
	    
	  }
	  else if(tempR!=NULL)
	  {
             tempR->data = tempR->data +(temp1->data * temp2->data)+(tempR->next)->data/10;
	     (tempR->next)->data = (tempR->next)->data % 10;
	  }
	  temp1 = temp1->prev;
          tempR = tempR->prev;
       }
       temp2 = temp2->prev;
      tempR_stat = tempR_stat->prev;
    }
     

    return SUCCESS;
}
