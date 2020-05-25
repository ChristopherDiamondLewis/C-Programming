
#	Compiler Version Information:
#		clang version 6.0.0-1ubuntu2 (tags/RELEASE_600/final)
#		Target: x86_64-pc-linux-gnu
#		Thread model: posix
#		InstalledDir: /usr/bin
#

CC 	   = clang++
CFLAGS = -std=c++17 -Wall -Wextra -Wpedantic

all: Logger.o LoggerDemo.o
	$(CC) $(CFLAGS) Logger.o LoggerDemo.o -o LoggerDemo

Logger.o: Logger.cpp Logger.h
	$(CC) $(CFLAGS) -c Logger.cpp

LoggerDemo.o: LoggerDemo.cpp Logger.h
	$(CC) $(CFLAGS) -c LoggerDemo.cpp

clean:

	rm -f *.o LoggerDemo