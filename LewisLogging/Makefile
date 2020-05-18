


all: Logger.o LoggerDemo.o
	clang++ Logger.o LoggerDemo.o -o LoggerDemo

Logger.o: Logger.cpp Logger.h
	clang++ -c Logger.cpp

LoggerDemo.o: LoggerDemo.cpp Logger.h
	clang++ -c LoggerDemo.cpp

clean:

	rm -f *.o LoggerDemo