#include <iostream>


int** allocateMatrix(int rows, int cols)
{
	
	int** matrix = new int*[rows];
	for(int i = 0;i < rows; i++)
	{
		matrix[i] = new int[cols];
	}
	return matrix;
};


void FreeMatrix(int** matrix,int rows)
{
	for (int i = 0; i < rows;i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
	

}

void ReadMatrix(int** matrix, int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			std::cin >> matrix[i][j];
		}
	}
}
void PrintMatrix(int** matrix, int rows, int cols)
{

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			std::cout << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

int** tranposeMatrix(int** matrix, int rows,int cols)
{
	int** tranposed = allocateMatrix(cols,rows);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			tranposed[j][i] = matrix[i][j];
		}
	}
	return tranposed;

}
void SwapPlaces( int& X,  int& Y)
{
	int Z;
	Z = X;
	X = Y;
	Y = Z;

}
void swapRows(int** matrix, int row1, int row2 ,int cols)
{
	for (size_t i = 0; i < cols; i++)
	{
		SwapPlaces(matrix[row1][cols], matrix[row2][cols]);
	}
}


int main()
{
	int rows;
	int cols;
	std::cin >> rows >> cols;
	int ** matrix = allocateMatrix(rows, cols);

	ReadMatrix(matrix, rows, cols);
	PrintMatrix(matrix, rows, cols);
	std::cout << std::endl;

	int ** transpoesed = tranposeMatrix(matrix, rows, cols);
	PrintMatrix(transpoesed, rows, cols);
	FreeMatrix(matrix, rows);
	FreeMatrix(transpoesed, rows);






	
}