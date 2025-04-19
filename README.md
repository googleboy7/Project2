# CS 540 Project 2: Multithreaded Matrix Multiplication

## Matrix Storage Design
Matrices are stored using a dynamic 2D array, wrapped in a `Matrix` struct with row and column metadata.

## Work of Each Thread
Each thread computes one element `(i, j)` of the result matrix by calculating the dot product of row `i` from matrix A and column `j` from matrix B.

## Critical Sections and Synchronization
No synchronization is required because each thread writes to a unique element in the result matrix. No shared resources are accessed concurrently.


1. You will need to open a folder with all the files in the bash terminal. There needs to 2 different matrices to be executed properly.

2. In the bash terminal, run 'make'.

3. Next, run './main' in the terminal.

4. The results should be ouputted to the result.txt file.