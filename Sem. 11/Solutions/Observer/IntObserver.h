#pragma once

#include "IntObservable.h"

class IntObserver {
	IntObservable* observable;
public:
	IntObserver(IntObservable* observable = nullptr);
	virtual ~IntObserver();

	void attach(IntObservable* observable);
	void detach();
	
	virtual void notify(int value) = 0;
	virtual void complete();
};

