#ifndef MATRIX_H
#define MATRIX_H
using namespace std;

class Matrix {
    public:
        int** Multiplication(int** first_matrix, int** second_matrix, int first_row, int first_col, int second_row, int second_col);
        int** Transpose(int** matrix, int row, int col);
        int** createMatrix(unsigned int row, unsigned int col);
        void destroyMatrix(int** matrix, unsigned int col);
};



#endif