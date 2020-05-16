#include <stdio.h>
#include <string>
#include <sstream>

enum Severity 
{
    TRACE,
    DEBUG,
    INFO ,
    WARN ,
    ERROR,
    FATAL,
    NUM_OF_SEVERITIES
};


const char* severityNames[NUM_OF_SEVERITIES] = {"TRACE", "DEBUG" , "INFO" , "WARN", "ERROR" , "FATAL"};


class LogMessage : public std::ostringstream
{

    public:
        LogMessage(Severity severity, const  char *funcName,int lineNumber);
        ~LogMessage();
        void printLogMessage();
    private:
        Severity priv_severity;

        const char *priv_funcName;
        int priv_lineNumber;
        time_t currentTime = time(NULL);

    

};

#define LOG_TRACE LogMessage(TRACE ,__FUNCTION__,__LINE__)
#define LOG_DEBUG LogMessage(DEBUG ,__FUNCTION__,__LINE__)
#define LOG_INFO  LogMessage(INFO,__FUNCTION__, __LINE__)
#define LOG_FATAL LogMessage(FATAL ,__FUNCTION__,__LINE__)
#define LOG(severity) LOG_##severity

// ================= logging.cpp stuff ===================

LogMessage::LogMessage(Severity severity, const  char *funcName, const int lineNumber)
{
    priv_severity = severity;
    priv_funcName = funcName;
    priv_lineNumber = lineNumber;
    


}
void LogMessage::printLogMessage()
{

    fprintf(stderr, "%s\t%s \n\tLine: %i \n\tFunction: %s\n\t%s\n\n" , asctime(localtime(&currentTime)) , severityNames[priv_severity] , priv_lineNumber, priv_funcName, str().c_str());
}

LogMessage::~LogMessage()
{
    if( priv_severity ==  FATAL )
    {
        printLogMessage();
        fprintf(stderr, "%s", "Program Ran Into Fatal Error\n");
        exit(0);
    }
    printLogMessage();
    
}
