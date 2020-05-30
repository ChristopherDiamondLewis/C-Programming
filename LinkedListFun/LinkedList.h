/*
*
*	@author - Christopher Lewis
*	@date   - 5/10/2020
*
*	This is the header file for my Linked Lists.
*		Here I explain each function for Linked Lists that I made
*		and this is also where some macros and structs are defined/explained.
*
*	
*	
*
*/




#ifndef LINKEDLIST_H
#define LINKEDLIST_H


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define LIST_SIZE 10

/**********************************
*
*	This is the structure that represents
*		each 'node' for the Linked List.
*	As per most nodes, simply holds a value
*	and a pointer to the 'next' node in the list.
*	
*
***********************************/
struct node
{
	int value;
	struct node *next;
};

typedef struct node node_t;	// some abstractions so we do not have to type 'struct node' for every declaration. 

/***********************************
*
*	Function for making each 'node' in the list
*		This function uses malloc to give us some new memory
*		to make each node, malloc returns NULL if there is not enough memory
*		to allocate.
*
*	@param - value, of type int, used for the 'value' of the node being made.
*	@return - newNode, of type 'node_t' or the function returns '-1' if not enough memory.
*
*
************************************/

	node_t *makeNode(int value);

/***********************************
*
*	
*
*
*
************************************/

	bool foundInList(node_t *head, int value);

node_t *reverse(node_t *head);

int listLength(node_t *head);

void addToIndex(node_t *head, int index , int nodeValue);
void deleteFromIndex(node_t *head, int index);
void appendList(node_t **head, int value);
void printList(node_t *head);
node_t *removeFront(node_t *head);


#endif
