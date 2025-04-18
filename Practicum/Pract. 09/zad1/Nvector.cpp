#include "Nvector.h"
#include <new>
#include <stdexcept>
#include <iostream>




void Nvector::copyDynamic(const Nvector& other)
{
    int* copyVector = new int[other.size]; // throws

    for (size_t i = 0; i < other.size; i++)
    {
        copyVector[i] = other.vector[i];
    }

    this->vector = copyVector;
}

void Nvector::freeDynamic()
{
    delete[] vector;
    vector = nullptr;
}

bool Nvector::areDiffSize(const Nvector& other) const
{
    return  (this->getSize() != other.getSize());
}

std::ostream& operator<<(std::ostream& lhs, const Nvector& rhs)
{
    for (size_t i = 0; i < rhs.getSize(); i++)
    {
        lhs << rhs[i];
        if (i != rhs.getSize() - 1)
            lhs << ",";
    }
    return lhs;
}

std::istream& operator>>(std::istream& lhs, Nvector& rhs)
{
    for (size_t i = 0; i < rhs.getSize(); i++)
    {
        lhs >> rhs[i];
    }
    return lhs;
}

Nvector::Nvector(unsigned n) : size(n), vector(nullptr)
{
    vector = new int[size]; // throws
}

Nvector::Nvector(const Nvector& other) : size(other.size)
{
    copyDynamic(other); // throws
}

Nvector& Nvector::operator=(const Nvector& other)
{
    if (this != &other)
    {

        freeDynamic();
        copyDynamic(other);
        this->size = other.size;
    }
    return *this;
}

Nvector::~Nvector()
{
    freeDynamic();
}

Nvector& Nvector::operator+=(const Nvector& other)
{
    if (areDiffSize(other))
        throw std::logic_error("cannot add vectors with different sizes");
    

    for (size_t i = 0; i < size; i++)
    {
        vector[i] += other.vector[i];
    }
    return *this;

}

Nvector& Nvector::operator*=(int scalar)
{

    for (size_t i = 0; i < size; i++)
    {
        vector[i] *= scalar;
    }
    return *this;
}


Nvector& Nvector::operator-=(const Nvector& other)
{
    if (areDiffSize(other))
        throw std::logic_error("cannot subtract vectors with different sizes");

    for (size_t i = 0; i < size; i++)
    {
        vector[i] -= other.vector[i];
    }
    return *this;
}


int& Nvector::operator[](int index)
{
    if (index < 0 || index >= size)
        throw std::out_of_range("index out of range");


    return this->vector[index];
}

int Nvector::operator[](int index) const
{
    if (index < 0 || index >= size)
        throw std::out_of_range("index out of range");


    return this->vector[index];
}


Nvector operator+(const Nvector& lhs,const Nvector& rhs)
{
    if (lhs.areDiffSize(rhs))
        throw std::logic_error("cannot add vectors with different sizes");

    Nvector result(lhs);

    result += rhs;
  
    return result;

}

Nvector operator-(const Nvector& lhs, const Nvector& rhs)
{
    if (lhs.areDiffSize(rhs))
        throw std::logic_error("cannot subtract vectors with different sizes");

    Nvector result(lhs);

    result -= rhs;

    return result;

}