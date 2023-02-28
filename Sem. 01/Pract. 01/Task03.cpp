#include <iostream>

int** initializeMatrix(const int rows, const int cols) {
	int** matrix = new int* [rows];
	for (int i = 0; i < rows; i++) {
		matrix[i] = new int[cols];
	}

	return matrix;
}

void fillMatrix(int** matrix, const int rows, const int cols) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			std::cin >> matrix[i][j];
		}
	}
}

int** transposeMatrix(const int** matrix, const int rows, const int cols) {
	int** transposedMatrix = initializeMatrix(cols, rows);
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			transposedMatrix[j][i] =  matrix[i][j];
		}
	}
    
	return transposedMatrix;
}

void printMatrix(const int** matrix, const int rows, const int cols) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			std::cout << matrix[i][j] << " ";
		}

		std::cout << std::endl;
	}
}

void deleteMatrix(int** matrix, const int rows) {
	for (int i = 0; i < rows; i++) {
		delete[] matrix[i];
	}

	delete[] matrix;
}

int main() {
	int rows, cols;
	std::cin >> rows >> cols;

	int** matrix = initializeMatrix(rows, cols);
	fillMatrix(matrix, rows, cols);
	printMatrix(matrix, rows, cols);

	int** transposedMatrix = transposeMatrix(matrix, rows, cols);
	printMatrix(transposedMatrix, cols, rows);

	deleteMatrix(matrix, rows);
	deleteMatrix(transposedMatrix, cols);
}