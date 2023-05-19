#include <cmath>
#include "Date.h"

Date::Date() : Date(1, 1, 2000) {}

Date::Date(int day, int month, int year)
{
	setYear(year);
	setMonth(month);
	setDay(day);
}

void Date::setYear(int year)
{
	if (!isYearValid(year))
		year = 2000;

	if (isLeap())
	{
		MAX_DAYS_IN_MONTH[1] = 29;
		MAX_DAYS_IN_YEAR = 366;
	}
	else
	{
		MAX_DAYS_IN_MONTH[1] = 28;
		MAX_DAYS_IN_YEAR = 365;
	}

	this->year = year;
}

void Date::setMonth(int month)
{
	if (!isMonthValid(month))
		month = 1;
	this->month = month;
}

void Date::setDay(int day)
{
	if (!isDayValid(day))
		day = 1;
	this->day = day;
}

int Date::getDay() const
{
	return day;
}

int Date::getMonth() const
{
	return month;
}

int Date::getYear() const
{
	return year;
}


bool Date::isLeap() const
{
	return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

void Date::addDays(int days)
{
	if (days < 0)
	{
		removeDays(-days);
		return;
	}

	while (days - MAX_DAYS_IN_YEAR >= 0)
	{
		days -= MAX_DAYS_IN_YEAR;
		setYear(year + 1);
	}

	while (days - MAX_DAYS_IN_MONTH[month - 1] >= 0)
	{
		days -= MAX_DAYS_IN_MONTH[month - 1];

		increaseMonth();
	}

	if (days + day > MAX_DAYS_IN_MONTH[month - 1])
	{
		setDay(days + day - MAX_DAYS_IN_MONTH[month - 1]);
		increaseMonth();
	}
	else
		setDay(days + day);
}

void Date::removeDays(int days)
{
	if (days < 0)
	{
		addDays(-days);
		return;
	}

	while (MAX_DAYS_IN_YEAR - days <= 0)
	{
		days -= MAX_DAYS_IN_YEAR;
		setYear(year - 1);
	}

	while (MAX_DAYS_IN_MONTH[month - 1] - days <= 0)
	{
		days -= MAX_DAYS_IN_MONTH[month - 1];

		decreaseMonth();
	}

	if (day - days < 1)
	{
		decreaseMonth();
		setDay(day - days + MAX_DAYS_IN_MONTH[month - 1]);
	}
	else
		setDay(day - days);
}

void Date::increaseMonth()
{
	if (month == 12)
	{
		setMonth(1);
		setYear(year + 1);
	}
	else
		setMonth(month + 1);
}

void Date::decreaseMonth()
{
	if (month == 1)
	{
		setMonth(12);
		setYear(year - 1);
	}
	else
		setMonth(month - 1);
}

long Date::daysToGivenDate(const Date& givenDate) const
{
	long daysInThisDate = dateToDays(*this);
	long daysInGivenDate = dateToDays(givenDate);

	return abs(daysInThisDate - daysInGivenDate);
}

long Date::daysToGivenDate(int day, int month, int year) const
{
	Date date(day, month, year);

	return daysToGivenDate(date);
}

long Date::daysToChristmas() const
{
	if (isAfter(25, 12, year))
		return daysToGivenDate(25, 12, year);

	return daysToGivenDate(25, 12, year + 1);
}

long Date::daysToEndOfYear() const
{
	if (isAfter(31, 12, year))
		return daysToGivenDate(31, 12, year);
	
	return daysToGivenDate(31, 12, year + 1);
}

bool Date::isAfter(const Date& date) const
{
	long daysInThisDate = dateToDays(*this);
	long daysInGivenDate = dateToDays(date);

	return daysInThisDate - daysInGivenDate < 0;
}

bool Date::isAfter(int day, int month, int year) const
{
	Date date(day, month, year);

	return isAfter(date);
}

bool Date::isDayValid(int day) const
{
	return day >= 1 && day <= MAX_DAYS_IN_MONTH[month - 1];
}

bool Date::isMonthValid(int month) const
{
	return month >= 1 && month <= 12;
}

bool Date::isYearValid(int year) const
{
	return year > 0;
}

long Date::dateToDays(const Date& date) const
{
	int dateDay = date.getDay();
	int dateMonth = date.getMonth();
	int dateYear = date.getYear();

	int leapYears = dateYear / 4 - dateYear / 100 + dateYear / 400;

	long yearToDays = leapYears * 366 + (dateYear - leapYears) * 365;
	long monthToDays = 0;

	while (dateMonth > 0)
	{
		monthToDays += MAX_DAYS_IN_MONTH[dateMonth - 1];
		dateMonth--;
	}

	return yearToDays + monthToDays + dateDay;
}

long Date::dateToDays(int day, int month, int year) const
{
	Date date(day, month, year);

	return dateToDays(date);
}