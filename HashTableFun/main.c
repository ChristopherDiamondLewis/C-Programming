/*
*
*   @author - Christopher Lewis
*
*
*   Testing out hash-table nonsense
*
*
*
*
*
*
*/

#include <stdio.h>
#include <stdbool.h>

#define TABLE_SIZE 10

struct person
{
    char *name;
    int age;
};

typedef struct person person_t;

person_t *hashTable[TABLE_SIZE];


unsigned int hash (char *name);

bool insertInTable(person_t *personToInsert);

void initTable();

void printTable();

void  lookupInTable (person_t *personToLookUp);

int main()
{
    
    person_t chris = {.name = "Christopher"};        // inline decleration.
    person_t kimmy = {.name = "Kimberly"}; 
    person_t kevin = {.name = "Kevin"}; 
    person_t joe   = {.name = "Joeseph"};
    person_t laura = {.name = "Laura"};
    person_t jacob = {.name = "Jacob"};
    initTable();
    printTable();

    insertInTable(&chris);
    insertInTable(&kimmy);
    insertInTable(&kevin);
    insertInTable(&laura);
    insertInTable(&joe);
    insertInTable(&jacob);


    lookupInTable(&chris);
    lookupInTable(&jacob);

    printTable();
    return 0;
}
//==================================================
unsigned int hash (char *name)
{
    unsigned int checkSum = 0;

    while (*name != '\0')
    {
        checkSum += *name;
        //checkSum *= checkSum;
        name++;
    }

    return checkSum % TABLE_SIZE;
}
//==================================================
bool insertInTable(person_t *personToInsert)
{
    unsigned int index = hash(personToInsert->name);

    if(hashTable[index] != NULL)
    {
        printf("We have a collision! -> %s: %i\n", personToInsert->name, index);
        return false;       // We have a collision.
    }
    else
    {
        hashTable[index] = personToInsert;
    }
    
    return true;

}
//==================================================
void  lookupInTable (person_t *personToLookUp)
{
    unsigned int index = hash(personToLookUp->name);

    if(hashTable[index] == personToLookUp)
    {
        printf("This person was found!: %s\n", personToLookUp->name);
    }
    else
    {
        printf("This person was not found!: %s\n", personToLookUp->name);

    }
    
}
//==================================================
void initTable()
{
    for ( int i = 0 ; i <  TABLE_SIZE ; i++ )
    {
        hashTable[i] = NULL;

    }
}
//==================================================
void printTable()
{
    printf("START\n");
    for (int i = 0 ; i < TABLE_SIZE ; i++)
    {
        if (hashTable[i] == NULL)
        {
            printf("%i\t----\n", i);
        }
        else
        {
            printf("%i\t%s\n", i , hashTable[i]->name);
        }
        
    }

    printf("END\n");

}
//==================================================

