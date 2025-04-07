#pragma once

class Singleton {
private:
	int dummy;
	Singleton();

	static Singleton* instance;
public:
	Singleton(const Singleton& other) = delete;
	Singleton& operator=(const Singleton& other) = delete;

	int getDummy() const;
	void print();

	static Singleton& getInstance();
};