#include "Event.h"
#pragma warning(disable : 4996)

Event::Event(const char* name, const Date& date, const Time& startTime, const Time& endTime)
    : date(date), startTime(startTime), endTime(endTime)
{
    setName(name);
    validateTimes();
}

Event::Event(const char* name, unsigned day, unsigned month, unsigned year,
    unsigned startTimeHours, unsigned startTimeMins, unsigned startTimeSecs,
    unsigned endTimeHours, unsigned endTimeMins, unsigned endTimeSecs) : date(day, month, year),
    startTime(startTimeHours, startTimeMins, startTimeSecs),
    endTime(endTimeHours, endTimeMins, endTimeSecs)
{
    setName(name);
    validateTimes();
}
const char* Event::getName() const {
    return name;
}
const Date& Event::getDate() const {
    return date;
}
const Time& Event::getStartTime() const {
    return startTime;
}
const Time& Event::getEndTime() const {
    return endTime;
}

void Event::setName(const char* str) {
    if (!str || strlen(str) > EventConstants::MAX_NAME_LENGTH) {
        return;
    }
    
    strcpy(name, str);
}
void Event::setDate(const Date& date) {
    this->date = date;
}

void Event::setStartTime(const Time& startTime) {
    if (startTime.compare(endTime) >= 1) {
        return;
    }

    this->startTime = startTime;
}

void Event::setEndTime(const Time& endTime) {
    if (this->startTime.compare(endTime) >= 1) {
        return;
    }

    this->endTime = endTime;
}

void Event::validateTimes() {
    if (startTime.compare(endTime) >= 1) {
        std::swap(startTime, endTime);
    }
}

Event::Event() : Event("Unknown", 1, 1, 1, 0, 0, 0, 0, 0, 0) {}