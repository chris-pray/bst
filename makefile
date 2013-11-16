OBJS = main.o bst.o rbt.o
OBJS_BST_TEST = bst_test.o bst.o
OBJS_RBT_TEST = rbt_test.o bst.o rbt.o
CC = g++
DEBUG = -g
CFLAGS = -std=c++0x -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)


BSTvRBT: $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o BSTvRBT
	
BST_TEST: $(OBJS_BST_TEST)
	$(CC) $(LFLAGS) $(OBJS_BST_TEST) -o BST_TEST
	
RBT_TEST: $(OBJS_BST_TEST)
	$(CC) $(LFLAGS) $(OBJS_BST_TEST) -o RBT_TEST
	
bst_test.o: bst.h
	$(CC) $(CFLAGS) bst_test.cpp
	
rbt_test.o: bst.h rbt.h
	$(CC) $(CFLAGS) rbt_test.cpp

main.o: bst.h rbt.h
	$(CC) $(CFLAGS) main.cpp

bst.o: bst.h bst.cpp exceptions.h
	$(CC) $(CFLAGS) bst.cpp

rbt.o: rbt.h rbt.cpp bst.h exceptions.h
	$(CC) $(CFLAGS) rbt.cpp

clean:
	\rm *.o *~ BSTvRBT BST_TEST RBT_TEST

tar:
	tar cfv BSTvRBT.tar main.cpp bst.h bst.cpp rbt.h rbt.cpp exceptions.h bst_test.cpp rbt_test.cpp README.md makefile

all: BSTvRBT BST_TEST RBT_TEST
