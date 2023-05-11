#pragma once

class TestClass {
public:
	int a = 4, b = 5;
};

class UniqueElementPointer{
private:
	TestClass* ptr;
public:
	UniqueElementPointer(TestClass* ptr);
	UniqueElementPointer(const TestClass& ptr) = delete;
	UniqueElementPointer& operator=(const TestClass& ptr) = delete;
	
	UniqueElementPointer(UniqueElementPointer&& other) noexcept;
	UniqueElementPointer& operator=(UniqueElementPointer&& other) noexcept;
	
	TestClass* operator->();
	const TestClass* operator->() const;
	TestClass& operator*();
	const TestClass& operator*() const;

	TestClass* get();
	void reset(TestClass* ptr);
	TestClass* release(); // releases the ownership of the pointer

	~UniqueElementPointer();
private:
	void move(UniqueElementPointer&& other) noexcept;
	void free();
};
