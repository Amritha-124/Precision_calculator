#include "apc.h"
#include <stdio.h>
#include <stdlib.h>
void print_list(Dlist *head)
{
    
	/* Cheking the list is empty or not */
	if (head == NULL)
	{
		printf("INFO : List is empty\n");
	}
	else
	{
	    while (head)		
	    {
		    /* Printing the list */
		    printf("%d", head -> data);

		    /* Travering in forward direction */
		    head = head -> next;
	    }
    }
}


char findOperator(char *s)
 {
     int i=0 ;
      while(s[i] != '\0')
     {
         if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
         {
              return s[i];
          }
         i++;
      }
  }

int insertElements(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,char *s)
  {
   int i=0;
 
    while(s[i] != '+' && s[i] != '-' && s[i] != '*' && s[i] != '/')
    {
       //create node
      Dlist *new = malloc(sizeof(Dlist));
      if(new== NULL)
      {
	  return FAILURE;
      }
       new->data = s[i]-48;
           new->prev = NULL;
           new->next = NULL;
       if(*head1 == NULL)
         {
           *head1 = new;
           *tail1 = new;
          
           
         }
       else
       {
         (* tail1)->next = new;
         new->prev = (*tail1);
         *tail1 = new;
       }
  
         i++;
  
     }
     i++;
     while(s[i] !='\0')
     {
          Dlist *new = malloc(sizeof(Dlist));
         new->data = s[i] - 48;
           new->prev = NULL;
           new->next = NULL;

         if(*head2 == NULL)
         {
           *head2 = new;
           *tail2 = new;
         }
	 else
	 {
         (* tail2)->next = new;
         new->prev = (*tail2);
        
         *tail2 = new;
         }
         i++;
	 
  
  
     }
     return SUCCESS;
  
  }

