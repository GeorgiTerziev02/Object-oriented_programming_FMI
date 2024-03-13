#include <iostream>

class Interval {
private:
    int start, end;

public:
    Interval() : Interval(0, 0) { }

    Interval(int start, int end) : start(start), end(end) {
        if(start > end) {
            this->start = this->end = 0;
        }
    }

    int getStart() const {
        return start;
    }

    int getEnd() const {
        return end;
    }

    void setStart(int newValue) {
        if(newValue > end) {
            return;
        }
        start = newValue;
    }

    void setEnd(int newValue) {
        if(newValue < start) {
            return;
        }
        end = newValue;
    }

    unsigned getLength() const {
        return end - start + 1;
    }

    bool isInInterval(int value) const {
        return start <= value && value <= end;
    }

    void print() const {
        std::cout << start << " - " << end << std::endl;
    }
};
