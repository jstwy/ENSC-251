# See example: https://www.cs.swarthmore.edu/~newhall/unixhelp/howto_makefiles.html
# the compiler: gcc for C program, define as g++ for C++
CC = g++

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CFLAGS  = -g -Wall

# very general commands ------------------------------------------------------
# the build target executable:
TARGET = FILE

all: $(TARGET)

$(TARGET): $(TARGET).cpp
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).cpp

clean:
	$(RM) $(TARGET) 
 
# more specific commands -----------------------------------------------------
# typing 'make' in terminal builds the following files
#MAIN: MAIN.o CLASS.o
#	$(CC) MAIN.o CLASS.o -o MAIN -g
#MAIN.o: MAIN.cpp CLASS.h
#	$(CC) MAIN.cpp -c -g
#CLASS.o: CLASS.cpp CLASS.h
#	$(CC) CLASS.cpp -c -g

# typing 'make clean' in terminal removes all object files previously created
#clean:
#	$(RM) *.o *~ MAIN