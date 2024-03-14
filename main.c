/**************************************************************************************************************************************************************
*Title		: main function(Driver function)
*Description	: This function is used as the driver function for the all the functions
***************************************************************************************************************************************************************/
#include "apc.h"
#include <stdio.h>
int main()
{
	/* Declare the pointers */
	Dlist *head1, *tail1, *head2, *tail2, *headR,*tailR;
	char option, operator;
	do
	{
	head1=tail1=head2=tail2=headR=tailR=NULL;

	
		/* Code for reading the inputs */
	    char s[1000];
	    printf("Enter the Input:\n");
	    scanf("%s",s);

		/* Function for extracting the operator */
	    operator = findOperator(s);
            if(insertElements(&head1,&tail1,&head2,&tail2,s) == SUCCESS)
	    {
		printf("Elements inserted in list\n");
	    }
	    
		switch (operator)
		{
			case '+':
				/* call the function to perform the addition operation */
			        if(addition(&head1,&tail1,&head2,&tail2,&headR,&tailR) == SUCCESS)
				{
				    printf("The result is \n");
				    print_list(headR);
				}
				else
				{
				   printf("INFO: ADDITION FAILED!\n");
				}
				break;
			case '-':	
				/* call the function to perform the subtraction operation */
				if(subtraction(&head1,&tail1,&head2,&tail2,&headR,&tailR) == SUCCESS)
				{
				    printf("The result is \n");
				    print_list(headR);
				}
				else
				{
				   printf("INFO: SUBTRACTION FAILED!\n");
				}

				break;
			case '*':	
				/* call the function to perform the multiplication operation */
				if(multiplication(&head1,&tail1,&head2,&tail2,&headR,&tailR) == SUCCESS)
				{
				    printf("The result is \n");
				    print_list(headR);
				}
				else
				{
				   printf("INFO: MULTIPLICATION  FAILED!\n");
				}


				break;
			case '/':	
				/* call the function to perform the division operation */
				break;
			default:
				printf("Invalid Input:-( Try again...\n");
		}
		printf("\nWant to continue? Press [yY | nN]: ");
		scanf("\n%c", &option);
	}while (option == 'y' || option == 'Y');

	return 0;
}
