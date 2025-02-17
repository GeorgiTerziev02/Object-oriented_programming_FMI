#include<iostream>

void mySwap(int*& a, int*& b) {
    int* temp = a;
    a = b;
    b = temp;
}

bool isValidRow(int rows, int row) {
    return row >= 0 && row < rows;
}

void swapRows(int** arr, int rows, int row1, int row2) {
    if(!isValidRow(rows, row1) || !isValidRow(rows, row2)) {
        return;
    }

    // TODO:
    // Why this is not optimal?
    // What is the difference between this and the other implementation?
    // When each of them should be used?
    // for (size_t i = 0; i < rows; i++) {
    //     int temp = arr[row1][i];
    //     arr[row1][i] = arr[row2][i];
    //     arr[row2][i] = temp;
    // }
    mySwap(arr[row1], arr[row2]);
}

void freeMatrix(int** arr, int rows) {
    for (size_t i = 0; i < rows; i++) {
        delete[] arr[i];
    }

    delete[] arr;
}

int main() {

    const int ROWS = 3;
    const int COLS = 3;

    // TODO: how would you handle the following case?
    // Each row of the matrix has different size
    int** arr = new int* [ROWS];
    for (size_t i = 0; i < ROWS; i++) {
        arr[i] = new int[COLS];
    }
    
    // ... do some stuff with the matrix
    swapRows(arr, ROWS, 0, 1); 
    
    freeMatrix(arr, ROWS);
}
