/*
 * @author - Christopher Lewis
 * 
 * @notes - Purpose of this program is for practicing the concept
 * 			 of semaphores in an operating system that must allocate
 * 			 a shared resource to one process/thread at a time.
 * 
 * 
 * @reference(s) - https://en.wikipedia.org/wiki/Semaphore_(programming)
 * 		
 * 				 - https://drive.google.com/file/d/1kTAQzhYg28bjm7pOs6yCXe93UAfhpFKn/view?usp=sharing
 * 
 * 
 * @compile: gcc -Wall -pedantic -pthread -o hungryStudents hungryStudents.c
 * 
 * 
 * 
 * */
 
 
 #include <stdio.h>
 #include <stdlib.h>
 #include <unistd.h>
 #include <signal.h>
 #include <pthread.h>
 #include <semaphore.h>
 #include <time.h>
 #include <stdbool.h>
 

#define REFILL_SIZE 5
#define MAX_REFILLS 5


// our global variables, define by the assignment PDF...

unsigned int currentPotServings = 0;
unsigned int currentPotRefills  = 0;

// our global semaphores...

sem_t studentMutex;
sem_t emptyPot; 
sem_t fullPot;	

// our functions...

int checkArgs(int argc, char* argv[]);

void putServingsInPot();
void studentEats(int studentNumber);
void getServingFromPot();


// thread specific functions...

void* RA(void *threadID);
void* hungryStudents(void *threadID);

 
 int main(int argc , char* argv[])
 {
	 int studentCount;
	 
	 if(!checkArgs(argc, argv))	// Argument validation...
	 {
		
		studentCount = atoi(argv[1]);	// Arugments good, get studentCount...
		
		// Make our arrays and initlaize our semaphores accordingly...
		
		pthread_t threads[studentCount];	// thread array for students...
		pthread_t ra_thread;				// single thrad for RA...
		
		
		sem_init(&studentMutex,0,1);
		sem_init(&emptyPot,0,0);
		sem_init(&fullPot,0,0);
		
		
		// create our RA thread as well as student threads...
		
		pthread_create(&ra_thread, NULL, &RA, NULL );
		
		for ( int i = 0 ; i < studentCount ; i++ )
		{
		
			pthread_create(&threads[i],NULL, &hungryStudents, (void*)((long)i));
				
		}
		
		// wait for all student threads & the RA thread to finish...
		
		for ( int i = 0 ; i < studentCount; i++ )
		{
			//printf("Thread %d is currently in pthread_join loop...\n" , (i + 1));
			pthread_join(threads[i] , NULL);
		}
		
		pthread_join(ra_thread,NULL);
			
		
		printf("All students have eating, game over , thank you for playing :) \n");
		
	 }

	 return 0;
}
void* RA(void *threadID)
{
	while(true && currentPotRefills < MAX_REFILLS )
	{
			
		sem_wait(&emptyPot);
		putServingsInPot();
		sem_post(&fullPot);
		
		
	}
		
	//printf("RA thread is exiting...\n");
	pthread_exit(threadID);
	
	
	return NULL;
	
}
void putServingsInPot()
{
	
	srand(time(0));
	
	currentPotServings =  REFILL_SIZE;
	currentPotRefills++;
	
	printf("\033[0;31mOK, fine, here are more Ramen Noodles(5)..\033[0m\n");
	
	
	if ( currentPotRefills ==  MAX_REFILLS )
	{
		printf("\033[0;31mHey, this is the last of the Ramen Noodles..\033[0m\n");
	}
	
	usleep(rand() % 500000);
	
	
}
	
void* hungryStudents(void *threadID)
{
	
	int studentNumber = (int)threadID;
	
	
	while(true)
	{
		
		
		sem_wait(&studentMutex);
		
		
		
		if ( currentPotServings == 0 && currentPotRefills != MAX_REFILLS )
		{
			
			sem_post(&emptyPot);
			sem_wait(&fullPot);
		}
		
		if ( currentPotServings == 0 && currentPotRefills == MAX_REFILLS )
		{
			//printf("Reaching this?\n");
			sem_post(&studentMutex);
			break;
		}
		
		getServingFromPot();
		
		
		
		sem_post(&studentMutex);
		
		studentEats(studentNumber);
		
			
	}
	
	
	
	
	return NULL;
}
void studentEats(int studentNumber)
{
	srand(time(0));
	
	printf("\033[0;32mStudent %d eating, yum..\033[0m\n", studentNumber + 1);
	
	 if ( currentPotRefills >= MAX_REFILLS && currentPotServings == 0)
	    {
				
				//printf("Student %d exiting...\n", studentNumber + 1 );
				pthread_exit((void*)studentNumber);
				
				
		}
	
	usleep(rand() % 1000000);
	
}
void getServingFromPot()
{
	
	srand(time(0));
	
	currentPotServings--;
	
	
	usleep(rand() % 1000);
}
int checkArgs(int argc, char* argv[])
{
	
	int studentCount;
	
	if ( argc != 2 )
	{
		printf("Error incorrect arguments\n");
		printf("Usage: ./hungryStudents [3-20]\n");
		return -1;
	}
	
	studentCount = atoi(argv[1]);
	
	
	if ( studentCount < 3 || studentCount > 20 )
	{
		printf("Error incorrect amount of students\n");
		printf("Usage: ./hungryStudents [3-20]\n");
		return -1;
	}
	
	
	return 0;
	
}

