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

#define TABLE_SIZE 30

struct person
{
    char *name;
    int   age;
};

typedef struct person person_t;

person_t *hashTable[TABLE_SIZE];


unsigned int hash (char *name);

bool collision(person_t *personToInsert);

void insertInTable(person_t *personToInsert);
void initTable();
void printTable();
void lookupInTable (person_t *personToLookUp);
void deleteFromTable(person_t *personToDelete);

int main()
{
    
    person_t chris = {.name = "Christopher" , .age = 23};        // inline decleration.
    person_t kimmy = {.name = "Kimberly", .age = 23}; 
    person_t kevin = {.name = "Kevin", .age = 55}; 
    person_t joe   = {.name = "Joe", .age = 15};
    person_t laura = {.name = "Laura", .age = 42};
    person_t jacob = {.name = "Jacob", .age =45};
    person_t david = {.name = "David", .age = 48};
    person_t dolly = {.name = "Dolly", .age = 55};
    person_t james = {.name = "James", .age = 66};
    person_t marge = {.name = "Margaret", .age = 255};
    person_t albert = {.name = "Albert", .age = 1000};

    initTable();
    printTable();    

    insertInTable(&chris);
    insertInTable(&kimmy);
    insertInTable(&kevin);
    insertInTable(&laura);
    insertInTable(&joe);
    insertInTable(&jacob);
    insertInTable(&david);
    insertInTable(&dolly);
    insertInTable(&james);
    insertInTable(&marge);
    insertInTable(&albert);
    printTable();

    deleteFromTable(&chris);
    insertInTable(&albert);
    printTable();



    return 0;
}
//==================================================
unsigned int hash (char *name)
{
    unsigned int hashValue = 0;
    unsigned int length    = 0;
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
    unsigned int index = hash(personToInsert->name);    // Calculates the hash.
    unsigned int try   = 0;     
    bool fixedCollision = false;             // Set to false if there is a collision, true if no collision.

    // will loop through each spot in table, linear probing method for fixing collisions.
    for (int i = 0 ; i < TABLE_SIZE && fixedCollision == false ; i++) 
    { 
        try = (index + i) % TABLE_SIZE;      // have to account for collision, if no collision O(1) time insert.

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

    if(fixedCollision == false)
    {
        printf("\tNo more space in the table for: %s\n", personToInsert->name);
    }
   
}
//==================================================
void deleteFromTable(person_t *personToDelete)
{
    unsigned int index = hash(personToDelete->name);    // Calculates the hash.
    unsigned int try   = 0;     
    bool deletedPerson = false;            

    
    for (int i = 0 ; i < TABLE_SIZE && deletedPerson == false ; i++) 
    { 
        try = (index + i) % TABLE_SIZE;      

        if (hashTable[try] == personToDelete)
        {
            hashTable[try] = NULL;
            deletedPerson  = true;
        }
        else
        {
            deletedPerson = false;
        }
    }

}
//==================================================
void  lookupInTable (person_t *personToLookUp)
{
    unsigned int index = hash(personToLookUp->name);    // Calculates the hash.
    unsigned int try   = 0;     
    bool personFound   = false;            

    
    for (int i = 0 ; i < TABLE_SIZE && personFound == false ; i++) 
    { 
        try = (index + i) % TABLE_SIZE;      

        if (hashTable[try] == personToLookUp)
        {
            printf("This person was found: %s\n", personToLookUp->name);
            personFound = true;
        }
    }


    if(personFound == false)
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

