#include <iostream>
#include <exception>
#include <math.h>

using namespace std;

struct Root {

public:
	Root(double paramx1, double paramx2) : x1(paramx1), x2(paramx2) {}
	Root() : x1(0),x2(0) {}
	void operator=(const Root& r) {
		this->x1 = r.get_x1();
		this->x2 = r.get_x2();
	}

	double get_x1()const {return x1;}
	double get_x2()const { return x2; }
private:
	double x1, x2;
};

class discriminantIsZeroException : public exception {
public:
	discriminantIsZeroException() : exception("Discriminant is zero") {}
};

class discriminantIsLessThanZeroException : public exception {
public:
	discriminantIsLessThanZeroException() : exception("Discriminant is less than zero") {}

};

double Discriminant(const double a,const double b,const double c) {
	return (b * b) - 4 * a * c;
}

Root quadraticSolver(const double a,const double b,const  double c) { 
	
	if (a == 0)
		throw runtime_error("Dividing by zero exception (a is 0).");
	const double discriminant = Discriminant(a, b, c);
	if (discriminant == 0)
		throw discriminantIsZeroException();
	else if(discriminant < 0)
		throw discriminantIsLessThanZeroException();
	
	const double rootIfDiscriminant = sqrt(discriminant);

	return Root((-b + rootIfDiscriminant) / (2 * a), (-b - rootIfDiscriminant) / (2 * a));
}

int main() {


	double a = 0, b = 2, c = 2;
	Root r;
	try {
		 r = quadraticSolver(a, b, c);
	}
	catch (exception e) {
		cout << e.what() << '\n';
		return 1;
	}
	cout << "Found roots: x1 = " << r.get_x1() << " x2 = " << r.get_x2() << '\n';
	if ((a * pow(r.get_x1(), 2) + b * r.get_x1() + c != 0))
		cout << "Wrong solution at x1. " << '\n';
	if ((a * pow(r.get_x2(), 2) + b * r.get_x2() + c != 0))
		cout << "Wrong solution at x2. " << '\n';

	return 0;
}