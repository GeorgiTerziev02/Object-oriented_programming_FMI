#pragma once
#include <utility>

template<typename T>
class polymorphic_ptr {
private:
	T* ptr = nullptr;
public:
	polymorphic_ptr() = default;
	polymorphic_ptr(T* ptr);
	polymorphic_ptr(const polymorphic_ptr<T>& other);
	polymorphic_ptr(polymorphic_ptr<T>&& other) noexcept;
	polymorphic_ptr<T>& operator=(const polymorphic_ptr<T>& other);
	polymorphic_ptr<T>& operator=(polymorphic_ptr<T>&& other) noexcept;
	~polymorphic_ptr();

	T* operator->();
	const T* operator->() const;
	T& operator*();
	const T& operator*() const;

	T* get();
	const T* get() const;
	void reset(T* ptr);
	T* release(); // releases the ownership of the pointer

private:
	void free();
	void copyFrom(const polymorphic_ptr& other);
	void moveFrom(polymorphic_ptr&& other);
};


template<typename T>
polymorphic_ptr<T>::polymorphic_ptr(T* ptr) : ptr(ptr)
{ }

template<typename T>
polymorphic_ptr<T>::polymorphic_ptr(const polymorphic_ptr<T>& other) {
	copyFrom(other);
}

template<typename T>
polymorphic_ptr<T>::polymorphic_ptr(polymorphic_ptr<T>&& other) noexcept {
	moveFrom(std::move(other));
}

template<typename T>
polymorphic_ptr<T>& polymorphic_ptr<T>::operator=(const polymorphic_ptr<T>& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}

	return *this;
}

template<typename T>
polymorphic_ptr<T>& polymorphic_ptr<T>::operator=(polymorphic_ptr<T>&& other) noexcept {
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

template<typename T>
polymorphic_ptr<T>::~polymorphic_ptr() {
	free();
}

template<typename T>
T* polymorphic_ptr<T>::operator->() {
	return ptr;
}

template<typename T>
const T* polymorphic_ptr<T>::operator->() const {
	return ptr;
}

template<typename T>
T& polymorphic_ptr<T>::operator*() {
	return *ptr;
}

template<typename T>
const T& polymorphic_ptr<T>::operator*() const {
	return *ptr;
}

template<typename T>
T* polymorphic_ptr<T>::get() {
	return ptr;
}

template<typename T>
const T* polymorphic_ptr<T>::get() const {
	return ptr;
}

template<typename T>
void polymorphic_ptr<T>::reset(T* ptr) {
	free();
	this->ptr = ptr;
}

template<typename T>
T* polymorphic_ptr<T>::release() {
	T* temp = ptr;
	ptr = nullptr;
	return temp;
}

template<typename T>
void polymorphic_ptr<T>::free() {
	delete ptr;
}

template<typename T>
void polymorphic_ptr<T>::copyFrom(const polymorphic_ptr& other) {
	ptr = other.ptr->clone();
}

template<typename T>
void polymorphic_ptr<T>::moveFrom(polymorphic_ptr&& other) {
	ptr = other.ptr;
	other.ptr = nullptr;
}
