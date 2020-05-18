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

#ifndef LOGGER_H
#define LOGGER_H

#include <cstdio>
#include <ctime>


enum Severity 
{
            TRACE,DEBUG,INFO,WARN,ERROR,FATAL,OFF,NUM_SEVERITIES
};

class Logger
{

    private:
/*****************************************************
*       Enumurated datatype to represent the severity
*           of the Logger, works with the 'setLevel'
*           function to determine which logging level
*           messages are displayed.
*
******************************************************/

        Severity priv_severityLevel;

/*****************************************************
*   
*       File pointer used to determine which output stream
*           the log messages will be written to.
*       A FILE pointer can point to stderr or an
*       open file depending on how the caller declares 
*       the logger object. 
*
******************************************************/
        
        FILE *priv_FilePtr;

/******************************************************/
/******************************************************/       

    public:
/*******************************************************
*       Non-parameterized constructor, will set the 
*           severity level to 'OFF' & FILE pointer to nullptr.
*
*******************************************************/

        Logger();

/*******************************************************
*
*       Parameterized constructor, will take a given filename
*           open a text file of that name in 'WRITE_MODE' 
            and assign it to the FILE pointer to be used as the output stream.
*
*
*******************************************************/

        Logger(const char* fileName);

/*******************************************************
*
*
*******************************************************/

        virtual ~Logger();

/*******************************************************
*
*       Will take a given severity, passed to it by
*           the caller and change the logging level to the 
*           passed severity.
*           This will determine what level of log messages
*           are displayed by caller.
*
*******************************************************/

        void setLevel(Severity severity);

/*******************************************************
*       Displays log messages with the 'message' that is passed
*           by the caller along with a timestamp for when
*           the log message occurred.
*       
*       Output Format To Expect:
*           DAY MON DATE HOUR:MINUTE:SECOND YEAR   
*                   "This is a {LogLevel} message!"
*
*       The 'if' statments in each of the logging level's
*           are used to determine if that level's message should be displayed
*           or not, due to enumerated datatypes being represented
*           as integers starting from {0,1,2...etc}. 
*           This allows the logic to ensure that only the current
*           log levels & all levels 'higher' will be displayed.  
*
*       Example: 
*           If the logging level is set to WARN, & the caller
*               calls the 'warn' function; the logger will display the
*               warn,error & fatal messages.
*           However if the logging level is set to WARN & the caller
*               calls the 'trace' function, the trace log message will not be 
*               displayed.           
*
*******************************************************/
        void trace(const char* message);
        void debug(const char* message);
        void info (const char* message);
        void warn (const char* message);
        void error(const char* message);
        void fatal(const char* message);
/*******************************************************
*
*
*******************************************************/

        const char* severitys[NUM_SEVERITIES] = {"TRACE", "DEBUG" , "INFO", "WARN", "ERROR", "FATAL", "OFF"};

};  // end of Logger class

#endif
