#pragma once

template<typename T>
class SharedPointer {
private:
	T* data = nullptr;
	size_t* counter = nullptr;

public:
	SharedPointer(T* data = nullptr);
	SharedPointer(const SharedPointer<T>& other);
	SharedPointer(SharedPointer<T>&& other) noexcept;
	SharedPointer<T>& operator=(const SharedPointer<T>& other);
	SharedPointer<T>& operator=(SharedPointer<T>&& other) noexcept;
	~SharedPointer();

	const T* operator->() const;
	T* operator->() const;
	const T& operator*() const;
	T& operator*() const;

	T* get() const;
	void reset(T* data = nullptr);
	size_t getCount() const;

	explicit operator bool() const;

private:
	void copyFrom(const SharedPointer<T>& other);
	void move(SharedPointer<T>&& other) noexcept;
	void free();
};


template<typename T>
SharedPointer<T>::SharedPointer(T* data) {
	this->data = data;
	if (this->data) {
		counter = new size_t(1);
	}
}

template<typename T>
SharedPointer<T>::SharedPointer(const SharedPointer<T>& other) {
	copyFrom(other);
}

template<typename T>
SharedPointer<T>::SharedPointer(SharedPointer<T>&& other) noexcept {
	move(std::move(other));
}

template<typename T>
SharedPointer<T>& SharedPointer<T>::operator=(const SharedPointer<T>& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}

	return *this;
}

template<typename T>
SharedPointer<T>& SharedPointer<T>::operator=(SharedPointer<T>&& other) noexcept {
	if (this != &other) {
		free();
		move(std::move(other));
	}

	return *this;
}

template<typename T>
SharedPointer<T>::~SharedPointer() {
	free();
}

template<typename T>
const T* SharedPointer<T>::operator->() const {
	return data;
}

template<typename T>
T* SharedPointer<T>::operator->() const {
	return data;
}

template<typename T>
const T& SharedPointer<T>::operator*() const {
	return *data;
}

template<typename T>
T& SharedPointer<T>::operator*() const {
	return *data;
}

template<typename T>
T* SharedPointer<T>::get() const {
	return data;
}

template<typename T>
void SharedPointer<T>::reset(T* data) {
	if (this->data == data) {
		return;
	}

	free();
	this->data = data;
	if (this->data) {
		counter = new size_t(1);
	}
}

template<typename T>
size_t SharedPointer<T>::getCount() const {
	return counter;
}

template<typename T>
SharedPointer<T>::operator bool() const {
	return data;
}

template<typename T>
void SharedPointer<T>::copyFrom(const SharedPointer<T>& other) {
	data = other.data;
	counter = other.data;
	if (data) {
		(*counter)++;
	}
}

template<typename T>
void SharedPointer<T>::move(SharedPointer<T>&& other) noexcept {
	data = other.data;
	counter = other.counter;

	other.data = nullptr;
	other.counter = nullptr;
}

template<typename T>
void SharedPointer<T>::free() {
	if (!data) {
		return;
	}

	if ((*counter) == 1) {
		delete data;
		delete counter;
	}
	else {
		(*counter)--;
	}
}
