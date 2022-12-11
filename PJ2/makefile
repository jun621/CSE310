
EXEC = PJ2
CC = g++
CFLAGS = -c -Wall
#
$(EXEC) :main.o util.o heap.o
		$(CC) -o $(EXEC) main.o util.o heap.o
#
main.o :main.cpp util.h heap.h
		$(CC) $(CFLAGS) main.cpp
#
util.o :util.cpp util.h
		$(CC) $(CFLAGS) util.cpp
#
heap.o :heap.cpp heap.h
		$(CC) $(CFLAGS) heap.cpp
#