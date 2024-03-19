#include <iostream>
#include <iomanip>

namespace TimeConstants {
    const unsigned HOURS_IN_DAY = 24;
    const unsigned MINUTES_IN_HOUR = 60;
    const unsigned SECONDS_IN_MINUTE = 60;
};

class Time {
private:
    unsigned hours, minutes, seconds;

public:
    Time() : hours(0), minutes(0), seconds(0) {}

    Time(unsigned hours, unsigned minutes, unsigned seconds) {
        setHours(hours);
        setMinutes(minutes);
        setSeconds(seconds);
    }

    unsigned getHours() const {
        return hours;
    }

    unsigned getMinutes() const {
        return minutes;
    }

    unsigned getSeconds() const {
        return seconds;
    }

    void setHours(unsigned newValue) {
        if (newValue >= TimeConstants::HOURS_IN_DAY) {
            newValue = 0;
        }
        hours = newValue;
    }

    void setMinutes(unsigned newValue) {
        if (newValue >= TimeConstants::MINUTES_IN_HOUR) {
            newValue = 0;
        }
        minutes = newValue;
    }

    void setSeconds(unsigned newValue) {
        if (newValue > TimeConstants::SECONDS_IN_MINUTE) {
            newValue = 0;
        }
        seconds = newValue;
    }

    void addSecond() {
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

    void print() const {
		std::cout
            << std::setw(2) << std::setfill('0') << getHours() << ":" 
	        << std::setw(2) << std::setfill('0') << getMinutes() <<  ":" 
		    << std::setw(2) << std::setfill('0') << getSeconds() << std::endl;
    }
};
