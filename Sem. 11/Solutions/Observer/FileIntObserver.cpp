#include "FileIntObserver.h"

FileIntObserver::FileIntObserver(const char* fileName, IntObservable* observable) 
	: IntObserver(observable), out(fileName) {
	if (!out.is_open()) {
		detach(); // attach is called in the base class
		throw std::exception("Could not open file");
	}
}

FileIntObserver::~FileIntObserver() {
	out.close();
}

void FileIntObserver::notify(int value) {
	out << value << std::endl;
}

void FileIntObserver::complete() {
	out << "This observable is dead" << std::endl;
	IntObserver::complete();
}