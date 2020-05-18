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

void demo(Logger &myLogger);

int main()
{
    
    Logger myLoggerFile("LoggerOut.txt");
    Logger myLoggerTerminal;

    myLoggerTerminal.setLevel(FATAL);
    demo(myLoggerTerminal);
    myLoggerTerminal.setLevel(INFO);
    demo(myLoggerTerminal);

    myLoggerFile.setLevel(TRACE);
    demo(myLoggerFile);
    myLoggerFile.setLevel(FATAL);
    demo(myLoggerFile);
    myLoggerFile.setLevel(INFO);
    demo(myLoggerFile);
    myLoggerFile.setLevel(TRACE);
    demo(myLoggerFile);
    
   


}
void demo(Logger &myLogger)
{

    myLogger.trace("This is a TRACE message!");
    myLogger.debug("This is a DEBUG message!");
    myLogger.info("This is an INFO message!");
    myLogger.warn("This is a  WARN message!");
    myLogger.error("This is an ERROR message!");
    myLogger.fatal("This is a FATAL message!");


}
