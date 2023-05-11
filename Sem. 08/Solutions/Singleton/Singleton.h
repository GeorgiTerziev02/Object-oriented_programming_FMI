#pragma once

class Singleton {
private:
	static Singleton* instance;
	Singleton();
    
public:
	Singleton(const Singleton&) = delete;
	Singleton& operator=(const Singleton&) = delete;
	static Singleton* getInstance();
	static void freeInstance();
	~Singleton();
};

