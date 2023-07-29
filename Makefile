# Compiler
CC = g++

# Compilation options
CFLAGS = -std=c++11 -Wall

# Linking options
LDFLAGS = -L. -lFileSearch

# Default target
all: main

# Building the main application
main: main.o libFileSearch.a
	$(CC) $(CFLAGS) -o main main.o $(LDFLAGS)

# Building the object file for the main application
main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

# Creating the static library libFileSearch.a
libFileSearch.a: FileSearch.o
	ar rcs libFileSearch.a FileSearch.o

# Building the object file for the library
FileSearch.o: FileSearch.cpp FileSearch.h
	$(CC) $(CFLAGS) -c FileSearch.cpp

# Clean
clean:
	rm -f *.o *.a main