CC     = gcc
CFLAGS = -Wall

all:
	make demo

demo: demo.o
	$(CC) -o demo demo.o Stack.o

demo.o: demo.c Stack.o
	$(CC) -c $(CFLAGS) demo.c

Stack.o: Stack.c Stack.h
	$(CC) -c $(CFLAGS) Stack.c


.PHONY: clean
clean:
	/bin/rm -f Stack.o demo.o demo