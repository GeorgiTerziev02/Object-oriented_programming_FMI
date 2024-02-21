#include <iostream>

struct Point{
    int x = 0, y = 0;
};

void readPoint(Point& p) {
    std::cin >> p.x >> p.y;
}

void printPoint(const Point& p) {
    std::cout << p.x << " " << p.y << std::endl;
}

int main() {
    Point p{1,2};
    Point p2 = {1,2};
    Point* p3 = new Point{1,2};
    Point* arr = new Point[5]; // why is this bad?

    std::cout << p.x << " " << p.y << std::endl;
    
    delete p3;
    delete[] arr;
}