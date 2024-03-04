#include <iostream>
using std::cin;
using std::cout;
using std::endl;

struct ComplexNum {
    int x;
    int y;
};

void readComplexNumbers(ComplexNum& num1, ComplexNum& num2) {
    cout << "Enter X1, Y1 and X2, Y2: ";
    cin >> num1.x >> num1.y >> num2.x >> num2.y;
}

int sumNums(const int num1, const int num2) {
    int sum = num1 + num2;
    return sum;
}

ComplexNum& findSum(const ComplexNum& num1, const ComplexNum& num2) {
    ComplexNum result;

    result.x = sumNums(num1.x, num2.x);
    result.y = sumNums(num1.y, num2.y);

    return result;
}

void printNumbers(const ComplexNum& result) {
    cout << result.x << ' ' << result.y << endl;
}

int main()
{
    ComplexNum num1;
    ComplexNum num2;

    readComplexNumbers(num1, num2);

    ComplexNum result = findSum(num1, num2);

    printNumbers(result);
}