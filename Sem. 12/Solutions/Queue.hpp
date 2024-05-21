#pragma once
#include <utility>
#include <exception>

template<typename T>
class MyQueue {
private:
	static const short INITIAL_CAPACITY = 4;
	static const short RESIZE_COEF = 2; // the most optimal is between 1.4 and 1.5

	T* data;
	size_t capacity = INITIAL_CAPACITY;
	size_t size = 0;

	size_t get = 0, put = 0;

	void resize();

	void incrementIndexPointer(size_t& indexPointer);
public:
	MyQueue();
	MyQueue(const MyQueue<T>& other);
	MyQueue(MyQueue<T>&& other) noexcept;
	MyQueue<T>& operator=(const MyQueue& other);
	MyQueue<T>& operator=(MyQueue&& other) noexcept;
	~MyQueue();

	void push(const T& value);
	void push(T&& value);
	void pop();

	const T& peek() const;
	bool isEmpty() const;
private:
	void copyFrom(const MyQueue<T>& other);
	void moveFrom(MyQueue<T>&& other);
	void free();
};

template<typename T>
void MyQueue<T>::resize() {
	T* newData = new T[capacity * RESIZE_COEF];
	for (size_t i = 0; i < size; i++) {
		newData[i] = data[get];
		incrementIndexPointer(get);
	}

	capacity *= RESIZE_COEF;
	delete[] data;
	data = newData;
	get = 0;
	put = size;
}

template<typename T>
void MyQueue<T>::incrementIndexPointer(size_t& indexPointer) {
	(++indexPointer) %= capacity;
}

template<typename T>
MyQueue<T>::MyQueue() {
	data = new T[capacity];
}

template<typename T>
MyQueue<T>::MyQueue(const MyQueue<T>& other) {
	copyFrom(other);
}

template<typename T>
MyQueue<T>::MyQueue(MyQueue<T>&& other) noexcept {
	moveFrom(std::move(other));
}

template<typename T>
MyQueue<T>& MyQueue<T>::operator=(const MyQueue& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}

	return *this;
}

template<typename T>
MyQueue<T>& MyQueue<T>::operator=(MyQueue&& other) noexcept {
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

template<typename T>
MyQueue<T>::~MyQueue() {
	free();
}

template<typename T>
void MyQueue<T>::push(const T& value) {
	if (size == capacity) {
		resize();
	}

	data[put] = value;
	incrementIndexPointer(put);
	size++;
}

template<typename T>
void MyQueue<T>::push(T&& value) {
	if (size == capacity) {
		resize();
	}

	data[put] = std::move(value);
	incrementIndexPointer(put);
	size++;
}

template<typename T>
void MyQueue<T>::pop() {
	if (isEmpty()) {
		throw std::logic_error("Queue is empty!");
	}

	incrementIndexPointer(get);
	size--;
}

template<typename T>
const T& MyQueue<T>::peek() const {
	if (isEmpty()) {
		throw std::logic_error("Queue is empty!");
	}

	return data[get];
}

template<typename T>
bool MyQueue<T>::isEmpty() const {
	return size == 0;
}

template<typename T>
void MyQueue<T>::copyFrom(const MyQueue<T>& other) {
	get = other.get;
	put = other.put;
	capacity = other.capacity;
	size = other.size;
	data = new T[capacity];
	for (size_t i = 0; i < size; i++) {
		data[i] = other.data[i];
	}
}

template<typename T>
void MyQueue<T>::moveFrom(MyQueue<T>&& other) {
	get = other.get;
	put = other.put;
	size = other.size;
	capacity = other.capacity;
	data = other.data;

	other.data = nullptr;
	other.get = other.put = 0;
	other.size = other.capacity = 0;
}

template<typename T>
void MyQueue<T>::free() {
	delete[] data;
}
