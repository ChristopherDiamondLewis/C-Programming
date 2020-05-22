/*
*
*	@author - Christopher Lewis
*
*
*	Just some linked list practice, nothing super special, gotta keep skills up in quarentine.
*       Made a library with some basic functions for Linked Lists.
*
*	Testing
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
