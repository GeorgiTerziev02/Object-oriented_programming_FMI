#include <iostream>

class Time{
private:
	unsigned hours, minutes, seconds;
public:
	Time() : hours(0), minutes(0), seconds(0) { }
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
        if(newValue > 23) {
            newValue = 0;
        } 
        hours = newValue;
    }
	void setMinutes(unsigned newValue) {
        if(newValue > 59) {
            newValue = 0;
        } 
        minutes = newValue;
    }
	void setSeconds(unsigned newValue) {
        if(newValue > 59) {
            newValue = 0;
        } 
        seconds = newValue;
    }

    void addSecond() {
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
   
    void Time::print() const {
    	std::cout << hours << ":" << minutes << ":" << seconds << std::endl;
    }
};