Build instructions
- To create executable/compile, run "make" (without quotes)
- To run executable, "./Tjahyadi-Hansel-Test" (without quotes)
- To clear executable, run "make clean" (without quotes)

About the files
- Tjahyadi-Hansel.h:
  - Contains the declaration for functions in Tjahyadi-Hansel.cpp

- Tjahyadi-Hansel.cpp
  - Contains function implementation for the library
  - DestroyMatrix(matrix, column): destructor for matrix
  - CreateMatrix(row, column): creates a 2D array (matrix) dynamically, returns newly created matrix
  - MultiplyHelper(first_matrix, second_matrix, result, first matrix row, first matrix column, second matrix row, second matrix column): helper function for multiplication, stores answer in result array
  - Multiplication(first_matrix, second_matrix, first matrix row, first matrix column, second matrix row, second matrix column): main driver for multiplication, returns multiplied matrix if successful, returns nullptr if first col != second row
  - Transpose(matrix, row, column): main driver for transpose, returns transposed matrix

- Tjahyadi-Hansel-Test.cpp
  - Contains all the test cases for the library
  - PrintMatrix(matrix, row, col): prints out the contents of the matrix with proper dimensions
  - MatrixEquals(first matrix, second matrix, row, col): checks for matrix equality, assuming the same size
  - TestMultiplication1 - checks correctness for matrix multiplication for matrices with MXN and NXL dimensions, output should be MXL matrix. Compares result to an matrix with expected results.
  - TestMultiplication2 - checks correctness for matrix multiplication for square matrices. Comparesresult to an matrix with expected results.
  - TestMultiplication3 - checks correctness for matrix multiplication for MXN and AXB dimensions (notice how first col != second row). Expected to return true if matrix is null.
  - TestTranspose1 - checks correctness for MXN and NXM matrices, depending on the random number generator. Checks correctness with the transpose property (A^T)^T == A. Contents of matrix are randomized each time.
  - TestTranspose2 - checks correctness for square matrices. Checks correctness with the transpose property (A^T)^T == A. Contents of matrix are randomized each time.

- Makefile
  - Compiles source code with C++11 (g++ -Wall -pedantic -g -O0 -std=c++11 -o Tjahyadi-Hansel-Test Tjahyadi-Hansel-Test.cpp Tjahyadi-Hansel.cpp)


Test cases (for multiplication, because transpose is randomized each time):
- TestMultiplication1:
  - First matrix: 2 5 7 
                  6 5 4

  - Second matrix: 3 4
                   5 6
                   7 8
  
  - Expected result: 80 94
                     71 86
                  
- TestMultiplication2:
  - First matrix: 15 8 12 
                  7 16 12
                  9 10 12

  - Second matrix: 13 4 12 
                   15 6 12
                   9 10 12
  
  - Expected result: 423 228 420 
                     439 244 420
                     375 216 372

- TestMultiplication3:
  - First matrix: 2 5 7 
                  6 5 4

  - Second matrix: 13 4
                   15 6
  
  - Expected result: Multiplication not possible


          