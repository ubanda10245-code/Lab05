# This is a comment line
CC=g++
# CFLAGS will be the options passed to the compiler.
CFLAGS= -c -Wall

all: prog

prog: salesReport.o
	$(CC) salesReport.o -o prog

salesReport.o: salesReport.c
	$(CC) $(CFLAGS) salesReport.c

clean:
	rm -rf *.o prog