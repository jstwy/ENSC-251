# See example: https://www.cs.swarthmore.edu/~newhall/unixhelp/howto_makefiles.html
# the compiler: gcc for C program, define as g++ for C++
CC = g++

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CFLAGS  = -g -Wall

# more specific commands -----------------------------------------------------
# typing 'make' in terminal builds the following files
partB: partB.o World.o
	$(CC) partB.o World.o -o partB -g
partB.o: partB.cpp World.h
	$(CC) partB.cpp -c -g
World.o: World.cpp World.h Organism.h Ant.h Doodlebug.h
	$(CC) World.cpp -c -g
Organism.o: Organism.cpp Organism.h World.h
	$(CC) Organism.cpp -c -g
Ant.o: Ant.cpp Ant.h Organism.h World.h
	$(CC) Ant.cpp -c -g
Doodlebug.o: Doodlebug.cpp Doodlebug.h Organism.h World.h
	$(CC) Doodlebug.cpp -c -g

# typing 'make clean' in terminal removes all object files previously created
clean:
	$(RM) *.o *~ partB