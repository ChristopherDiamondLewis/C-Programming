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


#include "HashTable.h"

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
    
    printTable();



    return 0;
}
