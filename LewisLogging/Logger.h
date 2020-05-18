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
        Severity priv_severityLevel;
        FILE *priv_FilePtr = nullptr;
        

    public:
        Logger();
        Logger(const char* fileName);
        virtual ~Logger();

        void setLevel(Severity severity);
        void trace(const char* message);
        void debug(const char* message);
        void info (const char* message);
        void warn (const char* message);
        void error(const char* message);
        void fatal(const char* message);

        const char* severitys[NUM_SEVERITIES] = {"TRACE", "DEBUG" , "INFO", "WARN", "ERROR", "FATAL", "OFF"};

};  // end of Logger class

#endif
