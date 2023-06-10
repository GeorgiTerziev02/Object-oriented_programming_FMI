#pragma once

enum class BaseType {
	Der1,
	Der2,
	Der3
};

class Base {
public:
	virtual ~Base() = default;
};

class Der1 : public Base { };
class Der2 : public Base { };
class Der3 : public Base { };

class SingletonFactory {
private:
	static SingletonFactory* instance;
	SingletonFactory();

public:
	SingletonFactory(const SingletonFactory&) = delete;
	SingletonFactory& operator=(const SingletonFactory&) = delete;
	~SingletonFactory();

	static SingletonFactory* getInstance();
	static void freeInstance();

	// v1
	Base* create(BaseType type) const;

	// v2
	// Der1* createDer1() const;
	// Der2* createDer1() const;
	// Der3* createDer1() const;
};