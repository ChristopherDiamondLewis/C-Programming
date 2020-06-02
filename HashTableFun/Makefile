
CC 	   = clang 
CFLAGS = -Wall -Wextra -pedantic 


all: main.o HashTable.o
	$(CC) $(CFLAGS)	main.o HashTable.o -o main

HashTable.o: HashTable.c HashTable.h
	$(CC) $(CFLAGS) -c HashTable.c

main.o: main.c HashTable.h 
	$(CC) $(CFLAGS) -c main.c


clean:
	rm -f *.o main