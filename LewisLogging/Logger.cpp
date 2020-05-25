/*
*
*   @author - Christopher Lewis
*
*   
*   This is the implemention file for the "Logger" class.
*       Please refer to "Logger.h" for explanation of each function 
*       and their purpose.
*
*/

#include "Logger.h"

//=====================================================================================
Logger::Logger()
{
    priv_severityLevel = OFF;
    priv_FilePtr       = stderr;
}
//=====================================================================================
Logger::~Logger()
{
    fclose(priv_FilePtr);
    priv_FilePtr = nullptr;
}
//=====================================================================================
Logger::Logger(const char* fileName)
{
    priv_FilePtr = fopen(fileName , "w");

    if(priv_FilePtr == nullptr)     // just in case file doesn't open.    
    {
        fprintf(stderr, "Error: File did not open, setting output to 'stderr'\n");
        priv_FilePtr = stderr;
    }
}
//=====================================================================================
void Logger::setLevel(Severity severity)
{
    priv_severityLevel = severity;
    fprintf(priv_FilePtr,"Logging Level: %s\n", severityNames[priv_severityLevel]);
}
//=====================================================================================
void Logger::trace(const char* message)
{
    if(priv_severityLevel <= TRACE)
    {
        time_t currTime = time(nullptr);
        fprintf(priv_FilePtr,"\t%s\t\t%s\n", asctime(localtime(&currTime)), message);
    }
}
//=====================================================================================
void Logger::debug(const char* message)
{
    if(priv_severityLevel <= DEBUG)
    {
        time_t currTime = time(nullptr);
        fprintf(priv_FilePtr,"\t%s\t\t%s\n",asctime(localtime(&currTime)), message);
    }
}
//=====================================================================================
void Logger::info(const char* message)
{
    if(priv_severityLevel <= INFO)
    {
        time_t currTime = time(nullptr);
        fprintf(priv_FilePtr,"\t%s\t\t%s\n",asctime(localtime(&currTime)), message);
    } 
}
//=====================================================================================
void Logger::warn(const char* message)
{
    if(priv_severityLevel <= WARN)
    {
        time_t currTime = time(nullptr);
        fprintf(priv_FilePtr,"\t%s\t\t%s\n",asctime(localtime(&currTime)), message);
    } 
}
//=====================================================================================
void Logger::error(const char* message)
{
    if(priv_severityLevel <= ERROR)
    {
        time_t currTime = time(nullptr);
        fprintf(priv_FilePtr,"\t%s\t\t%s\n",asctime(localtime(&currTime)), message);
    }
}
//=====================================================================================
void Logger::fatal(const char* message)
{
    if(priv_severityLevel <= FATAL)
    {
        time_t currTime = time(nullptr);
        fprintf(priv_FilePtr,"\t%s\t\t%s\n",asctime(localtime(&currTime)), message);
    }
}
//=====================================================================================
//                         END OF LOGGER IMPLEMENTATION FILE
//
//=====================================================================================
