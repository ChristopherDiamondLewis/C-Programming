/*
*
*   @author - Christopher Lewis
*
*   @compile -  clang++ LoggingDemo.cpp -o main
*
*
*
*
*/

#include <iostream>
#include <ctime>

#define NAME_OF( v ) #v


class Logger
{   
    public:

        Logger();
        void printTime();
        void trace(int tracedVariable);
        void info();

    private:
         time_t currentTime;
    
};


void randomFunc(int &tracedVariable );


int main()
{
    Logger myLogger;
    
    int tracedVariable;


    myLogger.trace(tracedVariable);
    
    randomFunc(tracedVariable); 

    myLogger.trace(tracedVariable);



    return 0;
}

Logger::Logger()
{

    this->currentTime = time(NULL);

}
void Logger::info()
{

    using cout;
    using endl;



}
void Logger::trace(int tracedVariable )
{

    using std::cout;
    using std::endl;

    

    
    this->printTime();
    cout << "\tThe value of " << NAME_OF(tracedVariable) << " is " << tracedVariable << endl;
    



}
void Logger::printTime()
{
    using std::cout;
    using std::endl;

    cout << std::asctime(std::localtime(&this->currentTime));

}

void randomFunc(int &tracedVariable)
{

    using std::cout;
    using std::endl;

    tracedVariable = 200;

    cout << "In function \"" << __FUNCTION__ <<  "\" the value of \"" << NAME_OF(tracedVariable) << "\" is " << tracedVariable << endl;


}