/*
*   @author  - Christopher Lewis
*   @Created - 5/17/2020
*   
*
*   LoggerDemo meant to show the different levels the logger should be able to write to
*       as well as show the loggers ability to write to a file or the terminal.
*
*   @compile - clang++ -std=c++17 -Wall -Wextra -Wpedantic Logger.cpp LoggerDemo.cpp -o LoggerDemo
*
*   @notes   - It easier to use the provided Makefile to compile & clean up if running multiple times.
*               the commands being 'make' to compile all object files into an executable & 'make clean'
*               which will delete all object files in currenty directory.                   
*
*/

#include "Logger.h"

// Prototype for demo function which will help test the logger.
void demo(Logger &myLogger);

/****************************************
*   Main entry point for application.
*       Just to test the different log levels & testing if log levels
*       are displayed or written to the desired output stream coprrectly.
*
*   Makes two different instances of the logger object, one with a file that log messages
*       will be written to, and the other which will write directly to the console/terminal. 
*      
*   The logging level will change during this function to show the correct functionality of the logger.
* 
*   @return - function will return 0 if exectuted with no errors.
*/
int main()
{
    
    Logger myLoggerFile("LoggerOut.txt");   // Any log messages used by 'myLoggerFile' are written to the specified '.txt' file.
    Logger myLoggerTerminal;                // Any log messages used by 'myLoggerTerminal' are written to terminal/console.


     // Test setting log levels & writing to the terminal/console.
    myLoggerTerminal.setLevel(TRACE);
    demo(myLoggerTerminal);
    myLoggerTerminal.setLevel(DEBUG);
    demo(myLoggerTerminal);
    myLoggerTerminal.setLevel(INFO);
    demo(myLoggerTerminal);
    myLoggerTerminal.setLevel(WARN);
    demo(myLoggerTerminal);
    myLoggerTerminal.setLevel(ERROR);
    demo(myLoggerTerminal);
    myLoggerTerminal.setLevel(FATAL);
    demo(myLoggerTerminal);

    // Test setting log levels & writing to a file.
    myLoggerFile.setLevel(TRACE);       
    demo(myLoggerFile);
    myLoggerFile.setLevel(DEBUG);
    demo(myLoggerFile);
    myLoggerFile.setLevel(INFO);
    demo(myLoggerFile);
    myLoggerFile.setLevel(WARN);
    demo(myLoggerFile);
    myLoggerFile.setLevel(ERROR);
    demo(myLoggerFile);
    myLoggerFile.setLevel(FATAL);
    demo(myLoggerFile);
   
    // Test turning off the logging for both writing to file & console/terminal.
    myLoggerFile.setLevel(OFF);
    myLoggerTerminal.setLevel(OFF);

    demo(myLoggerFile);
    demo(myLoggerTerminal);

    return 0;
}
/*********************************************************
*   Function used to help not bloat the main, it will take a 'Logger' variable 
*       by reference & call all of logging level message functions.
*
*   This 'demo' function help determine if the setting of logging levels is 
*       correctly implemented. The specific messages that are displayed depends on 
*       the log level of the 'Logger' variable passed to it. 
*
*   @param - myLogger, of type 'Logger' passed by reference.  
*
**********************************************************/
void demo(Logger &myLogger)
{
    myLogger.trace("This is a TRACE message!");
    myLogger.debug("This is a DEBUG message!");
    myLogger.info("This is an INFO message!");
    myLogger.warn("This is a WARN message!");
    myLogger.error("This is an ERROR message!");
    myLogger.fatal("This is a FATAL message!");
}
