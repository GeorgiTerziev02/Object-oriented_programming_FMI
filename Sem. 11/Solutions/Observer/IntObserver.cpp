#include "IntObserver.h"

IntObserver::IntObserver(IntObservable* observable) {
	attach(observable);
}

IntObserver::~IntObserver() {
	detach();
}

void IntObserver::attach(IntObservable* observable) {
	if (!observable) {
		return;
	}

	this->observable = observable;
	observable->addObserver(this);
}

void IntObserver::detach() {
	if (!observable) {
		return;
	}

	observable->removeObserver(this);
	observable = nullptr;
}

void IntObserver::complete() {
	observable = nullptr;
}