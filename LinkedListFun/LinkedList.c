

#include "LinkedList.h"

//==========================================================
node_t *makeNode(int value)
{
	node_t *newNode = (node_t *)malloc(sizeof(node_t));

	if (newNode == NULL)
	{
		printf("Error: not enough memory!\n");	
		exit(0);
	}

	newNode->value = value;
	newNode->next = NULL;

	return newNode;
}
//==========================================================
node_t *removeFront(node_t *head)
{
	node_t *newHead = head;

	newHead = newHead->next;
	head = NULL;

	free(head);

	return newHead;
}
//==========================================================
bool foundInList(node_t *head, int value)
{
	bool found = false;

	node_t *traversal = head;

	while (traversal->next != NULL)
	{
		if (traversal->value == value)
		{
			found = true;
		}

		traversal = traversal->next;
	}

	return found;
}
//==========================================================
node_t *reverse(node_t *head)
{

	node_t *next;
	node_t *prev    = NULL;
	node_t *current = head;

	// traversal step...
	while (current != NULL)
	{
		next = current->next;
		current->next = prev; // linked backwards to prev node...
		prev = current;
		current = next;
	}

	head = prev;

	return head;	
}
//==========================================================
int listLength(node_t *head)
{
	int length = 0;

	node_t *temp = head;

	while (temp != NULL)
	{
		length++;
		temp = temp->next;
	}

	return length;
}
//==========================================================
void addToIndex(node_t *head, int index, int nodeValue)
{

	int counter = 0;

	node_t *newNode  = makeNode(nodeValue);
	node_t *currNode = head;
	node_t *prevNode;

	while (currNode->next != NULL && counter < index)
	{
		prevNode = currNode;
		currNode = currNode->next;
		counter++;
	}

	prevNode->next = newNode;
	newNode->next  = currNode;
}
//==========================================================
void deleteFromIndex(node_t *head, int index)
{
	int counter = 0;

	// need two traversals to keep track of previous node and current node.
	node_t *current = head;
	node_t *prev = current;

	while (current->next != NULL && counter < index)
	{

		prev 	= current;
		current = current->next;
		counter++;
	}
	if ( counter == index )
	{
		printf("There are less than %i nodes in the list\n", index);
	}
	else
	{
		prev->next = current->next;
		free(current);
	}

}
//==========================================================
void appendList(node_t **head, int value)
{

	node_t *newNode = makeNode(value);
	node_t *traversal = *head;

	if (*head == NULL)
	{
		*head = newNode;
		return;
	}

	// Traverse to the end of the list if it is bigger than 1...
	while (traversal->next != NULL)
	{
		traversal = traversal->next;
	}

	// once we reach the end we will link the new node to the end of list...
	traversal->next = newNode;
}
//==========================================================
void printList(node_t *head)
{
	int counter = 0;

	if (head == NULL)
	{
		return; // if list is empty, we exit.
	}

	node_t *temp;
	temp = head;

	while (temp != NULL)
	{
		printf("%d -> ", temp->value);
		if (counter == 10)
		{
			printf("\n");
			counter = 0;
		}

		temp = temp->next;
		counter++;
	}
	printf("NULL\n\n");
}
//==========================================================
//			END OF LINKED LIST IMPLEMENTATION FILE
//
//
//==========================================================
