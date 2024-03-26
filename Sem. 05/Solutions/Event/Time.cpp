#include "Time.h"

#include <iostream>
#include <iomanip>

// if the namespace has name => can be accessed from other .cpp
namespace TimeConstants {
    const unsigned HOURS_IN_DAY = 24;
    const unsigned MINUTES_IN_HOUR = 60;
    const unsigned SECONDS_IN_MINUTE = 60;
    const unsigned SECONDS_IN_HOUR = 60 * 60;
};

Time::Time(unsigned seconds) {
    setSeconds(seconds % 60);
    seconds /= 60;
    setMinutes(seconds % 60);
    seconds /= 60;
    setHours(seconds);
}

Time::Time() : hours(0), minutes(0), seconds(0) {}

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
    if (newValue >= TimeConstants::HOURS_IN_DAY) {
        newValue = 0;
    }
    hours = newValue;
}

void Time::setMinutes(unsigned newValue) {
    if (newValue >= TimeConstants::MINUTES_IN_HOUR) {
        newValue = 0;
    }
    minutes = newValue;
}

void Time::setSeconds(unsigned newValue) {
    if (newValue > TimeConstants::SECONDS_IN_MINUTE) {
        newValue = 0;
    }
    seconds = newValue;
}

void Time::addSecond() {
    if (++seconds >= TimeConstants::SECONDS_IN_MINUTE) {
        ++minutes;
        seconds = 0;
    }
    if (minutes >= TimeConstants::MINUTES_IN_HOUR) {
        ++hours;
        minutes = 0;
    }
    if (hours >= TimeConstants::HOURS_IN_DAY) {
        hours = 0;
    }
}

unsigned Time::getTotalSeconds() const {
    return
        hours * TimeConstants::SECONDS_IN_HOUR +
        minutes * TimeConstants::SECONDS_IN_MINUTE +
        seconds;
}

void Time::print() const {
    std::cout
        << std::setw(2) << std::setfill('0') << getHours() << ":"
        << std::setw(2) << std::setfill('0') << getMinutes() << ":"
        << std::setw(2) << std::setfill('0') << getSeconds() << std::endl;
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

int Time::compare2(const Time& other) const {
    return getTotalSeconds() - other.getTotalSeconds();
}

Time Time::getDifference(const Time& other) const {
    unsigned currentSeconds = getTotalSeconds();
    unsigned otherSeconds = other.getTotalSeconds();
    unsigned difference = currentSeconds > otherSeconds 
        ? currentSeconds - otherSeconds
        : otherSeconds - currentSeconds;

    return Time(difference);
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