/*
 * 
 * 	@author - Christopher Lewis 
 * 
 * 	@purpose - Meant to be project 4 for Operating Systems class.
 * 				This code is meant to represent the bakery threading 
 * 				algortihm for mutual exclusion on 'n' number of threads.
 * 
 *  @source - en.wikipedia.org/wiki/Lamport%27s_bakery_algorithm
 *  
 *  @compile - gcc -Wall -pedantic -pthread -o bakery bakery.c
 * 
 * 
 *  
 * 
 * 
 * */


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <pthread.h>
#include <time.h>
#include <stdbool.h>


#define THD_MAX 256
#define THD_MIN 2

bool *entering;			// pointer for bool array.



int  *tickets ;			// pointer for integer array.


int  resource;
int  threadCount;


void lock(int thdID);
void unlock(int thdID);
void useResource(int thdID);
void *thdFunction(void* i);


int getThreadCount(int argc, char* argv[]);


int main(int argc, char* argv[])
{
	
	
	if (getThreadCount(argc, argv) != -1) // Argument validation...
	{
		// Dynamically allocate our arrays & initialize globals...
		
		
		resource = -1;
		
		tickets =  (int*) malloc(threadCount  * sizeof(int));
		entering = (bool*) malloc(threadCount * sizeof(bool));
		
		for ( int i = 0 ; i < threadCount ; i++)
		{
			tickets[i] = 0 ;
			entering[i] = false;
		}
		
		// Create threads array...
		
		pthread_t threads[threadCount];
		
		for ( int i = 0 ; i < threadCount ; i++ )
		{
			//printf("Creating thread number %d...\n" , i + 1);
			pthread_create(&threads[i],NULL, &thdFunction, (void*)((long)i));
			
		}
		
		
		// Wait for each thread to finish...
		
		for ( int i = 0 ; i < threadCount ; i++ )
		{
			//printf("Thread %d is currently in pthread_join loop...\n" , (i + 1));
			pthread_join(threads[i] , NULL);
		}
		
		 printf("\033[0;32mAll threads have finished!\033[0m\n");
		
		 // free our memory...
		
		 free(entering);	// freeing the memory yeilds undefined behavior
		 free(tickets);
		
	}
	
	
	
	return 0;
}
int getThreadCount(int argc, char* argv[])
{
		
	if ( argc != 2 )
	{
		printf("Error must provide thread count\n");
		printf("Usage: ./bakery [THREADCOUNT] \n");
		return -1;
	}
	
	threadCount = atoi(argv[1]);	// convert thdCnt given to int...
	
	
	if ( threadCount < THD_MIN || threadCount > THD_MAX )
	{
		printf("Error, %d is an invalid threadCount.\n" , threadCount);
		return -1;
	}

	
	return threadCount;
}
void *thdFunction(void* i )
{

	int thdID = (int)i;
	
	
	
	lock(thdID);
	useResource(thdID);
	unlock(thdID);
	
	
	
	return NULL;
	
		
}
void lock(int thread)
{
	
	entering[thread] = true;
	
	int max_ticket = 0;
	
	
	
	for ( int i = 0; i < threadCount; i++ )
	{
		int ticket = tickets[i];
		max_ticket = ticket > max_ticket ? ticket : max_ticket;
		
	}
	
	tickets[thread] =  max_ticket + 1;
	entering[thread] = false;
	
	
	for ( int other = 0; other < threadCount; ++other )
	{
		while(entering[other])
		{
		
			// do nothing...
		}
		
		// wait until all threads with smaller numbers or with the 
		// same number but higher priority finish.
		
		while ( ((tickets[other] != 0) && (tickets[other] < tickets[thread])) ||
			  (tickets[other] == tickets[thread] && other < thread ))
		{
			// do nothing...
		}
	}
	
	printf("Thread %d is locking...\n", thread + 1);

	
}
void useResource(int i)
{
	srand(time(0));
	
	if ( resource != -1 )
	{
		printf("Resource acquired by current thread %d but is still" , i);
		printf(" in use by %d\n" , resource);
		printf("Terminating program...\n");
		exit(0);
	}
	
	resource = i;
	
	printf("\033[0;31mThread %d is using resource...\033[0m\n" , i + 1);
	
	usleep(rand() % 1000000);	
	
	resource = -1;
		
}		
void unlock(int i)
{	
	
	printf("Thread %d is unlocking...\n", (i + 1));
	
	tickets[i] = 0;
}	
		
		
	
	
	
	
	
	
