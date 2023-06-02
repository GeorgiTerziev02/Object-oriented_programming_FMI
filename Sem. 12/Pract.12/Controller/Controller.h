#pragma once

#include <iostream>

struct Size {
    size_t _width ;
    size_t _height;
    Size() : Size(0, 0) {};
    Size(size_t width, size_t height) : _width(width), _height(height) {};
};

struct Point {
    size_t _x = 0;
    size_t _y = 0;
    Point() : Point(0, 0) {};
    Point(size_t x, size_t y) : _x(x), _y(y) {};
};

class Controller {
private:
    Size _size;
    Point _coordinates;

public:
    Controller() = default;
    Controller(size_t width, size_t height, size_t x, size_t y);
    virtual ~Controller() = default;

    virtual void setDataDialog() = 0;
    virtual Controller *clone() const = 0;

    const Size &getSize() const;
    const Point &getCoordinates() const;

    void setSize(size_t width, size_t height);
    void setCoordinates(size_t x, size_t y);

};
