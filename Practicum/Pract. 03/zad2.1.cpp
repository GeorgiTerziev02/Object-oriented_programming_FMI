#include <iostream>
#include <fstream>

const unsigned MAX_SIZE = 100;
constexpr char FIRST_MATRIX_FILE[] = "Matrix1.txt";
constexpr char SECOND_MATRIX_FILE[] = "Matrix2.txt";
constexpr char SUM_FILE[] = "SumMatrix.txt";

struct Matrix
{
	int matrix[MAX_SIZE][MAX_SIZE];
	int rows = 0;
	int cols = 0;
};

void readMatrix(Matrix& Rmatrix,std::ifstream& in)
{
	char delimiter;
	int value;
	int row = 0;
	while (row < MAX_SIZE && in)
	{
		int col = 0;
		while (col < MAX_SIZE && in >> value)
		{
			Rmatrix.matrix[row][col++] = value;
			in.get(delimiter);

			if (delimiter == '|')
			{
				break;
			}
		}
		row++;
		Rmatrix.rows++;
		Rmatrix.cols = col;
		
	}
	
}


 void addMatrixs(const Matrix& matrix1, const Matrix& matrix2,Matrix &sum)
{
	sum.rows = matrix1.rows;
	sum.cols = matrix1.cols;
	for (size_t i = 0; i < matrix1.rows; i++)
	{
		for (size_t j = 0; j < matrix2.cols; j++)
		{
			sum.matrix[i][j] = matrix1.matrix[i][j] + matrix2.matrix[i][j];
		}
	}
}

void printMatrix(Matrix& Pmatrix)
{
	for (size_t i = 0; i < Pmatrix.rows; i++)
	{
		for (size_t j = 0; j < Pmatrix.cols; j++)
		{
			std::cout << Pmatrix.matrix[i][j] << " ";
		}
		std::cout << "\n";
	}
}
void writeMatrixToFile(const Matrix& matrix,std::ofstream& out)
{
	for (size_t i = 0; i < matrix.rows; i++)
	{

		for (size_t j = 0; j < matrix.cols; j++)
		{
			if (j == matrix.cols -1)
			{
				if (i == matrix.rows - 1)
				{
					out << matrix.matrix[i][j];
					continue;
				}
				out << matrix.matrix[i][j] << "|";
				continue;
			}
			out << matrix.matrix[i][j] << ",";
		}
	}
	if (out.fail())
	{
		std::cerr << "Problem with writing matrix to file\n";
		return ;
	}

}

int main()
{
	std::ifstream inFirst(FIRST_MATRIX_FILE,std::ios::in);

	if (!inFirst)
	{
		std::cerr << "Problem opeining the file " << FIRST_MATRIX_FILE << "\n";
		return -1;
	}
	

	std::ifstream inSecond(SECOND_MATRIX_FILE, std::ios::in);

	if (!inSecond)
	{
		std::cerr << "Problem opeining the file " << SECOND_MATRIX_FILE << "\n";
		return -1;
	}

	Matrix matrix1;
	Matrix matrix2;
	Matrix result;

	readMatrix(matrix1, inFirst);
	readMatrix(matrix2, inSecond);
	inFirst.close();
	inSecond.close();

	
	addMatrixs(matrix1, matrix2, result);
	printMatrix(result);

	std::ofstream out(SUM_FILE, std::ios::out);

	if (!out)
	{
		std::cerr << "Problem opeining the file " << SUM_FILE << "\n";
		return -1;
	}

	writeMatrixToFile(result,out);	
	out.close();
	std::ifstream in(SUM_FILE, std::ios::in);

	if (!in)
	{
		std::cerr << "Problem opeining the file " << SUM_FILE << "\n";
		return -1;
	}
	readMatrix(result,in);
	printMatrix(result);
	




	




	
}

