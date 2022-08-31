CXX = g++

CFLAGS = --std=c++11 -g

all: game

utility.o: utility.cpp
	${CXX} -c ${CFLAGS} utility.cpp

cards.o: cards.cpp
	${CXX} -c ${CFLAGS} cards.cpp

game: main.o utility.o cards.o
	${CXX} ${CFLAGS} -o game main.o utility.o cards.o

main.o: main.cpp
	${CXX} -c ${CFLAGS} main.cpp

test: test.o utility.o cards.o
	${CXX} ${CFLAGS} -o test test.o utility.o cards.o

test.o: test.cpp
	${CXX} -c ${CFLAGS} test.cpp

clean: 
	/bin/rm -f *.o

