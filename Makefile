CC=g++
CFLAGS= -c -Wall
DIR= -o src/

all: output

output: start.o main.o
	$(CC) start.o src/Main.o -o tic-tac-toe

calculator.o: start.cpp
	$(CC) $(CFLAGS) start.cpp -o start.o

main.o: src/Main.cpp
	$(CC) $(CFLAGS) src/Main.cpp $(DIR)Main.o

# You can add your codes here
clean: 
	find . -name '*.o' -type f -delete
	clear

run:
	./tic-tac-toe