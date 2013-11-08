This repository is for my CIS 380 - Professional Practice research assignment.

bst.h is the specification file for a standard binary search tree data
structure.

bst.cpp is its implementation.

rbt.h is the specification file for a red-black tree, which is an augmented
binary search tree that rebalances itself after each insertion and deletion.

rbt.cpp is its implementation.

main.cpp is a client program that instantiates bst and rbt objects, inserts
data, and compares the execution times on each object's search operation.

I would like to pipe the output of main.cpp to an R program, which will create
a scatter plot diagram of the data and display a best-fitted curve. I would then
like to use these graphs on a LaTeX-beamer slideshow that I will present to the
class.

