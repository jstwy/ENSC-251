# See example: https://www.cs.swarthmore.edu/~newhall/unixhelp/howto_makefiles.html
# the compiler: gcc for C program, define as g++ for C++
CC = g++

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CFLAGS  = -g -Wall

# more specific commands -----------------------------------------------------
# typing 'make' in terminal builds the following files
partA: partA.o Queue.o
	$(CC) partA.o Queue.o -o partA -g
partA.o: partA.cpp Queue.h
	$(CC) partA.cpp -c -g
Queue.o: Queue.cpp Queue.h
	$(CC) Queue.cpp -c -g

# typing 'make clean' in terminal removes all object files previously created
clean:
	$(RM) *.o *~ partA