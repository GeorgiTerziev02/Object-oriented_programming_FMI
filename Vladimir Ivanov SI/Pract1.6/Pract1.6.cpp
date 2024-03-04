#include <iostream>
using std::cin;
using std::cout;
using std::endl;

void deleteMatrix(int** matrix, const unsigned int rows) {
    for (unsigned int row = 0; row < rows; row++) {
        delete[] matrix[row];
    }

    delete[] matrix;
}

void readMatrix(int** matrix, const unsigned int rows, const unsigned int cols) {
    for (unsigned int row = 0; row < rows; row++) {
        matrix[row] = new int[cols];

        for (unsigned int col = 0; col < cols; col++) {
            cin >> matrix[row][col];
        }
    }
}

void transponatedMatrix(int** matrix, const unsigned int rows, const unsigned int cols) {
    int** transponateMatrix = new int*[cols];

    for (unsigned int row = 0; row < cols; row++) {
        transponateMatrix[row] = new int[rows];
    }
    
    for (unsigned int row = 0; row < rows; row++) {
        for (unsigned int col = 0; col < cols; col++) {
            transponateMatrix[col][row] = matrix[row][col];
        }
    }

    matrix = transponateMatrix;

    deleteMatrix(transponateMatrix, rows);
}

void swapRows(int** matrix, const unsigned int row, const unsigned int rows) {
    unsigned int row2 = rows - row;
    int* rowTemp = matrix[row];
    matrix[row] = matrix[row2];
    matrix[row2] = rowTemp;
}

void swapTransponatedMatrixRows(int** matrix, const unsigned int rows) {
    unsigned int copyRows = rows / 2;

    for (unsigned int row = 0; row < copyRows; row++) {
        swapRows(matrix, row, rows);
    }
}

void printMatrix(int** matrix, const unsigned int rows, const unsigned int cols) {
    for (unsigned int row = 0; row < rows; row++) {
        for (unsigned int col = 0; col < cols; col++) {
            cout << matrix[row][col] << ' ';
        }

        cout << endl;
    }

    cout << endl;
}

int main()
{
    cout << "Enter rows: ";
    unsigned int rows;
    cin >> rows;

    cout << "Enter cols: ";
    unsigned int cols;
    cin >> cols;

    int** matrix = new int*[cols];
    readMatrix(matrix, rows, cols);
    
    transponatedMatrix(matrix, rows, cols);
    
    swapTransponatedMatrixRows(matrix, rows);

    printMatrix(matrix, rows, cols);

    deleteMatrix(matrix, rows);
}