#include <iostream>
using namespace std;

struct empty { 
}; // 1

struct test1 { 
	int number;
}; // 4

struct test2 { 
	char symbol;
	int number;
}; // 8

struct test3 {
	char symbol;
	short sh;
	int number;
}; // 8

struct test4 {
	char symbol1;
	int number;
	char symbol2;
}; // 12

struct student {
	char* name;
	int* grades;
}; // depends for x32 - 8 and for x64 - 16

struct test5 {
	char a[5];
	int b;
	double c;
}; // 24

struct test6 {
	char a[3];
	short b;
	double c[4];
	char d;
}; // 48

namespace task1 {
    struct A
    {
        double c;
        char b; 
    }; // 16

    struct B
    {
        char c;
    }; // 1

    struct C
    {
        A obj;
        B obj2;
    }; // 24
};

namespace task2 {
    struct A
    {
        double c;
        char b;
        int k;
        char s;
    }; // 24

    struct B
    {
        int a;
        char c;
        char d;
        float f;
    }; // 12

    struct C
    {
        char arr[3];
        float f;
    }; // 8

    struct D
    {
        C obj1;
        A obj2;
        int i;
        char c;
        B obj3;
        bool b;
        double d;
    }; // 64
};

namespace task3
{
    struct A
    {
        int a;
        char b;
    }; // 8

    struct B
    {
        char c;
    }; // 1

    struct C
    {
        char f;
        A obj;
        B obj2;
        double d;
    }; // 24
} 


int main() {
}