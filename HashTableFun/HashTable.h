/*
*   @author - Christopher Lewis 
*   @date   - 5/25/2020
*   
*   This is the implementation file for the hashtable, where I explain all the functions, their purpose,
*       inputs & outputs. 
*   This is also where the TABLE_SIZE is defined as well as the values for the 'person_t' type
*       That actually makes up each element in the Hash Table.
*
*/

#include <stdio.h>
#include <stdbool.h>


#define TABLE_SIZE 10

struct person
{
    char *name;
    int   age;
};

typedef struct person person_t; 

person_t *hashTable[TABLE_SIZE];

unsigned int hash (char *name);

void insertInTable(person_t *personToInsert);
void initTable();

void lookupInTable (person_t *personToLookUp);
void deleteFromTable(person_t *personToDelete);
void printTable();

