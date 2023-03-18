CC=g++
CFLAGS= -c -Wall
DIR= -o src/

all: output

output: start.o main.o
	$(CC) start.o src/Main.o -o tic-tac-toe

calculator.o: calculator.cpp
	$(CC) $(CFLAGS) start.cpp -o start.o

add-mine.o: src/add-mine.cpp
	$(CC) $(CFLAGS) src/Main.cpp $(DIR)Main.o

# You can add your codes here
clean: 
	rm -rf *.o calculator
	clear

run:
	./tic-tac-toe