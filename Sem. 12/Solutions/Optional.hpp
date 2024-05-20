#pragma once
#include <utility>
#include <exception>

template<typename T>
class Optional {
private:
	T* value = nullptr;

public:
	Optional() = default;
	Optional(const T& value);
	Optional(const Optional<T>& other);
	Optional(Optional<T>&& other) noexcept;
	
	Optional<T>& operator=(const Optional<T>& other);
	Optional<T>& operator=(Optional<T>&& other) noexcept;

	~Optional();

	bool hasValue() const;
	const T& getValue() const;
	void setValue(const T& newValue);
	void setValue(T&& newValue);
	void clear();

private:
	void copyFrom(const Optional<T>& other);
	void moveFrom(Optional<T>&& other);
	void free();
};

template<typename T>
Optional<T>::Optional(const T& value) {
	this->value = new T(value);
}

template<typename T>
Optional<T>::Optional(const Optional<T>& other) {
	copyFrom(other);
}

template<typename T>
Optional<T>::Optional(Optional<T>&& other) noexcept {
	moveFrom(std::move(other));
}

template<typename T>
Optional<T>& Optional<T>::operator=(const Optional<T>& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}

	return *this;
}

template<typename T>
Optional<T>& Optional<T>::operator=(Optional<T>&& other) noexcept {
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

template<typename T>
Optional<T>::~Optional() {
	free();
}

template<typename T>
bool Optional<T>::hasValue() const {
	return value;
}

template<typename T>
const T& Optional<T>::getValue() const {
	if (!hasValue()) {
		throw std::logic("No value in optional");
	}

	return *value;
}

// not optimal
// if the pointer is already allocated we don't
// need to delete it, just use op=
//template<typename T>
//void Optional<T>::setValue(const T& newValue) {
//	if (hasValue()) {
//		clear();
//	}
//
//	value = new T(newValue);
//}

template<typename T>
void Optional<T>::setValue(const T& newValue) {
	if (hasValue()) {
		*value = newValue;
	}
	else {
		value = new T(newValue);
	}
}

template<typename T>
void Optional<T>::setValue(T&& newValue) {
	if (hasValue()) {
		*value = std::move(newValue);
	}
	else {
		value = new T(std::move(newValue));
	}
}

template<typename T>
void Optional<T>::clear() {
	free();
	value = nullptr;
}

template<typename T>
void Optional<T>::copyFrom(const Optional<T>& other) {
	value = other.hasValue() ? new T(*other.value) : nullptr;
}

template<typename T>
void Optional<T>::moveFrom(Optional<T>&& other) {
	value = other.value;
	other.value = nullptr;
}

template<typename T>
void Optional<T>::free() {
	delete value;
}
