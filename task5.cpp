#include <iostream>
using namespace std;
struct Complex {
    int realPart;
    int imaginaryPart;
};
Complex addition(const Complex& num1,const Complex& num2) {
    Complex num3;
    num3.realPart = num1.realPart + num2.realPart;
    num3.imaginaryPart = num1.imaginaryPart + num2.imaginaryPart;
    return num3;
}
void printComplexNumbers(const Complex& num) {
    cout << num.realPart;
    if (num.imaginaryPart > 0) {
        cout<<"+"<< num.imaginaryPart << "i" << endl;
    }
    else {
        cout << num.imaginaryPart << "i" << endl;
    }
}
int main()
{
    Complex num1{ 1,5 }, num2{ 14,-6 };
    Complex num3 = addition(num1, num2);
    printComplexNumbers(num3);
}
