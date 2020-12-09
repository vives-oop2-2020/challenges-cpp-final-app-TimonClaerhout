# The compiler to use
CC=g++

# Compiler flags
CFLAGS=-c -Wall
    # -c: Compile or assemble the source files, but do not link.
    # The linking stage simply is not done.
    # The ultimate output is in the form of an object file
    # for each source file.
    #
    # -Wall: This enables all the warnings about constructions that
    # some users consider questionable, and that are easy to avoid
    # (or modify to prevent the warning), even in conjunction with macros.

# Name of executable output
EXECUTABLE=snake

all: $(EXECUTABLE)

# The executable depends on all the separate object files
$(EXECUTABLE): main.o controller.o canvas.o snake.o wall.o fruit.o entity.o game.o tail.o
	$(CC) main.o controller.o canvas.o snake.o wall.o fruit.o entity.o game.o tail.o -o $(EXECUTABLE)

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

canvas.o: src/canvas.cpp
	$(CC) $(CFLAGS) src/canvas.cpp

controller.o: src/controller.cpp
	$(CC) $(CFLAGS) src/controller.cpp

snake.o: src/snake.cpp
	$(CC) $(CFLAGS) src/snake.cpp

wall.o: src/wall.cpp
	$(CC) $(CFLAGS) src/wall.cpp

fruit.o: src/fruit.cpp
	$(CC) $(CFLAGS) src/fruit.cpp

entity.o: src/entity.cpp
	$(CC) $(CFLAGS) src/entity.cpp

game.o: src/game.cpp
	$(CC) $(CFLAGS) src/game.cpp

tail.o: src/tail.cpp
	$(CC) $(CFLAGS) src/tail.cpp

clean:
	rm -f *.o $(EXECUTABLE)