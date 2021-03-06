#include "stdafx.h"
#include <iostream>

class vector
{
public:
	vector(int *_a = new int[3], int _size = 3)
	{
		//if (a != nullptr) delete[]a;
		a = new int[_size];
		size = _size;
		for (int i = 0; i < size; i++)
		{
			std::cin >> a[i];
		}
	}
	vector& operator=(const vector &other)
	{
		if (this != &other)
		{
			del();
			copy(other);
		}
		return *this;
	}
	~vector()
	{
		del();
	}
	vector(const vector &other)
	{
		copy(other);
	}
	vector(int _size)
	{
		if (a != nullptr) delete[]a;
		a = new int[_size];
		size = _size;
		for (int i = 0; i < size; i++)
		{
			std::cin >> a[i];
		}
	}
	vector& operator+( vector &other)
	{
		if (this->size == other.size)
		{
			for (int i = 0; i < size; i++)
			{
				this->a[i] += other.a[i];
			}
		}
		else if(this->size > other.size)
		{
			helpAdd(other);
			for (int i = 0; i < this->size; i++)
			{
				this->a[i] += other.a[i];
			}
		}
		else
		{
			helpAdd(*this);
			for (int i = 0; i < this->size; i++)
			{
				this->a[i] += other.a[i];
			}
		}


		return *this;
	}
	friend vector& operator*(int mult, vector &v)
	{
		for (int i = 0; i < v.size; i++)
		{
			v.a[i] *= mult;
		}
		return v;
	}
	vector& operator*(int mult)
	{
		for (int i = 0; i < this->size; i++)
		{
			this->a[i] *= mult;
		}
		return *this;
	}
	friend std::ostream& operator<<( std::ostream &out, vector v)
	{
		for (int i = 0; i < v.size; i++)
		{
			out << v.a[i];
			if (i < v.size - 1) out << ", ";
		}
		out << std::endl;
		return out;
	}
private:
	int *a;
	int size;
	void del()
	{
		delete[] a;
	}
	void copy(const vector &other)
	{
		//if (a != nullptr) delete[]a;
		this->size = other.size;
		this->a = new int[size];
		for (int i = 0; i < size; i++)
		{
			this->a[i] = other.a[i];
		}
	}
	void helpAdd(vector &other)
	{
		int oldS = other.size;
		other.size = this->size;
		vector temp = other;
		delete[]other.a;
		other.a = new int[size];
		for (int i = 0; i < other.size; i++)
		{
			if (i < oldS) other.a[i] = temp.a[i];
			else other.a[i] = 0;
		}
	}
};

int main()
{
	vector v1;
	vector v2(5);
	std::cout << v2;
	v2 * 3;
	std::cout << v2;
	std::cout << v1;
	v2 + v1;
	std:: cout << v2;

	6 * v1;
	std::cout << v1;

	//std::cin.get();
    return 0;
}

