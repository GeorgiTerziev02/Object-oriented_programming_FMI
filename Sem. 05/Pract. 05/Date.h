#pragma once
class Date
{
public:
	Date();

	Date(int, int, int);

	int getDay() const;
	int getMonth() const;
	int getYear() const;

	void setDay(int);
	void setMonth(int);
	void setYear(int);

	void addDays(int);
	void removeDays(int);

	bool isLeap() const;

	long daysToChristmas() const;
	long daysToEndOfYear() const;

	long daysToGivenDate(const Date&) const;
	long daysToGivenDate(int, int, int) const;

	bool isAfter(const Date&) const;
	bool isAfter(int, int, int) const;

private:
	int day;
	int month;
	int year;

	int MAX_DAYS_IN_MONTH[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int MAX_DAYS_IN_YEAR = 365;

	void increaseMonth();
	void decreaseMonth();

	long dateToDays(const Date&) const;
	long dateToDays(int, int, int) const;

	bool isDayValid(int) const;
	bool isMonthValid(int) const;
	bool isYearValid(int) const;
};

