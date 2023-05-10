#pragma once
#include "IntObserver.h"

class ConsoleIntObserver : public IntObserver {
public:
	ConsoleIntObserver(IntObservable* observable = nullptr);
	void notify(int value) override;
	void complete() override;
};

