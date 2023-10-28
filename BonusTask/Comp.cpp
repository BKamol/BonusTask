#include "Comp.h"

Comp::Comp()
{
	size = 2;
	arr = new double[2];
	arr[0] = 0;
	arr[1] = 0;
}

Comp::Comp(double _a, double _b)
{
	size = 2;
	arr = new double[2];
	arr[0] = _a;
	arr[1] = _b;
}

Comp::Comp(const Comp& other)
{
	size = 2;
	arr = new double[2];
	arr[0] = other.arr[0];
	arr[1] = other.arr[1];
}

Comp::~Comp() noexcept
{
}

Comp Comp::operator+(const Comp& other)
{
	return Comp(arr[0] + other.arr[0], arr[1] + other.arr[1]);
}

Comp Comp::operator*(const Comp& other)
{
	return Comp(arr[0] * other.arr[0] - arr[1] * other.arr[1], arr[0] * other.arr[1] + arr[1] * other.arr[0]);
}

Comp Comp::operator*(int n)
{
	return Comp(arr[0]*n, arr[1]*n);
}

Comp& Comp::operator=(const Comp& other)
{
	if (this == &other) return *this;
	if (arr != NULL) delete[] arr;
	arr = new double[2];
	arr[0] = other.arr[0];
	arr[1] = other.arr[1];
	return *this;
}

double Comp::operator[](int index)
{
	if (index > 1)
	{
		cout << "Only 2 elems in Comp" << endl;
		return arr[0];
	}
	return arr[index];
}

istream& operator>>(istream& in, Comp& c)
{
	in >> c.arr[0] >> c.arr[1];
	return in;
}

ostream& operator<<(ostream& out, const Comp& c)
{
	out << c.arr[0] << "+" << c.arr[1] << "i";
	return out;
}

