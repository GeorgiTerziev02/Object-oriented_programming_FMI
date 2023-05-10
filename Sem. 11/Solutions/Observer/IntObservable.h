#pragma once

class IntObserver;

class IntObservable {
private:
	static const size_t MAX_OBSERVERS_SIZE = 20;

	int value = 0;
	IntObserver* observers[MAX_OBSERVERS_SIZE];
	size_t observersSize = 0;

	void notify();
	void complete();
public:
	IntObservable(int value);
	~IntObservable();

	void addObserver(IntObserver* obs);
	void removeObserver(IntObserver* obs);

	int getValue() const;
	void setValue(int newValue);
};

