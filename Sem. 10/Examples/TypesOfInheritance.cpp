class A {
private:
	int a;
protected:
	int b;
public:
	int c;
};

// default is private
class PrivateDerived : A{
	void test() {
		// private members are not accessible inside derived classes
		// a inaccessible
		// b and c are inherited as private members
		b;
		c;
	}
};

class ProtectedDerived : protected A {
	void test() {
		// private members are not accessible inside derived classes
		// b and c inherited as protected members
		b;
		c;
	}
};

class ProtectedOfProtectedDerived : protected ProtectedDerived {
	void test2() {
		// b and c inherited as protected members
		b;
		c;
	}
};

class PublicDerived : public A {
	void test() {
		// private members are not accessible inside derived classes
		// b is protected
		// c is public
		b;
		c;
	}
};

void myMain() {
	PrivateDerived privateDerived;
	ProtectedDerived protectedDerived;
	PublicDerived publicDerived;

	// privateDerived.a;	// inaccessible
	// privateDerived.b;	// private for the class
	// privateDerived.c;	// private for the class

	// protectedDerived.a;  // inaccessible
	// protectedDerived.b;  // protected for the class
	// protectedDerived.c;  // protected for the class

	//publicDerived.a;		// inacessible
	//publicDerived.b;		// protected for the class
	publicDerived.c;		// public for the class
}