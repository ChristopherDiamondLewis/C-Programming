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
        std::string priv_message;
        time_t currentTime = time(NULL);

    

};

// Logging Macros...

#define LOG_TRACE LogMessage(TRACE ,__FUNCTION__,__LINE__)
#define LOG_DEBUG LogMessage(DEBUG ,__FUNCTION__,__LINE__)
#define LOG_INFO  LogMessage(INFO,__FUNCTION__, __LINE__)
#define LOG_WARN  LogMessage(INFO,__FUNCTION__, __LINE__)
#define LOG_ERROR LogMessage(INFO,__FUNCTION__, __LINE__)
#define LOG_FATAL LogMessage(FATAL ,__FUNCTION__,__LINE__)

#define LOG(severity) LOG_##severity

#define NAME_OF(v) #v


// ================= logging.cpp stuff ===================

LogMessage::LogMessage(Severity severity, const  char *funcName, const int lineNumber)
{
    priv_severity   = severity;
    priv_funcName   = funcName;
    priv_lineNumber = lineNumber;
}
void LogMessage::printLogMessage()
{

    fprintf(stderr, "%s\t\tLine: %i \n\tFunction: %s\n\t%s\n\n" , asctime(localtime(&currentTime)) ,                                                                         
                                                                       priv_lineNumber, priv_funcName, 
                                                                       priv_message.c_str());
}

LogMessage::~LogMessage()
{
    switch(priv_severity)
    {
            case TRACE: priv_message = "This is a TRACE message\n";     break;
            case DEBUG: priv_message = "This is a DEBUG message\n";    break;
            case INFO:  priv_message = "This is a INFO  message\n";     break;
            case WARN:  priv_message = "This is a WARN  message\n";     break;
            case ERROR: priv_message = "This is a ERROR message\n";     break;
            case FATAL: priv_message = "This is a FATAL message\n";     break;



    }

    printLogMessage();
    
}

