#include "IntObservable.h"
#include "IntObserver.h"

#include <exception>

void IntObservable::notify() {
	for (size_t i = 0; i < observersSize; i++) {
		observers[i]->notify(value);
	}
}

void IntObservable::complete() {
	for (size_t i = 0; i < observersSize; i++) {
		observers[i]->complete();
	}

	observersSize = 0;
}

IntObservable::IntObservable(int value) : value(value) {}

IntObservable::~IntObservable() {
	complete();
}

void IntObservable::addObserver(IntObserver* observer) {
	if (observersSize >= IntObservable::MAX_OBSERVERS_SIZE) {
		throw std::exception("Limit reached");
	}

	observers[observersSize++] = observer;
}

void IntObservable::removeObserver(IntObserver* observer) {
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

int IntObservable::getValue() const {
	return value;
}

void IntObservable::setValue(int newValue) {
	value = newValue;
	notify();
}