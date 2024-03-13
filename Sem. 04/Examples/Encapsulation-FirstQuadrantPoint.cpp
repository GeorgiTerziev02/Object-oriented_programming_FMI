#include <iostream>
#include <fstream>

// X and Y of every instance of FirstQuadrantPoint
// should be non-negative
struct FirstQuadrantPoint {
private: // can not be accessed from outside
	int x, y;

public: // can be accessed from outside
	FirstQuadrantPoint(int x, int y) : x(0), y(0) {
		setX(x);
		setY(y);
	}

	// returning copy so that the original value can not be changed
	int getX() const {
		return x;
	}

	// the only way to change the value of x
	// every time the validation is applied
	void setX(int value) { 
		if (value < 0) {
			return;
		}
		x = value;
	}

	int getY() const {
		return y;
	}

	void setY(int value) {
		if (value < 0) {
			return;
		}
		y = value;
	}
};

int main() {
	{
		FirstQuadrantPoint p(1, 2);
		p.setY(-100);
		p.setY(-100);
		p.setY(100);
		std::cout << p.getX() << " " << p.getY(); // 1 100
	}
	{
		FirstQuadrantPoint p(-1, -2);
		p.setY(-100);
		p.setY(-100);
		p.setY(100);
		std::cout << p.getX() << " " << p.getY(); // 0 100
	}
}