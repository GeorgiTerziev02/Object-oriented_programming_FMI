#include <iostream>
using std::cin;
using std::cout;
using std::endl;

struct Point {
    double x;
    double y;
};

void readPoint(Point& p) {
    cout << "Enter X and Y: ";
    cin >> p.x >> p.y;
}

void printPoint(const Point& p) {
    cout << '(' << p.x << "; " << p.y << ')' << endl;
} 

double findDistanceFromCenter(const Point& p) {
    double sum = p.x + p.y;
    double distance = sqrt(abs(sum));

    return distance;
}

double square(const double number) {
    double squareNum = number * number;
    
    return squareNum;
}

double findDistanceBetweenTwoPoints(const Point& p1, const Point& p2) {
    double subsX = p1.x - p2.x;
    double subsY = p1.x - p2.x;
    double sum = square(subsX) + square(subsY);
    double distance = sqrt(abs(sum));

    return distance;
}

void quadrantByPositiveX(unsigned short& quadrant, double y) {
    if (y > 0) {
        quadrant = 1;
    }
    else {
        quadrant = 4;
    }
}

void quadrantByNegativeX(unsigned short& quadrant, double y) {
    if (y > 0) {
        quadrant = 2;
    }
    else {
        quadrant = 3;
    }
}

unsigned short findQuadrant(const Point& p) {
    unsigned short quadrant = 0;

    if (p.x > 0) {
        quadrantByPositiveX(quadrant, p.y);
    }
    else {
        quadrantByNegativeX(quadrant, p.y);
    }

    return quadrant;
}

void printIsInCircle(const short isInCircle) {
    switch (isInCircle) {
        case 1: cout << "Point is inside the circle!"; break;
        case 0: cout << "Point is on the contur!"; break;
        case -1: cout << "Point is outside the circle!"; break;
        default: cout << "Error!"; break;
    }
}

void isPointInCircle(const double radius, const Point& p) {
    short isInCircle;
    
    if (abs(p.x) < radius && abs(p.y) < radius) {
        isInCircle = 1;
    }
    else if (abs(p.x) == radius || abs(p.y) <= radius) {
        isInCircle = 0;
    }
    else {
        isInCircle = -1;
    }

    printIsInCircle(isInCircle);
}

int main()
{
    Point p1;
    Point p2;

    readPoint(p1);
    readPoint(p2);

    printPoint(p1);
    printPoint(p2);

    cout.precision(findDistanceFromCenter(p1)); // percision delete some symbols after comma(,)
    cout << "Distance from Center: " << findDistanceFromCenter(p1) << endl;
    cout << "Distance from Center: " << findDistanceFromCenter(p2) << endl;

    cout << "Distance between two point: " << findDistanceBetweenTwoPoints(p1, p2) << endl;

    cout << "Quadrant: " << findQuadrant(p1) << endl;
    cout << "Quadrant: " << findQuadrant(p2) << endl;

    double radius;
    cin >> radius;
    Point p3;
    readPoint(p3);
    isPointInCircle(radius, p3);
}