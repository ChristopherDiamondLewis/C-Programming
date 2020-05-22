CC	   =  clang 
CFLAGS =  -Wall -Wextra -Wpedantic


all: main.o LinkedList.o
	$(CC) $(CFLAGS) main.o LinkedList.o -o main

LinkedList.o: LinkedList.c LinkedList.h
	$(CC) $(CFLAGS) -c LinkedList.c

main.o: main.c LinkedList.h
	$(CC) $(CFLAGS) -c main.c

clean:
	rm -f *.o main