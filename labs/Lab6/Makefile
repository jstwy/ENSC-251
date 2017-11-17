# g++ compiler
CC = g++

# use c++11
CFLAGS  = -std=c++11

myLib: lab6.o lab6utils.o Book.o
	$(CC) $(CFLAGS) -o myLib lab6.o lab6utils.o Book.o
lab6.o: lab6.cpp lab6utils.h Book.h globalConst.h
	$(CC) $(CFLAGS) -c lab6.cpp
lab6utils.o: lab6utils.cpp Book.h globalConst.h
	$(CC) $(CFLAGS) -c lab6utils.cpp
Book.o: Book.cpp Book.h globalConst.h
	$(CC) $(CFLAGS) -c Book.cpp

# typing 'make clean' in terminal removes all object files previously created
clean:
	$(RM) *.o *~ myLib