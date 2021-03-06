#include <iostream>
#include "stdafx.h"

template <typename T>
class vector
{
private:
	T *elems;
	int capacity;
public:
	vector(int _capacity = 0)
	{
		capacity = _capacity;
		elems = new T[capacity];
	}
	~vector()
	{
		delete[]elems;
	}
	vector<T>& operator=(const vector<T> &other)
	{
		if (this != &other)
		{
			capacity = other.capacity;
			if (other.elems == nullptr) elems == nullptr;
			else
			{
				elems = new T[capacity];
				for (int i = 0; i < capacity; i++)
				{
					elems[i] = other.elems[i];
				}
			}
		}
		return *this;
	}
	vector(const vector &other)
	{
		capacity = other.capacity;
		if (other.elems == nullptr) elems == nullptr;
		else
		{
			elems = new T[capacity];
			for (int i = 0; i < capacity; i++)
			{
				elems[i] = other.elems[i];
			}
		}
	}
	vector<T>& operator+(int add)
	{
		std::cout << "Adding " << add << " to all elements..." << std::endl;
		for (int i = 0; i < capacity; i++)
		{
			elems[i] += add;
		}
		return *this;
	}
	vector<T>& operator+=(int add)
	{
		std::cout << "Adding " << add << " to all elements..." << std::endl;

		for (int i = 0; i < capacity; i++)
		{
			elems[i] += add;
		}
		return *this;
	}
	vector<T> operator[](int index)
	{
		if (index > capacity) std::cout << "No such index!" << std::endl;
		else
		{
			std::cout << "Element["<< index <<"]: "<<  elems[index] << std::endl;
			std::cout << "Do you want to overwrite it(Y/N): ";
			char input;
			std::cin >> input;
			if (input == 'Y' || input == 'y')
			{
				std::cout << "Write the new value of the element: ";
				std::cin >> elems[index];
				std::cout << "New value changed: " <<  "Element[" << index << "] = " << elems[index] << std::endl;
			}
			else
			{
				return *this;
			}
		}
		return *this;
	}
};

int main()
{
	
	vector<double> matrix[5][5];

    return 0;
}

