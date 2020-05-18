/*
*
*   @author - Christopher Lewis
*
*       This is the header file for the Logger class.
*       It robustly explains each functions purpose, their inputs and
*       how they should operate.
*
*   Example of Output:
*       Logging Level: {Log_Level}
*               DAY MON DATE HOUR:MIN:SEC YEAR   
*                       "This is a(n) {Log_Level} message!"
*
*       
*   @reference(s) - https://www.tutorialspoint.com/log4j/log4j_logging_methods.htm
*
* 
*
*
*/

#ifndef LOGGER_H
#define LOGGER_H

#include <cstdio>
#include <ctime>

/*******************************************************************************
*
*       Enumerated datatypes that represent the different logging or severity
*           levels. Used by the caller for setting a log level to determine
*           which log messages are displayed.
*       
*       NUM_SEVERITIES is to keep track of how many different logging levels
*           there are, if another level is added or removed,then the value 
*           of NUM_SEVERITIES will reflect that change.
*
*       The 'OFF' severity is the default severity given to any instance of the
*           Logger, when set to 'OFF' no log messages will be displayed.  
*
*********************************************************************************/
    enum Severity 
    {
        TRACE,DEBUG,INFO,WARN,ERROR,FATAL,OFF,NUM_SEVERITIES
    };

/*********************************************************************************/

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
*           open file depending on how the caller declares 
*           the logger object. 
*
******************************************************/
        
        FILE *priv_FilePtr;

/******************************************************/
/******************************************************/       

    public:
/*******************************************************
*       Non-parameterized constructor, will set the 
*           severity level to 'OFF' & the FILE pointer to 
*           'stderr' so that the output for the log messages
*           are displayed to the 'stderr' output stream.
*           This can be changed to be 'stdout', 'clog' or 
*           any viable output stream.
*
*******************************************************/

        Logger();

/*******************************************************
*
*       Parameterized constructor, will take a given filename
*           open a text file of that name in 'WRITE_MODE' 
*           and assign it to the FILE pointer to be used as the output stream.
*
*
*******************************************************/

        Logger(const char* fileName);

/*******************************************************
*
*       Destructor will close our output stream as well
*           as set the FILE pointer to null.
*       Both steps are necessary to ensure no danlging pointers
*           because closing the file does not change 
*           what the FILE pointer was pointing to.
*           
*
*       The desctructor is made virtual because TODO.
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
*       Also displays a message to output stream showing which
*           logging level the logger has been set to, making it
*           easier to visually parse output.
*
*******************************************************/

        void setLevel(Severity severity);

/*******************************************************
*       Displays log messages with the 'message' that is passed
*           by the caller along with a timestamp for when
*           the log message occurred.
*       
*       Output Format To Expect:
*           DAY MON DATE HOUR:MIN:SEC YEAR   
*                   "This is a(n) {LogLevel} message!"
*
*       The 'if' statments in each of the logging level's functions
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
*       This is an array of the actual names of each logging
*           level used in the 'setLevel' function to correctly
*           output the name of the loggers current log level.
*       The enumerated severity/logging level will map directly to
*           the respective string representaion of that level.
*
*       Example: 
*           if the severity/logging level is TRACE, then 
*           severityNames[TRACE] will yeild the string "TRACE".   
*
*******************************************************/

        const char* severityNames[NUM_SEVERITIES] = {"TRACE", "DEBUG" , "INFO", "WARN", "ERROR", "FATAL", "OFF"};

};  // end of Logger class

#endif
