#pragma once
#include <iostream>

using namespace std;

template <class T>
class Vector
{
protected:
	int size;
	T* arr;

public:
	Vector()
	{
		size = 0;
		arr = NULL;
	}

	Vector(int _size)
	{
		size = _size;
		arr = new T[size];
	}

	Vector(int _size, T* _arr)
	{
		size = _size;
		arr = _arr;
	}

	Vector(const Vector& a)
	{
		size = a.size;
		arr = new T[size];
		for (int i = 0; i < size; i++)
			arr[i] = a.arr[i];
	}

	~Vector()
	{
		delete[] arr;
	}

	Vector<T>& operator=(const Vector& other)
	{
		if (this == &other) return *this;
		if (arr != NULL) delete[] arr;
		arr = new T[other.size];
		for (int i = 0; i < other.size; i++)
			arr[i] = other.arr[i];
		return *this;
	}

	T& operator[](int index)
	{
		return arr[index];
	}

	Vector<T> operator+(const Vector& other)
	{
		Vector<T> result(max(size, other.size));
		if (size <= other.size)
		{
			for (int i = 0; i < size; i++)
				result.arr[i] = arr[i] + other.arr[i];
			for (int i = size; i < other.size; i++)
				result.arr[i] = other.arr[i];
		}
		else
		{
			for (int i = 0; i < other.size; i++)
				result.arr[i] = arr[i] + other.arr[i];
			for (int i = other.size; i < size; i++)
				result.arr[i] = arr[i];
		}
		return result;
	}

	Vector<T> operator*(const Vector& other)
	{
		Vector<T> result(max(size, other.size));
		if (size == other.size)
		{
			for (int i = 0; i < size; i++)
			{
				result.arr[i] = arr[i] * other.arr[i];
			}
		}
		else
		{
			if (size < other.size)
			{
				for (int i = 0; i < size; i++)
					result.arr[i] = arr[i] * other.arr[i];
				for (int i = size; i < other.size; i++)
					result.arr[i] = other.arr[i] * 0;
			}
			else
			{
				for (int i = 0; i < other.size; i++)
					result.arr[i] = arr[i] * other.arr[i];
				for (int i = other.size; i < size; i++)
					result.arr[i] = arr[i] *  0;
			}
		}
		
		return result;
	}

	friend istream& operator>>(istream& in, Vector<T>& a)
	{
		for (int i = 0; i < a.size; i++)
			in >> a.arr[i];

		return in;
	}

	friend ostream& operator<<(ostream& out, const Vector<T>& a)
	{
		out << "( ";
		for (int i = 0; i < a.size; i++)
			out << a.arr[i] << ' ';
		out << ")" << endl;
		return out;
	}
};





