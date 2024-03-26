#pragma once
#include "Time/Time.h"
#include "Date/Date.h"

namespace EventConstants {
    constexpr size_t MAX_NAME_LENGTH = 20;
}

class Event {
private:
    char name[EventConstants::MAX_NAME_LENGTH + 1] = "Unknown";
    Date date;
    Time startTime;
    Time endTime;

    void validateTimes();
public:
    Event();
    Event(const char* name, const Date& date, const Time& startTime, const Time& endTime);

    Event(const char* name, unsigned day, unsigned month, unsigned year,
        unsigned startTimeHours, unsigned startTimeMins, unsigned startTimeSecs,
        unsigned endTimeHours, unsigned endTimeMins, unsigned endTimeSecs);

    const char* getName() const;
    void setName(const char* str);

    const Date& getDate() const;
    // Question: 
    // if there is no validation is there need of setter and getter
    void setDate(const Date& date);

    const Time& getStartTime() const;
    void setStartTime(const Time& startTime);

    const Time& getEndTime() const;
    void setEndTime(const Time& endTime);
};