#include "stdafx.h"
#include <iostream>
using namespace std;

class A
{
public:
	A(int = 4, int = 7);
	A(const A&);
	~A();
	void print() const;
	int get_x() const;
	int get_y() const;
private:
	int x, y;
};

A::A(int a, int b)
{
	cout << "A(" << a << "," << b << ")" << endl;
	x = a - 3;
	y = b + 1;
}

A::A(const A &p)
{
	cout << "A(const&)" << endl;
	x = p.x - 1;
	y = p.y + 2;
}

A::~A()
{
	cout << "~A(" << x << "," << y << ")" << endl;
}

void A::print() const
{
	cout << x << "," << y << endl;
}

int A::get_x() const
{
	return x;
}

int A::get_y() const
{
	return y;
}

class B
{
public:
	B(A, double);
	B(const B&);
	~B();
	void printu() const; 
	A get_a() const;
private:
	int *x;
	A a;
};

B::B(A e, double d)
{
	cout << "B(" << e.get_x() << "," << e.get_y() << "," << d << ")" << endl;
	x = new int(d);
	a = A(e);
}

B::B(const B &b)
{
	cout << "B(const B&)" << endl;
	x = new int(*b.x);
}

B::~B()
{
	cout << "~B(" << a.get_x() << "," << a.get_y() << "," << *x << ")" << endl;
}

void B::printu() const
{
	a.print();
	cout << *x << endl;
}

A B::get_a() const
{
	return a;
}

int main()
{
	A a(10), x(a);
	a.print();
	x.print();
	B b(a, 4.5);
	B c = b;
	b.printu();
	c.printu();
	b.get_a().print();
	c.get_a().print();

    return 0;
}

