#include <iostream>

using std::cout;
using std::endl;
using std::cin;

struct Row {
	int* elements;
};

struct Matrix {
	size_t n;
	size_t m; // Done this way because the size of matrix is static
	Row* rows;
};

void InitMatrix(Matrix& matrix, size_t n, size_t m) {
	matrix.n = n;
	matrix.m = m;
	matrix.rows = new Row[n];
	for (size_t i = 0; i < n; i++) {
		matrix.rows[i].elements = new int[m];
	}
}


void EnterRow(Row& row, size_t m) {
	for (size_t i = 0; i < m; i++) {
		cin >> row.elements[i];
	}
}

void EnterMatrix(Matrix& matrix) {
	for (size_t i = 0; i < matrix.n; i++) {
		EnterRow(matrix.rows[i], matrix.m);
	}
}


void Transpose(Matrix* oldMatrix) {
	int n = oldMatrix->n;
	int m = oldMatrix->m;

	Matrix newMatrix;
	InitMatrix(newMatrix, m, n);

	for (int i = 0; i < n; i++) {
		for (int k = 0; k < m; k++) {
			newMatrix.rows[k].elements[i] = oldMatrix->rows[i].elements[k];
		}
	}

	*oldMatrix = newMatrix;
}

void Swap2LinesByIndex(Matrix* matrix, size_t i1, size_t i2) {
	Row temp = matrix->rows[i1];
	matrix->rows[i1] = matrix->rows[i2];
	matrix->rows[i2] = temp;
}

void SwapAllLines(Matrix* matrix) {
	int n = matrix->n;
	for (int i = 0; i < n/2; i++) {
		if (i != n - i - 1) {
			//std::swap (matrix->rows[i], matrix->rows[n - i - 1]);
			Swap2LinesByIndex(matrix, i, n - i - 1);
		}
	}
}

void Print(const Matrix& matrix) {
	for (int i = 0; i < matrix.n; i++) {
		for (int k = 0; k < matrix.m; k++) {
			cout << matrix.rows[i].elements[k] << " ";
		}
		cout << "\n";
	}
}

int main()
{
	int n, m;
	cin >> n >> m;
	Matrix* matrix = new Matrix();
	InitMatrix(*matrix, n, m);
	EnterMatrix(*matrix);

	Transpose(matrix);
	SwapAllLines(matrix);

	Print(*matrix);

	for(size_t i = 0; i < matrix->n; i++) {
			delete[] matrix->rows[i].elements;
	}
	delete[] matrix->rows;
	delete matrix;

	return 0;
}
