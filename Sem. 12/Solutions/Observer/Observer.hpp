#pragma once

#include "Observable.hpp"

template<typename T>
class Observer {
	Observable<T>* observable;
public:
	Observer(Observable<T>* observable = nullptr);
	virtual ~Observer();

	void attach(Observable<T>* observable);
	void detach();
	
	virtual void notify(const T& value) = 0;
	virtual void complete();
};

template<typename T>
Observer<T>::Observer(Observable<T>* observable) {
	attach(observable);
}

template<typename T>
Observer<T>::~Observer() {
	detach();
}

template<typename T>
void Observer<T>::attach(Observable<T>* observable) {
	if (!observable) {
		return;
	}

	this->observable = observable;
	observable->addObserver(this);
}

template<typename T>
void Observer<T>::detach() {
	if (!observable) {
		return;
	}

	observable->removeObserver(this);
	observable = nullptr;
}

template<typename T>
void Observer<T>::complete() {
	observable = nullptr;
}