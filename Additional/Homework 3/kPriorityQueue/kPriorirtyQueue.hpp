#pragma once
#include "Queue.hpp"

template<typename T>
class kPriorityQueue {
	Queue<T>* queues;
	size_t maxPriority;
	size_t size = 0;
public:
	kPriorityQueue(const size_t maxPriority);
	kPriorityQueue(const kPriorityQueue<T>& other);
	kPriorityQueue(kPriorityQueue<T>&& other) noexcept;
	kPriorityQueue<T>& operator=(const kPriorityQueue<T>& other);
	kPriorityQueue<T>& operator=(kPriorityQueue<T>&& other) noexcept;
	~kPriorityQueue();

	size_t getSize() const;

	void enqueue(const T& value, const size_t priority);
	T dequeue();
	T& peek() const;

	bool isEmpty() const;
private:
	void copyFrom(const kPriorityQueue<T>& other);
    void move(kPriorityQueue<T>&& other);
	void free();
};

template<typename T>
kPriorityQueue<T>::kPriorityQueue(const size_t maxPriority) {
	this->maxPriority = maxPriority;
	this->queues = new Queue<T>[maxPriority];
}

template<typename T>
kPriorityQueue<T>::kPriorityQueue(const kPriorityQueue<T>& other) {
	copyFrom(other);
}

template<typename T>
kPriorityQueue<T>::kPriorityQueue(kPriorityQueue<T>&& other) {
	move(std::move(other));
}

template<typename T>
kPriorityQueue<T>& kPriorityQueue<T>::operator=(const kPriorityQueue<T>& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}

	return *this;
}

template<typename T>
kPriorityQueue<T>& kPriorityQueue<T>::operator=(kPriorityQueue<T>&& other) {
	if (this != &other) {
		free();
		move(std::move(other));
	}

	return *this;
}

template<typename T>
kPriorityQueue<T>::~kPriorityQueue() {
	free();
}

template<typename T>
void kPriorityQueue<T>::copyFrom(const kPriorityQueue<T>& other) {
	maxPriority = other.maxPriority;
	size = other.size;
	queues = new Queue<T>[maxPriority];

	for (size_t i = 0; i < maxPriority; i++) {
		queues[i] = other.queues[i];
    }
}

template<typename T>
void kPriorityQueue<T>::move(kPriorityQueue<T>&& other) {
    size = other.size;
    maxPriority = other.maxPriority;
    queues = other.queues;
    other.queues = nullptr;
    other.maxPriority = other.size = 0;
}

template<typename T>
void kPriorityQueue<T>::free() {
	delete[] queues;
	maxPriority = 0;
}

template<typename T>
size_t kPriorityQueue<T>::getSize() const {
	return size;
}

template<typename T>
void kPriorityQueue<T>::enqueue(const T& element, const size_t priority) {
	if (priority >= maxPriority) {
		throw std::exception("Invalid priority!");
    }

	queues[priority].enqueue(element);
	size++;
}

template<typename T>
T kPriorityQueue<T>::dequeue() {
	if (isEmpty()) {
		throw std::exception("No elements in the queue!");
    }

	for (int i = maxPriority - 1; i >= 0; i--) {
		if (!queues[i].isEmpty()) {
			size--;
			return queues[i].dequeue();
		}
	}
}

template<typename T>
T& kPriorityQueue<T>::peek() const {
	if (isEmpty()) {
		throw std::exception("No elements in the queue!");
    }

	for (int i = maxPriority - 1; i >= 0; i--) {
		if (!queues[i]->isEmpty()) {
			queues[i].peek();
        }
    }
}

template<typename T>
bool kPriorityQueue<T>::isEmpty() const {
	return size == 0;
}