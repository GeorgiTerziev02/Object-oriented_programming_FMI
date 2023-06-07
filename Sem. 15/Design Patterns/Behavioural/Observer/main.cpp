#include "Observable.hpp"
#include "FileLoggerObserver.hpp"
#include "ConsoleLoggerObserver.hpp"

int v1() {
	Observable<int>* intObservable = new Observable<int>(4);

	auto fileLogger = new FileLoggerObserver<int>("test.txt", intObservable);
	auto consoleLogger = new ConsoleLoggerObserver<int>(intObservable);

	consoleLogger->detach();
	intObservable->setValue(5);
	consoleLogger->attach(intObservable);
	intObservable->setValue(6);

	delete intObservable;
	delete fileLogger;
	delete consoleLogger;
	return 0;
}