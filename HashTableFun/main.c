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

#define TABLE_SIZE 10

struct person
{
    char *name;
    int age;
};

typedef struct person person_t;

person_t *hashTable[TABLE_SIZE];


unsigned int hash (char *name);

void init_table();

void printTable();

int main()
{
    


    person_t student1;

    init_table();
    printTable();

    return 0;
}
unsigned int hash ( char *name)
{
    unsigned int checkSum = 0;

    while (*name != '\0')
    {
        checkSum += *name;
        name++;
    }

    return checkSum % TABLE_SIZE;
}
void init_table()
{
    for ( int i = 0 ; i <  TABLE_SIZE ; i++ )
    {
        hashTable[i] = NULL;

    }
}
void printTable()
{

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

}

