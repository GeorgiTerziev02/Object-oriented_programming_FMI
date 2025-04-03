#include "Time.h"
#include <iostream>

Time::Time(): seconds(0) 
{

}
Time::Time(int hour, int min, int sec)
{
	if (!setHour(hour) || !setMinute(min) || !setSecond(sec)) 
	{
		this->seconds = 0;
	}
	setHour(hour);
	setMinute(min);
	setSecond(sec);
		
}

int Time::getHour() const
{
	return this->seconds / 3600 ;
}
bool Time::setHour(int hour)
{
	if (hour < 0 || hour > 23)
		return false;
	this->seconds = hour * 3600 + this->seconds % 3600;
	
}

int Time::getMinute() const
{
	return this->seconds / 60 % 60;
}
bool Time::setMinute(int min)
{
	if (min < 0 || min > 59)
		return false;
	this->seconds = min * 60 + seconds / 3600 * 3600 + seconds % 60;
}


int Time::getSecond() const
{
	return this->seconds % 60;
}
bool Time::setSecond(int sec)
{
	if (sec < 0 || sec > 59)
		return false;
	this->seconds = seconds - getSecond() + sec;
}

void  Time::AddTime(const Time& t)
{

	seconds += t.seconds;
	seconds %= 24 * 3600;
}
void Time::printTime() const
{
	std::cout << getHour() << ":" << getMinute() << ":" << getSecond() << "\n";
}