/*
*
*   @author - Christopher Lewis
*
*   
*
*
*   
*
*
*
*/
#include <cstdio>
#include "Logger.h"



Logger::Logger()
{
    priv_severityLevel = OFF;
    priv_FilePtr       = stderr;
}
Logger::~Logger()
{
    fclose(priv_FilePtr);
    priv_FilePtr = nullptr;
}
Logger::Logger(const char* fileName)
{

    priv_FilePtr = fopen(fileName , "w");

}
void Logger::setLevel(Severity severity)
{

    priv_severityLevel = severity;

}
void Logger::trace(const char* message)
{
    if( priv_severityLevel <= TRACE )
    {
        fprintf(priv_FilePtr,"%s\t%s\n", asctime(localtime(&priv_currentTime)), message);
    }
    

}
void Logger::debug(const char* message)
{
    if(priv_severityLevel <= DEBUG)
    {
        fprintf(priv_FilePtr,"%s\t%s\n",asctime(localtime(&priv_currentTime)), message);
    }
    
}
void Logger::info(const char* message)
{
    if (priv_severityLevel <= INFO)
    {
        fprintf(priv_FilePtr,"%s\t%s\n",asctime(localtime(&priv_currentTime)), message);
    }
    
    
}
void Logger::warn(const char* message)
{
    if (priv_severityLevel <= WARN)
    {
        fprintf(priv_FilePtr,"%s\t%s\n",asctime(localtime(&priv_currentTime)), message);
    }
    
    
}
void Logger::error(const char* message)
{
    if(priv_severityLevel <= ERROR)
    {
        fprintf(priv_FilePtr,"%s\t%s\n",asctime(localtime(&priv_currentTime)), message);
    }
    
}
void Logger::fatal(const char* message)
{
    if(priv_severityLevel <= FATAL)
    {
        fprintf(priv_FilePtr,"%s\t%s\n",asctime(localtime(&priv_currentTime)) , message);
    }
    
    
}
