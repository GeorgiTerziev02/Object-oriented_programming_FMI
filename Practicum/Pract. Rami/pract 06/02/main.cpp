#include <iostream>
#include "NumberSeries.h"

int transitionFunction(int previousNumber) {
	return previousNumber + 45;
}

int main() {
	int initialValue = -10;

	NumberSeries series(initialValue, transitionFunction);

	std::cout << series.getNumberAtIndex(4) << std::endl;
	std::cout << series.isInSeries(4) << std::endl;
	std::cout << series.isInSeries(80) << std::endl;
}