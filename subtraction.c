/*******************************************************************************************************************************************************************
*Title			: Subtraction
*Description		: This function performs subtraction of two given large numbers and store the result in the resultant list.
*Prototype		: int subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);
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

int subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR,Dlist **tailR)
{
	/* Definition goes here */
    //check if list is empty or not
    if(*head1==NULL || *head2==NULL)
    {
	return FAILURE;
    }
    /*
    else if((*head1)->data == 0 && (*head1)->next == NULL)
    {
       (*headR)=(*head2);
       return SUCCESS;
    }
    else if((*head2)->data == 0 && (*head2)->next == NULL)
    {
       (*headR) = (*head1);
       return SUCCESS;
    }*/
     
    //2 pointers
    Dlist *temp1 = *head1;
    Dlist *temp2 = *head2;
    int count1=1,count2=1;
    while(temp1->next!=NULL)
    {
      count1++;
      temp1 = temp1->next;
    }
    while(temp2->next!=NULL)
    {
      count2++;
      temp2 = temp2->next;
    }
    
    
    if(count1 <count2)
    {
	temp1 = *tail2;
	temp2 = *tail1;
    }
    else
    {
       temp1 = *tail1;
       temp2 = *tail2;
    }
   while(temp1!=NULL && temp2!=NULL)
   {
     //create node
       Dlist *new = malloc(sizeof(Dlist));
       if(new == NULL)
	   return FAILURE;
       new->next = NULL;
       new->prev = NULL;
        if(temp1->data >=temp2->data)
	 {
	     
	     new->data = temp1->data - temp2->data;
	     	 
	 }else
	 {
	     Dlist *temp_carr = temp1->prev;
	     while(temp_carr ->data == 0)
	     { 
		 temp_carr->data = temp_carr->data + 9;
		 temp_carr = temp_carr->prev;
	     }
	     
	     
	     temp1->data = temp1->data + 10;
	     (temp_carr)->data = (temp_carr)->data - 1;
	     

	     new->data = temp1->data - temp2->data;
	 }
	 
       if(*headR == NULL)
       {
	   
	 
	 *headR = new;
	 *tailR = new;
       }
       else
       {
	 new->next = (*headR);
	 (*headR)->prev = new;
	 (*headR)=new;
       }
       temp1=temp1->prev;
       temp2=temp2->prev;
   }
   if(temp1!=NULL)
   {
      while(temp1!=NULL)
      {
         //create node
	  Dlist *new = malloc(sizeof(Dlist));
	  if(new == NULL)
	      return FAILURE;
	  new->next = NULL;
	  new->prev = NULL;
	  new->data = temp1->data;
          new->next =(*headR);
	  (*headR)->prev = new;
	  (*headR) = new;
	  temp1 = temp1->prev;
      }
   }
   while((*headR)->data==0)
   {
       (*headR) = (*headR)->next;
       free((*headR)->prev);
   }
   if(count2>count1)
   {
      (*headR)->data = (-1)*((*headR)->data);
   }
   return SUCCESS;
    
}
