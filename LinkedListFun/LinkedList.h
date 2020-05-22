



#ifndef LINKEDLIST_H
#define LINKEDLIST_H


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>


#define LIST_SIZE 10

struct node
{
	int value;
	struct node *next;
};

typedef struct node node_t;



node_t *makeNode(int value);

bool foundInList(node_t *head, int value);

node_t *reverse(node_t *head);

int listLength(node_t *head);

void addToIndex(node_t *head, int index , int nodeValue);
void deleteFromIndex(node_t *head, int index);
void appendList(node_t **head, int value);
void printList(node_t *head);
node_t *removeFront(node_t *head);


#endif
