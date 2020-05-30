/*
*
*	@author - Christopher Lewis
*	@date   - 5/10/2020
*
*	Just some linked list practice, nothing super special.
*       Made a library with some basic functions for Linked Lists.
*
*	
*
*/


#include <stdio.h>
#include "LinkedList.h"



int main()
{

	srand(time(NULL));
	
	
	node_t *head = NULL;
	
	
	for ( int i = 0 ; i < LIST_SIZE ; i++)
	{
		appendList(&head,rand() % 100);
		
	}
	
	
	printList(head);
	
	deleteFromIndex(head, 3);

	printList(head);
	
	
	
	return 0;
}
