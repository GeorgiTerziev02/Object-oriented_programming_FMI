#include "Matrix.h"
#include <new>
#include <stdexcept>
#include <iostream>

void Matrix::freeDynamic()
{
    for (size_t i = 0; i < rows; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}

void Matrix::copyDynamic(const Matrix& other)
{
   
    matrix = new int* [rows]; // throws 

    for (size_t i = 0; i < rows; i++)
    {
        matrix[i] = new int[cols]; // throws

        for (size_t j = 0; j < cols; j++)
        {
            matrix[i][j] = other.matrix[i][j];
        }
    }
}

Matrix::Matrix() : Matrix(2, 2) {}


Matrix::Matrix(int rows, int cols) :rows(rows), cols(cols), matrix(nullptr)
{
    if (rows == 0 || cols == 0)
        throw std::invalid_argument("rows and cols cannot be zero");

    matrix = new int* [rows]; // throws

    for (size_t i = 0; i < rows; i++)
    {
        matrix[i] = new int[cols]; // throws
    }
}

Matrix::Matrix(const Matrix& other)
    : rows(other.rows), cols(other.cols), matrix(nullptr)
{
    copyDynamic(other); // throws bad alloc
}

Matrix::~Matrix() noexcept
{
    freeDynamic();
}

Matrix& Matrix::operator=(const Matrix& other)
{
    if (this != &other)
    {
        freeDynamic();
        copyDynamic(other);
        this->rows = other.rows;
        this->cols = other.cols;
    }
    return *this;
}

Matrix& Matrix::operator+=(const Matrix& rhs)
{
    if (rows != rhs.rows || cols != rhs.cols)
    {
        std::cerr << "Can += matrix with different sizes\n";
        throw std::invalid_argument("bad matrix in +=");
    }

    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            matrix[i][j] += rhs.matrix[i][j];
        }
    }
    return *this;

}

Matrix& Matrix::operator-=(const Matrix& rhs)
{
    if (rows != rhs.rows || cols != rhs.cols)
    {
        std::cerr << "Can -= matrix with different sizes\n";
        throw std::invalid_argument("bad matrix in -=");
    }

    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            matrix[i][j] -= rhs.matrix[i][j];
        }
    }
    return *this;

}

Matrix& Matrix::operator++()
{
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            matrix[i][j] += 1;
        }
    }
    return *this;
}

Matrix Matrix::operator++(int dummy)
{
    Matrix copy = *this;
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            matrix[i][j] += 1;
        }
    }
    return copy;
}

Matrix& Matrix::operator--()
{
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            matrix[i][j] -= 1;
        }
    }
    return *this;
}

Matrix Matrix::operator--(int dummy)
{
    Matrix copy = *this;
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            matrix[i][j] -= 1;
        }
    }
    return copy;
}

Matrix& Matrix::operator*=(int num)
{
  

    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            matrix[i][j] *= num;
        }
    }
    return *this;
}

int* Matrix::operator[](unsigned index)
{
    if (index >= rows)
        throw std::out_of_range("in operator [] out of bounds");

    return matrix[index];
}

const int* Matrix::operator[](unsigned index) const
{
    if (index >= rows)
        throw std::out_of_range("in operator [] out of bounds");

    return matrix[index];
}

Matrix Matrix::operator()()
{
    Matrix result(this->cols, this->rows);

    for (size_t i = 0; i < cols; i++)
    {
        for (size_t j = 0; j < rows; j++)
        {
            result[i][j] = matrix[j][i];
        }
    }
    return result;
}


 Matrix::operator bool() const
{
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            if (matrix[i][j] != 0)
                return true;
        }
    }
    return false;
}





bool operator<(const Matrix& lhs, const Matrix& rhs)
{

    if (lhs.getRows() != rhs.getRows() || rhs.getCols() != rhs.getRows())
    {
        std::cerr << "Can -= matrix with different sizes\n";
        throw std::invalid_argument("bad matrix in -=");
    }

    int sumLhs = 0;
    int sumRhs = 0;

    for (size_t i = 0; i < lhs.getRows(); i++)
    {
        for (size_t j = 0; j < lhs.getCols(); j++)
        {
            sumLhs += lhs[i][j];
            sumRhs += rhs[i][j];
        }
    }

    return sumLhs < sumRhs;
}

bool operator==(const Matrix& lhs, const Matrix& rhs)
{

    if (lhs.getRows() != rhs.getRows() || rhs.getCols() != rhs.getRows())
    {
        std::cerr << "Can -= matrix with different sizes\n";
        throw std::invalid_argument("bad matrix in -=");
    }

    int sumLhs = 0;
    int sumRhs = 0;

    for (size_t i = 0; i < lhs.getRows(); i++)
    {
        for (size_t j = 0; j < lhs.getCols(); j++)
        {
            sumLhs += lhs[i][j];
            sumRhs += rhs[i][j];
        }
    }

    return sumLhs == sumRhs;
}




bool operator<=(const Matrix& lhs, const Matrix& rhs)
{

    return (lhs < rhs) && (lhs == rhs);
}

bool operator>(const Matrix& lhs, const Matrix& rhs)
{

   return !(lhs < rhs);
}

bool operator>=(const Matrix& lhs, const Matrix& rhs)
{

    return (lhs > rhs) && (lhs == rhs);
}


// == is for sum so im making a different function for comparison



bool Equals(const Matrix& lhs, const Matrix& rhs)
{
    if (lhs.getRows() != rhs.getRows() || rhs.getCols() != rhs.getRows())
    {
        std::cerr << "Can -= matrix with different sizes\n";
        throw std::invalid_argument("bad matrix in -=");
    }

    

    for (size_t i = 0; i < lhs.getRows(); i++)
    {
        for (size_t j = 0; j < lhs.getCols(); j++)
        {
            if (lhs[i][j] != rhs[i][j])
                return false;
        }
    }

    return true;
}

bool operator!=(const Matrix& lhs, const Matrix& rhs)
{
    if (lhs.getRows() != rhs.getRows() || rhs.getCols() != rhs.getRows())
    {
        std::cerr << "Can -= matrix with different sizes\n";
        throw std::invalid_argument("bad matrix in -=");
    }

    return !Equals(lhs, rhs);


}


void Matrix::print() const
{
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j= 0; j < cols; j++)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << "\n";
    }
}




