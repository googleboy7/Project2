CC = gcc
CFLAGS = -Wall -pthread

all: main

main: main.o matrix.o file_io.o
	$(CC) $(CFLAGS) -o main main.o matrix.o file_io.o

main.o: main.c matrix.h file_io.h
	$(CC) $(CFLAGS) -c main.c

matrix.o: matrix.c matrix.h
	$(CC) $(CFLAGS) -c matrix.c

file_io.o: file_io.c file_io.h matrix.h
	$(CC) $(CFLAGS) -c file_io.c

clean:
	rm -f *.o main result.txt
