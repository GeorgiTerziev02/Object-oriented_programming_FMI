#pragma once
#include "Observer.hpp"
#include <fstream>

template<typename T>
class FileLoggerObserver : public Observer<T>  {
	std::ofstream out;
public:
	FileLoggerObserver(const char* fileName, Observable<T>* observable = nullptr);
	~FileLoggerObserver();
	void notify(const T& value) override;
	void complete() override;
};

template<typename T>
FileLoggerObserver<T>::FileLoggerObserver(const char* fileName, Observable<T>* observable) 
	: Observer<T>(observable), out(fileName) {
	if (!out.is_open()) {
		Observer<T>::detach(); // attach is called in the base class
		throw std::exception("Could not open file");
	}
}

template<typename T>
FileLoggerObserver<T>::~FileLoggerObserver() {
	out.close();
}

template<typename T>
void FileLoggerObserver<T>::notify(const T& value) {
	out << value << std::endl;
}

template<typename T>
void FileLoggerObserver<T>::complete() {
	out << "This observable is dead" << std::endl;
	Observer<T>::complete();
}