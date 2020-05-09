#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LIST_SIZE 10

struct node
{
	int value;
	struct node *next;
};

typedef struct node node_t;



node_t *makeNode(int value);

void addToIndex(node_t *head, int index , int nodeValue);
void deleteFromIndex(node_t *head, int index);
void appendList(node_t **head, int value);
void printList(node_t *head);

int listLength(node_t *head);


int main()
{

	srand(time(NULL));
	
	
	node_t *head = NULL;
	
	
	for ( int i = 0 ; i < LIST_SIZE ; i++)
	{
		appendList(&head,i);
		
	}
	 printList(head);
	printf("This is the length of your list: %i\n" , listLength(head));
	 deleteFromIndex(head, 8);
	 
	
	 printList(head);
	 printf("This is the length of your list: %i\n" , listLength(head));
	
	 addToIndex(head, 1, 100);
	 
	 printList(head);
	
	
	 printf("This is the length of your list: %i\n" , listLength(head));
	
	
	return 0;
}
node_t *makeNode(int value)
{	
	node_t *newNode = malloc(sizeof(node_t));
	
	newNode->value = value;
	newNode->next  = NULL;
	
	
	return newNode;
	
}
void addToIndex(node_t *head, int index , int nodeValue)
{
	
	int counter = 0;
	
	node_t *newNode = makeNode(nodeValue);
	
	
	node_t *currNode = head;
	node_t *prevNode;
	
	
	while(currNode->next != NULL && counter < index )
	{
		prevNode = currNode;
		currNode = currNode->next;
		counter++;
	}
	
	prevNode->next = newNode;
	newNode->next  = currNode;
	
	
}

void deleteFromIndex(node_t *head, int index)
{
	int counter = 0;
	
	
	// need two traversals to keep track of previous node and current node...
	node_t *traverse1 = head;
	node_t *traverse2 = traverse1;
	
	while (traverse1->next != NULL && counter < index)
	{
		
		traverse2 = traverse1;
		traverse1 = traverse1->next;
		counter++;
	}
	
	traverse2->next = traverse1->next;
	
	free(traverse1);
	
	
}
void appendList(node_t **head, int value)
{
	
	node_t *newNode   =  makeNode(value);
	node_t *traversal = *head;
	
	
	if( *head == NULL )
	{	
		*head = newNode;
		return;
	}
	
	
	// Traverse to the end of the list if it is bigger than 1...
	while ( traversal->next != NULL ) 
	{
		traversal = traversal->next;
	}
	
	// once we reach the end we will link the new node to the end of list...
	traversal->next = newNode;
}

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
void printList(node_t *head)
{
	
	if (head == NULL)
	{
		return;
	}
	
	node_t *temp;
	
	temp = head;
	
	
	while (temp != NULL)
	{
		
		printf("%d-->" , temp->value);
		
		temp = temp->next;
		
	}
	printf("NULL\n");
	
}
