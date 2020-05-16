#include <stdio.h>
#include <string>

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


std::string severityNames[NUM_OF_SEVERITIES] = {"TRACE", "DEBUG" , "INFO" , "WARN", "ERROR" , "FATAL"};


class LogMessage
{

    public:
        LogMessage(Severity severity, const  char *funcName,int lineNumber);
        ~LogMessage();
        void printLogMessage();
    private:
        Severity priv_severity;
        const char *priv_message;
        const char *priv_funcName;
        int priv_lineNumber;
        time_t currentTime = time(NULL);

    

};

#define LOG_INFO LogMessage(INFO,__FUNCTION__, __LINE__)




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

    fprintf(stderr, "%s: %s %i %s\n\n" , asctime(localtime(&currentTime)) , severityNames[priv_severity].c_str() , priv_lineNumber, priv_funcName);


}

LogMessage::~LogMessage()
{

    printLogMessage();


}
