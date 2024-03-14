/*******************************************************************************************************************************************************************
*Title			: Addition
*Description		: This function performs addition of two given large numbers and store the result in the resultant list.
*Prototype		: int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);
*Input Parameters	: head1: Pointer to the first node of the first double linked list.
			: tail1: Pointer to the last node of the first double linked list.
			: head2: Pointer to the first node of the second double linked list.
			: tail2: Pointer to the last node of the second double linked list.
			: headR: Pointer to the first node of the resultant double linked list.
*Output			: Status (SUCCESS / FAILURE)
*******************************************************************************************************************************************************************/
#include "apc.h"
#include<stdio.h>
#include<stdlib.h>

int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR,Dlist **tailR)
{
	/* Definition goes here */
    //check if list 1 is empty or not
    if(*head1 == NULL|| *head2 == NULL)
	return FAILURE;
    else if((*head1)->data ==0 && (*head1)->next==NULL)
    {
       *headR=*head2;
       return SUCCESS;
    }
    else if((*head2)->data == 0 && (*head2)->next == NULL)
    {
	*headR=*head1;
	return SUCCESS;
    }
    
  int data;	     
  Dlist *temp1= *tail1;
  Dlist *temp2= *tail2;
  
  while(temp1 != NULL && temp2 != NULL)
  {
      
      //create new node
      Dlist *new = malloc(sizeof(Dlist));
      if(new == NULL)
      {
	  return FAILURE;
      }
     new->data = (temp1->data + temp2->data);
        new->next = NULL;	
        new->prev = NULL;
      
      if((*headR) == NULL)
	  
      {
        *headR = new;
	*tailR = new;
      }
      else
      {
	
        (*headR)->prev = new;
	new->next = *headR;
	*headR = new;
	new->data = new->data + ((new->next)->data / 10);
	(new->next)->data = (new->next)->data % 10;
	
      }
      
      temp1 = temp1->prev;
      temp2 = temp2->prev;
      
     
  }
  
  if(temp1!=NULL)
  {
      
      while(temp1!=NULL)
      {
	  
        //create new node
	  Dlist *new = malloc(sizeof(Dlist));
	  new->next=NULL;
	  new->prev=NULL;

	  new->data = temp1->data+((*headR)->data/10);
	  (*headR)->data = (*headR)->data % 10;
	  (*headR)->prev = new;
	  new->next = (*headR);
	  (*headR) = new;
	 
	 temp1 = temp1->prev; 
      }
  }
  else if(temp2!=NULL)
  {
      
      while(temp2!=NULL)
      {
        //create new node
	  Dlist *new = malloc(sizeof(Dlist));
	  new->next=NULL;
	  new->prev=NULL;

	  new->data = temp2->data+((*headR)->data/10);
	  (*headR)->data = (*headR)->data % 10;
	  (*headR)->prev = new;
	  new->next = (*headR);
	 (*headR)=new;
	 temp2 = temp2->prev; 
      }
  }
  
return SUCCESS;  
}
