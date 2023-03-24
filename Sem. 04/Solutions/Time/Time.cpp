#include "Time.h"
#include <iostream> 

unsigned myAbsDiff(unsigned a, unsigned b) {
	return a > b ? a - b : b - a;
}

Time::Time(unsigned seconds) {
	this->seconds = seconds % 60;
	seconds /= 60;
	this->minutes = seconds % 60;
	seconds /= 60;
	this->hours = seconds;
}

Time::Time()/* : Time(0, 0, 0) */ {
	hours = minutes = seconds = 0;
}

Time::Time(unsigned hours, unsigned minutes, unsigned seconds) {
	setHours(hours);
	setMinutes(minutes);
	setSeconds(seconds);
}

unsigned Time::getHours() const {
	return hours;
}

unsigned Time::getMinutes() const {
	return minutes;
}

unsigned Time::getSeconds() const {
	return seconds;
}

void Time::setHours(unsigned newValue) {
	if (newValue >= 24) {
		newValue = 0;
	}
	hours = newValue;
}

void Time::setMinutes(unsigned newValue) {
	if (newValue >= 60) {
		newValue = 0;
	}
	minutes = newValue;
}

void Time::setSeconds(unsigned newValue) {
	if (newValue >= 60) {
		newValue = 0;
	}
	seconds = newValue;
}

void Time::addSecond() {
	if (++seconds >= 60) {
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

Time Time::getDifference(const Time& other) const {
	return Time(myAbsDiff(getTotalSeconds(), other.getTotalSeconds()));
}

int Time::compare(const Time& other) const {
	unsigned currentTotalSeconds = getTotalSeconds();
	unsigned otherTotalSeconds = other.getTotalSeconds();

	if (currentTotalSeconds == otherTotalSeconds) {
		return 0;
	}

	// 1 - the current is later, -1 the current is earlier
	return currentTotalSeconds > otherTotalSeconds ? 1 : -1;
}

Time Time::getTimeToMidnight() const {
	Time leftTime = getDifference(Time(23, 59, 59));
	leftTime.addSecond();

	return leftTime;
}

bool Time::isDinnerTime() const {
	Time lowerBound(20, 30, 0);
	Time upperBound(22, 0, 0);

	return compare(lowerBound) >= 0 && compare(upperBound) <= 0;
}

bool Time::isPartyTime() const {
	Time lowerBound(23, 0, 0);
	Time upperBound(6, 0, 0);
	
	return compare(lowerBound) >= 0 || compare(upperBound) <= 0;
}

unsigned Time::getTotalSeconds() const {
	return hours * 60 * 60 + minutes * 60 + seconds;
}

void Time::print() const {
	std::cout << hours << ":" << minutes << ":" << seconds << std::endl;
}