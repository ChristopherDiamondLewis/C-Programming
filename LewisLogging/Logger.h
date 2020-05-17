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
   TRACE,DEBUG,INFO,WARN,ERROR,FATAL, OFF
};

class Logger
{

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

    private:
        Severity priv_severityLevel;
        FILE *priv_FilePtr = nullptr;
        time_t priv_currentTime = time(nullptr);
};  // end of Logger class

#endif
