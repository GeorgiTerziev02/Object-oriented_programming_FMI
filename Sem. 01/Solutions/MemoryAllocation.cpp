#include <iostream>

int main() {
	// How much memory is allocated in the following expressions and where?
	// We assume that our os is x32 and the pointer takes 4 bytes
	short s = 1;				// Stack:	2	Heap:	0
	int a = 2;				// Stack:	4	Heap:	0
	bool b = true;				// Stack:	1	Heap:	0
	bool* p = new bool;			// Stack:	4	Heap:   1
	char c = '\0';				// Stack:	1	Heap:	0
	double d = 11.1;			// Stack:	8	Heap:	0
	int arr1[40] = { 0 };			// Stack:	164	Heap:	0
	// arr1 is a static array => it allocates one pointer and 40 * 4 int
	
	int* arr2 = new int(40);		// Stack:	4	Heap:   4
	int* arr3 = new int[40];		// Stack:	4	Heap:	160
	char test[] = "abcd";			// Stack:	9	Heap:	0
	int** matrix = new int*[10];  		// Stack:	4  	Heap:	10 * 4
	for (size_t i = 1; i < 10; i++) {
		matrix[i] = new int[i]; // new int(i) vs new int[i]
	}
	// new int(i)
	// Stack:  4    Heap: 10 * 4 + 9 * 4
	// new int[i]
	// Stack:  4	Heap: 10 * 4 + 4(1 + 2 .... + 9)

	//int arr1[40] = { 0 };		// Stack: 164	Heap:
	//int* arr2 = new int(40);	// Stack:	4	Heap:   4
	//int* arr3 = new int[40];	// Stack:	4	Heap: 160
	// Which of the following statements is/are incorrect?
	// delete[] arr1; - arr1 is not a dynamic array
	// delete[] arr2; - arr2 is a pointer to a int, not to a int[]
	// delete[] arr3; - correct

	return 0;
}
