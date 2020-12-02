CC = gcc
CFLAGS = -Wall

all: conway.o board.o
	$(CC) $(CFLAGS) -o conway.out conway.o board.o

conway.o: conway.c board.h
	$(CC) $(CFLAGS) -c conway.c

board.o: board.c board.h
	$(CC) $(CFLAGS) -c board.c

clean: 
	rm *.o conway.out
