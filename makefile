OBJS = main.o bst.o rbt.o
CC = g++
DEBUG = -g
CFLAGS = -std=c++0x -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)


BSTvRBT: $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o BSTvRBT

main.o: bst.h rbt.h
	$(CC) $(CFLAGS) main.cpp

bst.o: bst.h bst.cpp exceptions.h
	$(CC) $(CFLAGS) bst.cpp

rbt.o: rbt.h rbt.cpp bst.h exceptions.h
	$(CC) $(CFLAGS) rbt.cpp

clean:
	\rm *.o *~ BSTvRBT

tar:
	tar cfv BSTvRBT.tar main.cpp bst.h bst.cpp rbt.h rbt.cpp exceptions.h README.md

all: BSTvRBT