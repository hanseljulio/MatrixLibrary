#include "Matrix.h"
#include <iostream>
#include <array>
using namespace std;

void Matrix::destroyMatrix(int** matrix, unsigned int col) {
    for (unsigned int i = 0; i < col; i++) {
        delete[] matrix[i];
    }

    delete[] matrix;
    matrix = 0;
}

int** Matrix::createMatrix(unsigned int row, unsigned int col) {
    int** matrix = new int*[row];

    for (unsigned int i = 0; i < row; i++) {
        matrix[i] = new int[col];
    }

    return matrix;
}

void MultiplyHelper(int** first_matrix, int** second_matrix, int** result, int first_row, int first_col, int second_row, int second_col) {
    for (int i = 0; i < first_row; i++) {
        for (int j = 0; j < second_col; j++) {
                *(*(result + i) + j) = 0;
            for (int k = 0; k < second_row; k++) {
                *(*(result + i) + j) += *(*(first_matrix + i) + k) * *(*(second_matrix + k) + j);
            }
        }
    }
}

int** Matrix::Multiplication(int** first_matrix, int** second_matrix, int first_row, int first_col, int second_row, int second_col) {
    if (first_col != second_row) {
        return nullptr;
    }
    
    int** result = createMatrix(first_row, second_col);

    MultiplyHelper(first_matrix, second_matrix, result, first_row, first_col, second_row, second_col);

    return result;
}

int** Matrix::Transpose(int** matrix, int row, int col) {
    if (row == 1 && col == 1) {
        return matrix;
    }

    int** transposed_matrix = createMatrix(col, row);

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            *(*(transposed_matrix + j) + i) = *(*(matrix + i) + j);
        }
    }

    return transposed_matrix;
}