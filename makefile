EXEC = PJ1
CC = g++

CFLAGS = -c -Wall 

# 
$(EXEC) : main.o IS.o MS.o QS.o 
	$(CC) -o  $(EXEC) main.o IS.o MS.o QS.o

#
main.o	: main.cpp IS.h MS.h QS.h 
	$(CC) $(CFLAGS) main.cpp

#
IS.o	: IS.cpp IS.h 
	$(CC) $(CFLAGS) IS.cpp 

#
MS.o	: MS.h MS.cpp
	$(CC) $(CFLAGS) MS.cpp 

#
QS.o 	: QS.h QS.cpp 
	$(CC) $(CFLAGS) QS.cpp
  	
