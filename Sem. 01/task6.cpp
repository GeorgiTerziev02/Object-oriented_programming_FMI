#include <iostream>

using std::cout;
using std::cin;
using std::endl;

struct Point
{
	double x, y;
};

void GetPoint(Point& p)
{
	cin >> p.x >> p.y;
}

void PrintPoint(Point& p)
{
	cout << "(" << p.x << ";" << p.y << ")";
}

double GetDist(Point& p1, Point& p2)
{
	double dx = p2.x - p1.x;
	double dy = p2.y - p1.y;
	return sqrt((dx * dx) + (dy * dy));
}

double GetDistFromCenter(Point& p1)
{
	double dx = 0 - p1.x;
	double dy = 0 - p1.y;
	return sqrt((dx * dx) + (dy * dy));
}

void whichQuadrant(Point& p)
{
	if (p.x == 0 && p.y == 0)
	{
		cout << "center";
	}

	if (p.x >= 0 && p.y >= 0)
	{
		cout << "first";
	}
	else if (p.x <= 0 && p.y >= 0)
	{
		cout << "second";
	}
	else if (p.x <= 0 && p.y <= 0)
	{
		cout << "third";
	}
	else if (p.x >= 0 && p.y <= 0)
	{
		cout << "fourth";
	}
}

double myAbs(double n)
{
	return (n > 0) ? n : -n;
}

void CircleOrContour(double& r, Point& p)
{
	double distance = GetDistFromCenter(p);
	if (myAbs(distance - r) < 1e-9) // 1 multiplied by 10 to the power of 9
	{
		cout << "boundry";
	}
	else if (distance <= r)
	{
		cout << "in";
	}
	else
	{
		cout << "out";
	}
}

int main()
{
	Point p;
	GetPoint(p);
	cout << GetDistFromCenter(p) << endl;
	whichQuadrant(p);
	double r;
	cin >> r;
	CircleOrContour(r, p);
}