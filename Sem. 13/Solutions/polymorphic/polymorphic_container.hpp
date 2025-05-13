#pragma once
#include "polymorphic_ptr.hpp"
#include "MyVector.hpp"

template<typename T>
class polymorphic_container {
private:
	Vector<polymorphic_ptr<T>> ptrs;

public:
	void add(T* ptr);
	void execute(size_t index, void(*func)(T*));
	void execute(size_t index, void(*func)(const T*)) const;
};

template<typename T>
void polymorphic_container<T>::add(T* ptr) {
	ptrs.push_back(ptr);
}

template<typename T>
void polymorphic_container<T>::execute(size_t index, void(*func)(T*)) {
	func(ptrs[index].get());
}


template<typename T>
void polymorphic_container<T>::execute(size_t index, void(*func)(const T*)) const {
	func(ptrs[index].get());
}