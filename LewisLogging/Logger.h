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
*           severity level to 'OFF' & FILE pointer to null.
*
*******************************************************/

        Logger();

/*******************************************************
*
*       Parameterized constructor, will take a given filename
*           open a file of that name and assign it to the
*           FILE pointer to be used as the output stream.
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
*       
*
*
*
*******************************************************/

        void setLevel(Severity severity);

/*******************************************************
*
*   
*
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
