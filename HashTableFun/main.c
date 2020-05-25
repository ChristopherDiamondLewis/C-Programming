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


    initTable();
    printTable();    

    insertInTable(&chris);
    insertInTable(&kimmy);
    insertInTable(&kevin);
    insertInTable(&laura);
    insertInTable(&joe);
    insertInTable(&jacob);
    insertInTable(&david);
    printTable();

    lookupInTable(&chris);
    lookupInTable(&jacob);
    

    deleteFromTable(&david);
    printTable();
    lookupInTable(&david);


    
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
bool collision(person_t *personToInsert)
{
    unsigned int index = hash(personToInsert->name);
    bool fixedCollision = false;

    while(index + 1 < TABLE_SIZE && fixedCollision == false)       // if we have a collision we will go from hashed index up to end of list till empty spot.
    {
        if(hashTable[index +1] == NULL)
        {
            hashTable[index +1] = personToInsert;
            fixedCollision = true;

        }

        index++;
    }

    return fixedCollision;
}
//==================================================
void insertInTable(person_t *personToInsert)
{
    unsigned int index = hash(personToInsert->name);

    if(hashTable[index] != NULL)
    {
        
        if(collision(personToInsert) == false)
        {
            printf("\tNo more space in table\n");
        }


    }
    else
    {
        hashTable[index] = personToInsert;
    }

}
//==================================================
void deleteFromTable(person_t *personToDelete)
{
    unsigned int index = hash(personToDelete->name);

    hashTable[index] = NULL;

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

