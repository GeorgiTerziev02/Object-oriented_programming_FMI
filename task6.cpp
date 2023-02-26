#include <iostream>
using namespace std;
struct Point {
    int x, y;
};
void readPoint(Point& point) {
    cout << "X: ";
    cin >> point.x;
    cout << endl;
    cout << "Y: ";
    cin >> point.y;
    cout << endl;
}
void printPoint(const Point& point) {
    cout << "X: " << point.x << endl;
    cout << "Y: " << point.y << endl;
}
double distanceFromCenter(const Point& point) {
    return sqrt(point.x * point.x + point.y * point.y);
}
double distanceBetweenPoint(const Point& point1, const Point& point2) {
    int dx = point1.x - point2.x;
    int dy = point1.y - point2.y;
    return sqrt(dx * dx + dy * dy);
}
int quadrant(const Point& point) {
    if (point.x >= 0 && point.y >= 0) {
        return 1;
    }
    else if (point.x <= 0 && point.y >= 0) {
        return 2;
    }
    else if (point.x <= 0 && point.y <= 0) {
        return 3;
    }
    else {
        return 4;
    }
}
bool doesItBelong(Point& point, double& r) {
    if (distanceFromCenter(point) - r < 0) {
        return false;
    }
    else true;
}
int main()
{
    Point point1, point2;
    double r = 5.00;
    readPoint(point1);
    readPoint(point2);
    printPoint(point1);
    printPoint(point2);
    cout<<"Distance of point 1 to the center: "<< distanceFromCenter(point1)<<endl;
    cout<<"Distance between point 1 and point 2: " << distanceBetweenPoint(point1, point2)<<endl;
    cout << "Quadrant of point 1: " << quadrant(point1) << endl;
    cout << "Quadrant of point 1: " << quadrant(point2) << endl;
    cout<< boolalpha << "Does point 1 belong to a circle with radius " << r << ":" << doesItBelong(point1, r)<<endl;
}