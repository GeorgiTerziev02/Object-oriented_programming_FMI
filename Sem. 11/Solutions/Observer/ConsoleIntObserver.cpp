#include "ConsoleIntObserver.h"
#include <iostream>

ConsoleIntObserver::ConsoleIntObserver(IntObservable* observable) : IntObserver(observable) { }
void ConsoleIntObserver::notify(int value) {
	std::cout << "We have new value: " << value << std::endl;
}

void ConsoleIntObserver::complete() {
	std::cout << "The observable is dead" << std::endl;
	IntObserver::complete();
}