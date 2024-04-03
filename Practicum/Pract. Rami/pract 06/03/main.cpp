#include <iostream>

#include "MultiSet.h"

int main() {
	MultiSet set1(10);
	MultiSet set2(6);

	set1.add(3);
	set1.add(2);
	set1.add(4);
	set1.add(5);
	set1.add(1);
	set1.add(4);
	set1.add(4);
	set1.add(4);
	set1.add(11);
	set1.printAllElements();

	set1.remove(4);
	set1.printAllElements();

	set2.add(1);
	set2.add(2);
	set2.add(3);
	set2.add(4);
	set2.add(4);
	set2.add(5);
	set2.printAllElements();

	MultiSet unionSet = unite(set1, set2);
	unionSet.printAllElements();

	MultiSet intersectionSet = intersect(set1, set2);
	intersectionSet.printAllElements();

	int set3Elements[] = { 2, 5, 7 };
	MultiSet set3(8, set3Elements, 3);
	set3.printAllElements();
}