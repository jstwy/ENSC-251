# g++ compiler
CC = g++

# use c++11
CFLAGS  = -std=c++11

lab: lab5.o lab5utils.o TimeFormatMistake.o
	$(CC) $(CFLAGS) -o lab lab5.o lab5utils.o TimeFormatMistake.o
lab5.o: lab5.cpp lab5utils.h TimeFormatMistake.h
	$(CC) $(CFLAGS) -c lab5.cpp
lab5utils.o: lab5utils.cpp lab5utils.h TimeFormatMistake.h
	$(CC) $(CFLAGS) -c lab5utils.cpp
TimeFormatMistake.o: TimeFormatMistake.cpp TimeFormatMistake.h
	$(CC) $(CFLAGS) -c TimeFormatMistake.cpp

# typing 'make clean' in terminal removes all object files previously created
clean:
	$(RM) *.o *~ lab