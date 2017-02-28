CC=g++
CFLAG=-ansi -pedantic -Wall -std=c++11
all:	test.cpp
	$(CC) $(CFLAG) test.cpp
main:	test.cpp
	$(CC) $(CFLAG) test.cpp

function:	function.h global.h function.c
	$(CC) $(CFLAG) -c function.c

clean:
	rm -f a.out
	rm -f *.o
	rm -f *~
demo:	all
	./a.out
