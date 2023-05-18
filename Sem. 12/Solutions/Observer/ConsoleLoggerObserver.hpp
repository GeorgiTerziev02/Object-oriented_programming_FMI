#pragma once
#include "Observer.hpp"

template<typename T>
class ConsoleLoggerObserver : public Observer<T> {
public:
	ConsoleLoggerObserver(Observable<T>* observable = nullptr);
	void notify(const T& value) override;
	void complete() override;
};

template<typename T>
ConsoleLoggerObserver<T>::ConsoleLoggerObserver(Observable<T>* observable) 
    : Observer<T>(observable) { }

template<typename T>
void ConsoleLoggerObserver<T>::notify(const T& value) {
	std::cout << "We have new value: " << value << std::endl;
}

template<typename T>
void ConsoleLoggerObserver<T>::complete() {
	std::cout << "The observable is dead" << std::endl;
	Observer<T>::complete();
}