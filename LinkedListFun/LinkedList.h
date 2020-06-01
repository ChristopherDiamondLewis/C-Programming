/*
*
*	@author - Christopher Lewis
*	@date   - 5/10/2020
*
*	This is the header file for my Linked Lists.
*		Here I explain each function for Linked Lists that I made
*		and this is also where some macros and structs are defined/explained.
*
*	@reference - https://www.geeksforgeeks.org/linked-list-set-1-introduction/
*
*/


#ifndef LINKEDLIST_H
#define LINKEDLIST_H


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define LIST_SIZE 29

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
*	@return - newNode, of type 'node_t' or the function returns NULL if not enough memory.
*
*
*	@note - We have to do a 'harsh' exit in this function if no memory is left to allocate
*				I decided to do so because this function is called within other functions
*				and simplying returning isn't good enough of an 'out' if we are out of memory.
*
************************************/

	node_t *makeNode(int value);

/***********************************
*
*	Will remove the first node in the list and
*		will correctly 'free' the head of the list
*		to avoid memory leaks.
*
*	@param  - head, of type 'node_t'
*	@return - newHead, of type 'node_t' which is just the newHead of the list.
*
*
************************************/

	node_t *removeFront(node_t *head);

/************************************
*
*	Searches the list for a node that has the desired
*		value passed to it by the caller.
*	Search is Linear so big 0(n) time, which scales with amount of nodes.
*
*	@param - head, of type 'node_t' used for starting point for searching.
*	@param - value, of type 'int' , which is the value we are searching for.
*
*	@return - found, of type 'bool', returns true if value found, false if not.
*
*************************************/

	bool foundInList(node_t *head, int value);

/****************************************
*
*	Will reverse the list linearaly.
*		 This function returns the 'new' head 
*		 head of the reversed list instead of changing
*		 the passed head.
*		 Therefore, to see the results of the reversal, you must assign
*		 what is returned from this function to a node, then utilize that node
*		 as the new 'head' of the list.
*
*	@param  - head, of type 'node_t'
*
*	@return - head, of type 'node_t'  which is just the new head of the reversed list.
*
*****************************************/

	node_t *reverse(node_t *head);

/*******************************************
*
*	Returns length of list using the simple traversal method
*		going through each node and keeping track of how many there are
*		until the traversal node reaches the end.
*	
*	@param  - head, of type 'node_t'
*	
*	@return - length, of type 'int'
*
*******************************************/

	int listLength(node_t *head);

/******************************************
*
*	This function adds to the list at any spot in the list.
*	
*	If the 'index' where the caller wants to add the node is larger
*		than the lists length, then the new node is added to the end of the list.
*
*	@param - head, of type 'node_t'
*	@param - index, of type 'int', this is the spot caller is added the new node to.
*	@param - nodeValue, of type 'int', the value the caller wants to add to the list.
*
*	@return - function is void, no return value.
*
*******************************************/

	void addToIndex(node_t *head, int index , int nodeValue);

/******************************************
*
*	This function removes to the list at any spot in the list.
*	
*	If the 'index' where the caller wants to remove the node is larger
*		than the lists length, then the function will not do anything and print an error.
*	This function also correctly frees up memory from deleted node.
*
*	@param - head, of type 'node_t'
*	@param - index, of type 'int', this is the spot caller is removing the node from.
*
*	@return - function is void, no return value.
*
*******************************************/

	void deleteFromIndex(node_t *head, int index);

/*******************************************
*	Adds to the end of the list.
*
*	@param - head, of type 'node_t', this is a double pointer so that the function can change it during exectution.
*	@param - value, of type 'int' used to make a new node that will be inserted at the end of the list.
*
*	@return - function is void, no return value.
********************************************/

	void appendList(node_t **head, int value);

/*******************************************
*	This function prints the list from the given
*		head.
*
*	Expected Format:
*		{Node_Value} -> {Node_Value} -> ... NULL
*
*	@param - head, of type 'node_t'
*
********************************************/

	void printList(node_t *head);

//********************************************/
//
//		END OF LINKED LIST HEADER FILE
//
//********************************************/
#endif
