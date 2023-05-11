#pragma once
#include "IntObserver.h"
#include <fstream>

class FileIntObserver : public IntObserver {
	std::ofstream out;
public:
	FileIntObserver(const char* fileName, IntObservable* observable = nullptr);
	~FileIntObserver();
	void notify(int value) override;
	void complete() override;
};