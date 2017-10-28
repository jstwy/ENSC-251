# See example: https://www.cs.swarthmore.edu/~newhall/unixhelp/howto_makefiles.html
# the compiler: gcc for C program, define as g++ for C++
CC = g++

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CFLAGS  = -g -Wall

# VERY GENERAL COMMANDS (uncomment lines 12-20) ------------------------------
# the build target executable:
#TARGET = FILE #change this to name of main file

#all: $(TARGET)

#$(TARGET): $(TARGET).cpp
#	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).cpp

#clean:
#	$(RM) $(TARGET) 
 
# COMMANDS FOR SEPARATE FILES (uncomment lines 24-29, 32-33) -----------------
# typing 'make' in terminal builds the following files:
#MAIN_PROGRAM: MAIN_PROGRAM.o CLASS.o
#	$(CC) MAIN_PROGRAM.o CLASS.o -o MAIN_PROGRAM -g
#MAIN_PROGRAM.o: MAIN_PROGRAM.cpp CLASS.h
#	$(CC) MAIN_PROGRAM.cpp -c -g
#CLASS.o: CLASS.cpp CLASS.h
#	$(CC) CLASS.cpp -c -g

# typing 'make clean' in terminal removes all object files previously created
#clean:
#	$(RM) *.o *~ MAIN_PROGRAM