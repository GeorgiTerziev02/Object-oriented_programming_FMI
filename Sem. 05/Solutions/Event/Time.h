#pragma once

class Time {
private:
    unsigned hours, minutes, seconds;

    Time(unsigned seconds);
public:
    Time();
    Time(unsigned hours, unsigned minutes, unsigned seconds);

    unsigned getHours() const;
    unsigned getMinutes() const;
    unsigned getSeconds() const;

    void setHours(unsigned newValue);
    void setMinutes(unsigned newValue);
    void setSeconds(unsigned newValue);

    void addSecond();

    unsigned getTotalSeconds() const;

    void print() const;

    /// @brief 
    /// @param other 
    /// @return -1 if this is before other, 0 if they are equal, 1 if this is after other
    int compare(const Time& other) const;
    /// @brief 
    /// @param other 
    /// @return number less than 0 if this is before other, 0 if they are equal, number greater than 0 if this is after other 
    int compare2(const Time& other) const;

    Time getDifference(const Time& other) const;

    Time getTimeToMidnight() const;
    bool isDinnerTime() const;
    bool isPartyTime() const;
};