// Практикум-6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
using namespace std;

class NumberSeries
{
private:
    int* series = nullptr;
    int size;
    int capacity;
    int initial;
    int (*func)(int);

    void free()
    {
        delete[] series;
        series = nullptr;
    }

    void CopyFrom(const NumberSeries& other)
    {
        series = new int[capacity + 1];
        for (int i = 0; i < size; i++) 
        {
            series[i] = other.series[i];
        }
        size = other.size;
        capacity = other.capacity;
        initial = other.initial;
        func = other.func;
    }

    void resizeArray() 
    {
        int newCapacity = capacity * 2;
        int* newSeries = new int[newCapacity];
        for (int i = 0; i < size; i++) 
        {
            newSeries[i] = series[i];
        }
        free();
        capacity = newCapacity;
    }

    void reset()
    {
        free();
        capacity = 10;
        size = 0;
        series = new int[capacity];

        if (func != nullptr) 
        {
            series[0] = initial;
            size = 1;
        }
    }

public:


    NumberSeries(int a0 = 0, int capacity = 10, int (*func)(int) = nullptr) : initial(a0), capacity(capacity), func(func), size((func != nullptr) ? 1 : 0)
    {
        series = new int[capacity];
        if (func != nullptr) 
        {
            series[0] = initial;
        }
    }


    NumberSeries(const NumberSeries& other)
    {
        CopyFrom(other);
    }

    NumberSeries operator=(const NumberSeries& other) 
    {
        if (this != &other) 
        {
            free();
            CopyFrom(other);
        }
        return *this;
    }

    ~NumberSeries() 
    {
        free();
    }


    int getValue(int index)
    {
        if (func == nullptr) 
        {
            std::cerr << "Error: Function is not given" << std::endl;
            return -1;
        }

        while (index >= size)
        {
            if (size >= capacity)
            {
                resizeArray();
            }
            int next = func(series[size - 1]);
            series[size] = next;
            size++;
        }
        return series[index];
    }


    bool isInSeries(int num)
    {
        if (func == nullptr)
        {
            std::cerr << "Error: Function is not given" << std::endl;
            return false;
        }

        for (int i = 0; i < size; i++) 
        {
            if (series[i] == num)
                return true;
        }

        const int maxIterations = 1000;
        int iterations = 0;
        while (iterations < maxIterations) 
        {
            int val = getValue(size);
            if (val == num)
                return true;
            iterations++;
        }
        return false;
    }

    void setInitialValue(int a0) 
    {
        initial = a0;
        reset();
    }

    void setTransitionFunction(int (*f)(int)) 
    {
        func = f;
        reset();
    }

    void printSeries() const 
    {
        for (int i = 0; i < size; i++) 
        {
            std::cout << series[i] << " ";
        }
        std::cout << std::endl;
    }
};

int multiplyByTwo(int x) 
{
    return x * 2;
}

int addThree(int x) 
{
    return x + 1912;
}



int main()
{
    int n = 8;
    NumberSeries ns(1, 10, multiplyByTwo);
    cout << "NumberSeries.getValue(0) = " << ns.getValue(0) << endl;
    cout << "NumberSeries.getValue(1) = " << ns.getValue(1) << endl;
    cout << "NumberSeries.getValue(5) = " << ns.getValue(5) << endl;

    cout << "Generated series: ";
    ns.printSeries();

    if (ns.isInSeries(n))
        cout << n << " is in the series" << endl;
    else
        cout << n << " is not in the series" << endl;

    ns.setInitialValue(2);
    ns.setTransitionFunction(addThree);

    cout << endl;
    cout << "After change:" << endl;
    cout << "NumberSeries.getValue(0) = " << ns.getValue(0) << endl;
    cout << "NumberSeries.getValue(1) = " << ns.getValue(1) << endl;
    cout << "NumberSeries.getValue(4) = " << ns.getValue(4) << endl;
    cout << "New series: ";
    ns.printSeries();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
