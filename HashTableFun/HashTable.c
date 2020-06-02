/*
*   @author - Christopher Lewis 
*   @date   - 5/25/2020
*   
*   This is the header file for the hash table. 
*
*/


#include "HashTable.h"


//==================================================
unsigned int hash(char *name)
{
    unsigned int hashValue = 0;
    unsigned int length = 0;
    while (*name != '\0')
    {
        hashValue += *name;

        name++;
        length++;
    }

    hashValue *= length;

    return hashValue % TABLE_SIZE;
}
//==================================================
void insertInTable(person_t *personToInsert)
{
    unsigned int index = hash(personToInsert->name); // Calculates the hash.
    unsigned int try   = 0;
    bool fixedCollision = false; // Set to false if there is a collision, true if no collision.

    // will loop through each spot in table, linear probing method for fixing collisions.
    for (int i = 0; i < TABLE_SIZE && fixedCollision == false; i++)
    {
        try = (index + i) % TABLE_SIZE; // have to account for collision, if no collision O(1) time insert.

        if (hashTable[try] == NULL)
        {
            hashTable[try] = personToInsert;
            fixedCollision = true;
        }
        else
        {
            fixedCollision = false;
        }
    }

    if (fixedCollision == false)
    {
        printf("\tNo more space in the table for: %s\n", personToInsert->name);
    }
}
//==================================================
void deleteFromTable(person_t *personToDelete)
{
    unsigned int index = hash(personToDelete->name); 
    unsigned int try   = 0;
    bool deletedPerson = false;

    for (int i = 0; i < TABLE_SIZE && deletedPerson == false; i++)
    {
        try
            = (index + i) % TABLE_SIZE;

        if (hashTable[try] == personToDelete)
        {
            hashTable[try] = NULL;
            deletedPerson = true;
        }
        else
        {
            deletedPerson = false;
        }
    }
}
//==================================================
void lookupInTable(person_t *personToLookUp)
{
    unsigned int index = hash(personToLookUp->name); 
    unsigned int try   = 0;
    bool personFound = false;

    for (int i = 0; i < TABLE_SIZE && personFound == false; i++)
    {
        try = (index + i) % TABLE_SIZE;

        if (hashTable[try] == personToLookUp)
        {
            printf("This person was found: %s\n", personToLookUp->name);
            personFound = true;
        }
    }

    if (personFound == false)
    {
        printf("This person was not found!: %s\n", personToLookUp->name);
    }
}
//==================================================
void initTable()
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        hashTable[i] = NULL;
    }
}
//==================================================
void printTable()
{
    printf("START\n");
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        if (hashTable[i] == NULL)
        {
            printf("%i\t----\n", i);
        }
        else
        {
            printf("%i\t%s\n", i, hashTable[i]->name);
        }
    }

    printf("END\n");
}
//==================================================
