#include "Matrix.h"
#include <iostream>
#include <functional>
#include <time.h>
#include <string>
using namespace std;

#define MESSAGE_SUCCESS "All tests passed"
#define MESSAGE_MULTIPLICATION1_SUCESS "Multiplication test 1 passed"
#define MESSAGE_MULTIPLICATION1_FAIL "Multiplication test 1 failed"
#define MESSAGE_MULTIPLICATION2_SUCESS "Multiplication test 2 passed"
#define MESSAGE_MULTIPLICATION2_FAIL "Multiplication test 2 failed"
#define MESSAGE_MULTIPLICATION3_SUCESS "Multiplication test 3 passed"
#define MESSAGE_MULTIPLICATION3_FAIL "Multiplication test 3 failed"
#define MESSAGE_TRANSPOSE1_SUCCESS "Transpose test 1 passed - the transpose of the transpose is the original matrix (A^T)^T == A"
#define MESSAGE_TRANSPOSE1_FAIL "Transpose 1 failed - the transpose of the transpose is not the original matrix (A^T)^T != A"
#define MESSAGE_TRANSPOSE2_SUCCESS "Transpose test 2 passed - the transpose of the transpose is the original matrix (A^T)^T == A"
#define MESSAGE_TRANSPOSE2_FAIL "Transpose 2 failed - the transpose of the transpose is not the original matrix (A^T)^T != A"

// PrintMatrix(matrix, row of input matrix, col of input matrix);
void PrintMatrix(int** matrix, int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << " " << *(*(matrix + i) + j);
        }
        cout << endl;
    }
}

// Checks equality, assuming the same dimension
bool MatrixEquals(int** firstMatrix, int** secondMatrix, unsigned int row, unsigned int col) {
    for (unsigned int i = 0; i < row; i++) {
        for (unsigned int j = 0; j < col; j++) {
            if (firstMatrix[i][j] != secondMatrix[i][j]) {
                return false;
            }
        }
    }

    return true;
}

// MXN * NXL matrix - should return true (0)
int TestMultiplication1(Matrix mtx, int** expected_matrix) {
    int** firstMatrix = mtx.createMatrix(2, 3);
    int** secondMatrix = mtx.createMatrix(3, 2);

    firstMatrix[0][0] = 2;
    firstMatrix[0][1] = 5;
    firstMatrix[0][2] = 7;
    firstMatrix[1][0] = 6;
    firstMatrix[1][1] = 5;
    firstMatrix[1][2] = 4;

    secondMatrix[0][0] = 3;
    secondMatrix[0][1] = 4;
    secondMatrix[1][0] = 5;
    secondMatrix[1][1] = 6;
    secondMatrix[2][0] = 7;
    secondMatrix[2][1] = 8;

    int** result = mtx.Multiplication(firstMatrix, secondMatrix, 2, 3, 3, 2);

    if (!(MatrixEquals(expected_matrix, result, 2, 2))) {
        // mtx.destroyMatrix(firstMatrix, 3);
        // mtx.destroyMatrix(secondMatrix, 2);
        // mtx.destroyMatrix(result, 2);
        return 1;
    }

    return 0;
}

// MXN * MXN matrix - should return true (0)
int TestMultiplication2(Matrix mtx, int** expected_matrix) {
    int** firstMatrix = mtx.createMatrix(3, 3);
    int** secondMatrix = mtx.createMatrix(3, 3);

    firstMatrix[0][0] = 15;
    firstMatrix[0][1] = 8;
    firstMatrix[0][2] = 12;
    firstMatrix[1][0] = 7;
    firstMatrix[1][1] = 16;
    firstMatrix[1][2] = 12;
    firstMatrix[2][0] = 9;
    firstMatrix[2][1] = 10;
    firstMatrix[2][2] = 12;

    secondMatrix[0][0] = 13;
    secondMatrix[0][1] = 4;
    secondMatrix[0][2] = 12;
    secondMatrix[1][0] = 15;
    secondMatrix[1][1] = 6;
    secondMatrix[1][2] = 12;
    secondMatrix[2][0] = 9;
    secondMatrix[2][1] = 10;
    secondMatrix[2][2] = 12;

    int** result = mtx.Multiplication(firstMatrix, secondMatrix, 3, 3, 3, 3);

    if (!(MatrixEquals(expected_matrix, result, 3, 3))) {
        return 1;
    }

    return 0;
}

// MXN * MXN - Should fail - return 1
int TestMultiplication3(Matrix mtx) {
    int** firstMatrix = mtx.createMatrix(2, 3);
    int** secondMatrix = mtx.createMatrix(2, 2);

    firstMatrix[0][0] = 2;
    firstMatrix[0][1] = 5;
    firstMatrix[0][2] = 7;
    firstMatrix[1][0] = 6;
    firstMatrix[1][1] = 5;
    firstMatrix[1][2] = 4;

    secondMatrix[0][0] = 13;
    secondMatrix[0][1] = 4;
    secondMatrix[1][0] = 15;
    secondMatrix[1][1] = 6;

    if (mtx.Multiplication(firstMatrix, secondMatrix, 2, 3, 2, 2) == nullptr) {
        return 0;
    }

    return 1;
}

// MXN or NXM matrix transpose (depends on the random generator)
int TestTranspose1(Matrix mtx) {
    int transpose_row = (rand() % 10) + 1;
    int transpose_col = (rand() % 10) + 1;

    int** matrix = mtx.createMatrix(transpose_row, transpose_col);

    for (int i = 0; i < transpose_row; i++) {
        for (int j = 0; j < transpose_col; j++) {
            matrix[i][j] = (rand() % 10) + 1;
        }
    }

    int** transposed_matrix = mtx.Transpose(matrix, transpose_row, transpose_col);

    // PrintMatrix(matrix, transpose_row, transpose_col);
    // cout << endl;
    // PrintMatrix(transposed_matrix, transpose_col, transpose_row);
    // cout << endl;
    // PrintMatrix(mtx.Transpose(transposed_matrix, transpose_col, transpose_row), transpose_row, transpose_col);

    if (!MatrixEquals(matrix, mtx.Transpose(transposed_matrix, transpose_col, transpose_row), transpose_row, transpose_col)) {
        return 1;
    }

    return 0;
}

// Square matrix transpose
int TestTranspose2(Matrix mtx) {
    int transpose_row = (rand() % 10) + 1;
    int transpose_col = transpose_row;

    int** matrix = mtx.createMatrix(transpose_row, transpose_col);

    for (int i = 0; i < transpose_row; i++) {
        for (int j = 0; j < transpose_col; j++) {
            matrix[i][j] = (rand() % 10) + 1;
        }
    }

    int** transposed_matrix = mtx.Transpose(matrix, transpose_row, transpose_col);

    if (!MatrixEquals(matrix, mtx.Transpose(transposed_matrix, transpose_col, transpose_row), transpose_row, transpose_col)) {
        return 1;
    }

    return 0;
}

int main() {
    srand(time(0));

    Matrix mtx;

    int** expected_matrix_mxn_nxl = mtx.createMatrix(2, 3);
    expected_matrix_mxn_nxl[0][0] = 80;
    expected_matrix_mxn_nxl[0][1] = 94;
    expected_matrix_mxn_nxl[1][0] = 71;
    expected_matrix_mxn_nxl[1][1] = 86;

    int** expected_matrix_mxm_mxm = mtx.createMatrix(3, 3);
    expected_matrix_mxm_mxm[0][0] = 423;
    expected_matrix_mxm_mxm[0][1] = 228;
    expected_matrix_mxm_mxm[0][2] = 420;
    expected_matrix_mxm_mxm[1][0] = 439;
    expected_matrix_mxm_mxm[1][1] = 244;
    expected_matrix_mxm_mxm[1][2] = 420;
    expected_matrix_mxm_mxm[2][0] = 375;
    expected_matrix_mxm_mxm[2][1] = 216;
    expected_matrix_mxm_mxm[2][2] = 372;

    if (TestMultiplication1(mtx, expected_matrix_mxn_nxl) != 0) {
        cout << MESSAGE_MULTIPLICATION1_FAIL << endl;
        return EXIT_FAILURE;
    } else {
        cout << MESSAGE_MULTIPLICATION1_SUCESS << endl;
    }

    if (TestMultiplication2(mtx, expected_matrix_mxm_mxm) != 0) {
        cout << MESSAGE_MULTIPLICATION1_FAIL << endl;
        return EXIT_FAILURE;
    } else {
        cout << MESSAGE_MULTIPLICATION2_SUCESS << endl;
    }

    if (TestMultiplication3(mtx) != 0) {
        cout << MESSAGE_MULTIPLICATION1_FAIL << endl;
        return EXIT_FAILURE;
    } else {
        cout << MESSAGE_MULTIPLICATION3_SUCESS << endl;
    }
    

    if (TestTranspose1(mtx) != 0) {
        cout << MESSAGE_TRANSPOSE1_FAIL << endl;
        return EXIT_FAILURE;
    } else {
        cout << MESSAGE_TRANSPOSE1_SUCCESS << endl;
    }

    if (TestTranspose2(mtx) != 0) {
        cout << MESSAGE_TRANSPOSE2_FAIL << endl;
        return EXIT_FAILURE;
    } else {
        cout << MESSAGE_TRANSPOSE2_SUCCESS << endl;
    }

    cout << MESSAGE_SUCCESS << endl;

    mtx.destroyMatrix(expected_matrix_mxn_nxl, 3);
    mtx.destroyMatrix(expected_matrix_mxm_mxm, 3);

    return 0;
}