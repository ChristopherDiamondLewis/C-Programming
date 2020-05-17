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
#include <unistd.h>


void demo(Logger &myLogger);

int main()
{
    
    Logger myLogger("LogOut.txt");

    myLogger.setLevel(TRACE);
    demo(myLogger);
    myLogger.setLevel(FATAL);
    demo(myLogger);
    myLogger.setLevel(INFO);
    demo(myLogger);
    
   


}
void demo(Logger &myLogger)
{

    myLogger.trace("This is a TRACE message!");
    myLogger.debug("This is a DEBUG message!");
    myLogger.fatal("This is a FATAL message!"); 
    myLogger.info("This is a INFO message!");
    myLogger.warn("This is a  WARN message!");
    myLogger.error("This is a ERROR message!");

    

}
