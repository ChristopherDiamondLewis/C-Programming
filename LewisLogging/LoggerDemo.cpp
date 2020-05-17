/*
*
*   @author - Christopher Lewis
*
*   @compile -  clang++ LoggingDemo.cpp -o Logger
*
*
*   
*
*
*
*/



#include "Logger.h"

int main()
{
    
    Logger myLogger;

    myLogger.setLevel(INFO);

    myLogger.trace("This is a TRACE message!");
    myLogger.debug("This is a DEBUG message!");
    myLogger.fatal("This is a FATAL message!"); 
    myLogger.info("This is a INFO message!");
    myLogger.warn("This is a WARN message!");
    myLogger.error("This is a ERROR message!");


}
