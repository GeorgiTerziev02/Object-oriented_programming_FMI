#include <iostream> 

unsigned myAbsDiff(unsigned a, unsigned b) {
	return a > b ? a - b : b - a;
}

class Time {
private:
	unsigned hours, minutes, seconds;

	Time(unsigned seconds) {
		this->seconds = seconds % 60;
		seconds /= 60;
		this->minutes = seconds % 60;
		seconds /= 60;
		this->hours = seconds;
	}

public:
	Time() {
		hours = minutes = seconds = 0;
	}

	Time(unsigned hours, unsigned minutes, unsigned seconds) {
		setHours(hours);
		setMinutes(minutes);
		setSeconds(seconds);
	}

	unsigned getHours() const {
		return this->hours;
	}

	unsigned getMinutes() const {
		return this->minutes;
	}

	unsigned getSeconds() const {
		return this->seconds;
	}

	void setHours(unsigned newValue) {
		if (newValue >= 24) {
			newValue = 0;
		}

		hours = newValue;
	}

	void setMinutes(unsigned newValue) {
		if (newValue >= 60) {
			newValue = 0;
		}

		minutes = newValue;
	}

	void setSeconds(unsigned newValue) {
		if (newValue >= 60) {
			newValue = 0;
		}

		seconds = newValue;
	}

	void addSecond() {
		++seconds;
		if (seconds >= 60) {
			++minutes;
			seconds = 0;
		}

		if (minutes >= 60) {
			++hours;
			minutes = 0;
		}

		if (hours >= 24) {
			hours = 0;
		}
	}

	Time getDifference(const Time& other) const {
		unsigned diff = myAbsDiff(this->getTotalSeconds(), other.getTotalSeconds());

		return Time(diff);
	}

	bool isEarlierThan(const Time& other) const {
		return this->getTotalSeconds() < other.getTotalSeconds();
	}

	unsigned getTotalSeconds() const {
		return hours * 60 * 60 + minutes * 60 + seconds;
	}

	void print() const {
		std::cout << hours << ":" << minutes << ":" << seconds;
	}
};
