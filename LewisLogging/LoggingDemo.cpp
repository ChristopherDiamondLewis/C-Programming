/*
*
*   @author - Christopher Lewis
*
*   @compile -  clang++ LoggingDemo.cpp -o Logger
*
*
*   @references - 
*
*
*
*/

#include <iostream>
#include <ctime>

#include <unistd.h>
#include "loggingDemo.h"


// Logging Testing Functions...

int logMenu();
void logDemo();

int main()
{
    int logLevel;

    while(1)
    {
        
        logLevel = logMenu();
        
        switch(logLevel)
        {

            case TRACE: LOG(TRACE);     break;
            case DEBUG: LOG(DEBUG);     break;
            case INFO:  LOG(INFO);      break;
            case WARN:  LOG(WARN);      break;
            case ERROR: LOG(ERROR);     break;
            case FATAL: LOG(FATAL);     break;


            default: logDemo(); break;


        }


    }
    

}
int  logMenu()
{

    using std::cin;

    int logLevel;

    printf("Choose your logging level\n");
    printf("TRACE: 0\n");
    printf("DEBUG: 1\n");
    printf("INFO:  2\n");
    printf("WARN:  3\n");
    printf("ERROR: 4\n");
    printf("FATAL: 5\n");
    printf("DEMO/ALL:  6\n");

    cin >> logLevel;
    
    return logLevel;



}
void logDemo()
{


    LOG(TRACE);
    LOG(TRACE);
    LOG(FATAL);



}