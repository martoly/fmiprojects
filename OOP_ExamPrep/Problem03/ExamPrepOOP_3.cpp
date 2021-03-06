#include "stdafx.h"
#include <iostream>

class FibGen
{
private:
	int *n;
	int size;
public:
	FibGen(int _n)
	{
		n = new int[_n];
		for (int i = 0; i < _n; i++)
		{
			if (i == 0) n[i] = i;
			else if (i == 1) n[i] = i;
			else n[i] = n[i - 1] + n[i - 2];
		}
		size = _n;
	}
	FibGen(const FibGen &other)
	{
		this->n = other.n;
		n = new int[*n];
		for (int i = 0; i < *n; i++)
		{
			this->n[i] = other.n[i];
		}
		this->size = other.size;
	}
	~FibGen()
	{
		delete[]n;
	}
	FibGen& operator=(const FibGen &other)
	{
		if (this != &other)
		{
			this->n = other.n;
			n = new int[*n];
			for (int i = 0; i < *n; i++)
			{
				this->n[i] = other.n[i];
			}
			this->size = other.size;
		}
		return *this;
	}
	friend std::ostream& operator<<(std::ostream &out, const FibGen &fib)
	{
		for (int i = 0; i < fib.size; i++)
		{
			out << fib.n[i] << std::endl;
		}
		return out;
	}
	int get(int _n)
	{
		if (this->size < _n)
		{
			int *temp = new int[_n];
			temp = this->n;
			int i = this->size -1;
			do
			{
				i++;
				temp[i] = temp[i - 1] + temp[i - 2];
			} while (i < _n -1);
			int result = temp[i];
			//delete[] temp;
			return result;
		}
		else 
		{
			return this->n[_n - 1];
		}
	}
};

int main()
{
	FibGen f1(10);
	std::cout << f1;
	std::cout << std::endl;
	std::cout << f1.get(8) << std::endl;
    return 0;
}

