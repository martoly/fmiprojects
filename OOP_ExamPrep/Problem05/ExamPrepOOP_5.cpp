#include "stdafx.h"
#include <iostream>
//just test
class abstr
{
public:
	virtual void print() const = 0;
	virtual int get() const = 0;
};

class inh1: public abstr
{
public: 
	virtual void print() const
	{
		std::cout << "Inheritance 1" << std::endl;
	}
	virtual int get() const
	{
		return 1;
	}
};

class inh2 : public abstr
{
public:
	virtual void print() const override
	{
		std::cout << "Inheritance 2" << std::endl;
	}
	virtual int get() const override
	{
		return 2;
	}
};

int main()
{
	inh1 i1;
	std::cout << i1.get() << std::endl;
	i1.print();

	inh2 i2;
	i2.print();
	std::cout << i2.get() << std::endl;
	//std::cin.get();
	abstr *a = new inh2;
	a = new inh1;
	a->print();
    return 0;
}

