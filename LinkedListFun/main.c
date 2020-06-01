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
	
	printf("This is our list\n");
	printList(head);
	
	addToIndex(head,8,10);
	printf("I just added a new node at index 8!\n");
	printList(head);

	head = reverse(head);

	printf("Here is that list but in REVERSE!\n");
	printList(head);

	appendList(&head, 777);
	appendList(&head, 1234);
	printf("We will add a two nodes to the end of the list.\n");
	printList(head);

	printf("We will get rid of node at index 5\n");
	deleteFromIndex(head, 5);
	printList(head);

	printf("Now remove the head of list and reverse!\n");

	head = removeFront(head);

	head = reverse(head);

	printList(head);


	
	
	return 0;
}
