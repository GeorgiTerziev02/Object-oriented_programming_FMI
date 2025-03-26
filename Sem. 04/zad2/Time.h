#pragma once
class Time
{
public:
	Time();
	Time(int hour, int min, int sec);	

	int getHour() const;
	bool  setHour(int hour);

	int getMinute() const;
	bool setMinute(int min);

	int getSecond() const;
	bool setSecond(int sec);

	void AddTime(const Time& t);
	void printTime() const ;



private:
	int seconds;
};

