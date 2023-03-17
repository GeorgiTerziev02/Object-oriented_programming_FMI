class Interval{
private:
    int a, b;
public:
    Interval();
    Interval(int a, int b);

	int getA() const;
	int getB() const;
        
	void setA(int);
	void setB(int);

    unsigned getLength() const;
    bool isInInterval(int) const;

    // TODO:
    // primenumbers
    // palindorms
    // uniquedigits 
    // startendpowof2
    // intersec
    // subinterval
};

Interval::Interval() : Interval(0, 0) { }

Interval::Interval(int a, int b) {
    if(a > b) {
        a = b = 0;
    }

    this->a = a;
    this->b = b;
}

int Interval::getA() const {
	return a;
}

int Interval::getB() const {
	return b;
}

void Interval::setA(int a) {
	if (a > b) {
		return;
    }

	this->a = a;
}

void Interval::setB(int b) {
	if (b < a) {
        return;
    }
    
	this->b = b;
}

unsigned Interval::getLength() const {
    return b - a + 1;
}

bool Interval::isInInterval(int x) const
{
	return a <= x && x <= b;
}