This repository is for my CIS 380 - Professional Practice research assignment.

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Compiled on:	Ubuntu 12.04

Compilation Instructions:
	makefile enables the user of this program to compile it from the terminal
	by typing:

		make

	This creates an executable file, BSTvRBT.  In addition, makefile enables
	the user of this program to compile the .cpp files individually by typing:

		make main.o
		make bst.o
		make rbt.o

	Furthermore, if the user so wishes, makefile allows for the removal of all
	files named *.o, *~, or BSTvRBT by typing:

		make clean

	Also, the user can create a tar file containing the source code and this
	README by typing:

		make tar

	If future modifications to this project require additional source code
	files, appropriate entries should be added to makefile.  If additional
	executable files are needed, the names of these files should also be added
	to the dependencies list of the makefile entry whose target is 'all'. Then,
	each executable file can be created by typing:

		make all

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Source Code Files:
	bst.h is the specification file for a standard binary search tree data
	structure.

	bst.cpp is its implementation.

	rbt.h is the specification file for a red-black tree, which is an augmented
	binary search tree that rebalances itself after each insertion and deletion.

	rbt.cpp is its implementation.

	main.cpp is a client program that instantiates bst and rbt objects, inserts
	data, and compares the execution times on each object's search operation

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Notes:
	I would like to pipe the output of main.cpp to an R program, which will
	create a scatter plot diagram of the data and display a best-fitted curve.
	I would then like to use these graphs on a LaTeX-beamer slideshow that I
	will present to the class.

