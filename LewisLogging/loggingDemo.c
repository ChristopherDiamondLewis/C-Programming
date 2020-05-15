/*
*
*   @author - Christpoher Lewis
*
*   @compile - clang loggingDemo.c -o LoggerDemo
*
*
*
*
*/
#include <stdio.h>
#include <string.h>


int checkArgs(int argc, char *argv[]);
void printUsage();

int main(int argc,  char* argv[])
{


    if( checkArgs(argc, argv) == 1 )
    {
        printf("This is the file name you want to write to %s\n" , argv[1]);


        FILE *outFile = fopen(argv[1] , "w");

        fputs("This should work\n", outFile);

    }
   


    return 0;
}
/*
*
*   Check command line arguments to determine if write output to a file or terminal/console.
*
*   - if writing to a file usage is "./LoggerDemo {outputFileName}.txt"
*   - if not writing to a file usage is "./LoggerDemo"
*
*/
int checkArgs(int argc, char *argv[])
{

    if (argc > 2)
    {
        printf("Error Incorrect Usage\n");
        printUsage();
        return -1;
    }


    int fileFlag = 0;

    if ( argc == 2 )
    {
        unsigned int ext = strlen(argv[1]) - 4;
        
    
        if ( argv[1][ext]  == '.' )
        {
            if (argv[1][ext + 1] == 't')
            {
                 if (argv[1][ext + 2] == 'x')
                {
                    if (argv[1][ext + 3] == 't')
                    {
                        fileFlag = 1;
                    }
                }

            }

        }
    }
    
    return fileFlag;

}
void printUsage()
{
    printf("Correct Usage for writing to terminal: ./LoggerDemo\n");
    printf("Correct Usage for writing to a file: ./LoggerDemo {outputFileName}.txt\n");

}