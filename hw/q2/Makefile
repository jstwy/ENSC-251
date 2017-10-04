# See example: https://www.cs.swarthmore.edu/~newhall/unixhelp/howto_makefiles.html
# the compiler: gcc for C program, define as g++ for C++
CC = g++

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CFLAGS  = -g -Wall

# typing 'make' in terminal builds the following files
q2: q2.o VectorDouble.o
	$(CC) q2.o VectorDouble.o -o q2 -g
q2.o: q2.cpp VectorDouble.h
	$(CC) q2.cpp -c -g
VectorDouble.o: VectorDouble.cpp VectorDouble.h
	$(CC) VectorDouble.cpp -c -g

# typing 'make clean' in terminal removes all object files previously created
clean:
	$(RM) *.o *~ q2