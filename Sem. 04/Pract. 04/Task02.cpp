#include <iostream>
#include <fstream>
#include "Exam.h"

int main() {
	Task arr[3];
	arr[0].setName("test 1");
	arr[0].setDescription("easy");
	arr[0].setPoints(10);

	arr[1].setName("test 2");
	arr[1].setDescription("medium");
	arr[1].setPoints(20);

	arr[2].setName("test 3");
	arr[2].setDescription("difficult");
	arr[2].setPoints(50);

	Exam ex(arr, 5);

	ex.writeToFile("Task02.dat");
	ex.readFromFile("Task02.dat");
	std::cout << ex.getMax() << std::endl;
	ex.print();
}