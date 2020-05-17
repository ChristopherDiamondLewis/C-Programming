
#ifndef LOGGER_H
#define LOGGER_H
#include <fstream>
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

        void setLevel(Severity severity);
        void trace(const char* message);
        void debug(const char* message);
        void info(const char* message);
        void warn(const char* message);;
        void error(const char* message);
        void fatal(const char* message);
        void close();

    private:
        Severity priv_severityLevel;
        FILE *priv_FilePtr;
        time_t priv_currentTime = time(NULL);
};  // end of Logger class

#endif
