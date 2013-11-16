AUTHOR:	Chris Pray

This repository is for my CIS 380 - Professional Practice research assignment.

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Compiled on:	Ubuntu 12.04

Compilation Instructions:

	makefile enables the user of this program to compile all dependencies from
	the terminal and create an executable, named BSTvRBT, by typing:

		make

	In addition, makefile enables the user of this program to compile the .cpp
	files individually by typing: (Note: order of compilation matters)

		make <name>.o

	Furthermore, if the user so wishes, makefile allows for the removal of all
	binary, backup, and executable files by typing:

		make clean

	Also, the user can create a tar file containing all source code, the
	makefile, and this README by typing:

		make tar
		
	To compile all files and create all executables, including test files, type:

		make all

	If future modifications to this project require additional source code
	files, appropriate entries should be added to makefile.  If additional
	executable files are needed, the names of these files should also be added
	to the dependencies list of the makefile entry whose target is 'all'.

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Source Code Files:

	bst.h is the specification file for a standard binary search tree data
	structure.

	bst.cpp is its implementation.

	rbt.h is the specification file for a red-black tree, which is an augmented
	binary search tree that rebalances itself after each insertion and deletion.

	rbt.cpp is its implementation.

	main.cpp is a client program that instantiates bst and rbt objects, inserts
	data, and compares the execution times on each object's search operation.
	
	exceptions.h contains customized exceptions used in this project.
	
	bst_test.cpp is the test file for the BST class.
	
	rbt_test.cpp is the test file for the RBT class.

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Notes:

	I would like to pipe the output of main.cpp to an R program, which will
	create a scatter plot diagram of the data and display a best-fitted curve.
	I would then like to use these graphs on a LaTeX-beamer slideshow that I
	will present to the class.

