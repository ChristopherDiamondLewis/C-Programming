/*
*
*   @author - Christopher Lewis
*
*   @compile -  clang++ LoggingDemo.cpp -o Logger
*
*
*
*
*/

#include <iostream>
#include <ctime>
#include <unistd.h>
#include "loggingDemo.h"

int menu();

int main()
{


    LOG(INFO) << "this is an info message\n";
    LOG(FATAL);
    LOG(TRACE);
   

}
int menu()
{
    int loggingLevel = 0;

    printf("Choose your logging level\n");



    return loggingLevel;

}

