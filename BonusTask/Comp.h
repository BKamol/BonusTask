#pragma once
#include "Vector.h"

class Comp : private Vector<double>
{
public:
	Comp();
	Comp(double _a, double _b);
	Comp(const Comp& other);
	~Comp();

	Comp operator+(const Comp& other);
	Comp operator*(const Comp& other);
	Comp operator*(int n);
	Comp& operator=(const Comp& other);
	double operator[](int index);

	friend istream& operator>>(istream& in, Comp& c);
	friend ostream& operator<<(ostream& out, const Comp& c);
};