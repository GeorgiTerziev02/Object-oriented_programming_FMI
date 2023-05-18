#pragma once

#include <exception>

template<typename T>
class Observer;

template<typename T>
class Observable {
private:
	static const size_t MAX_OBSERVERS_SIZE = 20;

	T value;
    // TODO: can be replaced with vector
	Observer<T>* observers[MAX_OBSERVERS_SIZE];
	size_t observersSize = 0;

	void notify();
	void complete();
public:
	Observable(const T& value);
	~Observable();

	void addObserver(Observer<T>* obs);
	void removeObserver(Observer<T>* obs);

	const T& getValue() const;
	void setValue(const T& newValue);
};

template<typename T>
void Observable<T>::notify() {
	for (size_t i = 0; i < observersSize; i++) {
		observers[i]->notify(value);
	}
}

template<typename T>
void Observable<T>::complete() {
	for (size_t i = 0; i < observersSize; i++) {
		observers[i]->complete();
	}

	observersSize = 0;
}

template<typename T>
Observable<T>::Observable(const T& value) : value(value) {}

template<typename T>
Observable<T>::~Observable() {
	complete();
}

template<typename T>
void Observable<T>::addObserver(Observer<T>* observer) {
	if (observersSize >= Observable<T>::MAX_OBSERVERS_SIZE) {
		throw std::exception("Limit reached");
	}

	observers[observersSize++] = observer;
}

template<typename T>
void Observable<T>::removeObserver(Observer<T>* observer) {
	if (observersSize == 0) {
		throw std::exception("Empty");
	}

	int observerIndex = -1;
	for (size_t i = 0; i < observersSize; i++) {
		if (observers[i] == observer) {
			observerIndex = i;
			break;
		}
	}

	if (observerIndex == -1) {
		throw std::exception("Not found");
	}

	for (size_t i = observerIndex; i < observersSize - 1; i++) {
		observers[i] = observers[i + 1];
	}
	--observersSize;
}

template<typename T>
const T& Observable<T>::getValue() const {
	return value;
}

template<typename T>
void Observable<T>::setValue(const T& newValue) {
	value = newValue;
	notify();
}