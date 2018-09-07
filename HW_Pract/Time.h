#pragma once
#ifndef TIME_H
#define TIME_H

#include <iostream>
using namespace std;

class Time
{
	//operators
	friend Time& operator+(const Time &t, const int x);
	friend Time& operator+(const int x, const Time &t);
	friend Time& operator+(const Time &t1, const Time &t2);
	friend bool operator>(const Time &t1, const Time &t2);
	friend bool operator<(const Time& t1, const Time &t2);
	friend ostream& operator<<(ostream &out, const Time &t);
	friend istream& operator >> (istream &is, Time &t);
	
	//friend Time& checkTime(Time &t);
public:
	Time();
	Time(int, int);

	void setHours(int);
	void setMinutes(int);
	void setTime(int, int);

	unsigned getHours() const { return hours; }
	unsigned getMinutes() const { return minutes; }
	Time &getTime() { return *this; }
	void reset();

	//operators
	Time& operator=(const Time &t);
	int operator-(const Time &t);
	Time& operator++(int x);
	Time& operator++();
	Time& operator+=(int x);
	bool operator==(const Time &t);
	bool operator!=(const Time &t);
private:
	unsigned hours;
	unsigned minutes;
	int check_m(int);
	int check_h(int);
	Time& checkTime(Time &t);
};

Time& Time::operator=(const Time &t)
{
	hours = t.hours;
	minutes = t.minutes;
	return *this;
}

ostream& operator<<(ostream &out, const Time &t)
{
	return out << "<" << t.hours << ":" << t.minutes << ">" << endl;
}

istream& operator >> (istream &is, Time &t)
{
	cout << "Enter hour: ";
	is >> t.hours;
	cout << "Enter minutes: ";
	is >> t.minutes;
	return is;
}

Time& Time::operator+=(int x)
{
	*this = *this + x;
	return checkTime(*this);
}

bool Time::operator==(const Time &t)
{
	return ((hours == t.hours) && (minutes == t.minutes));
}

bool Time::operator!=(const Time &t)
{
	return !(*this == t);
}

bool operator>(const Time &t1, const Time &t2)
{
	return (t1.getHours() > t2.getHours()) || (t1.getHours() == t2.getHours() && t1.getMinutes() > t2.getMinutes());
}

bool operator<(const Time &t1, const Time &t2)
{
	return !(t2 > t1);
}

Time& Time::operator++()
{
	this->setMinutes(this->getMinutes() + 1);
	return checkTime(*this);
}

Time& Time::operator++(int x)
{
	Time temp = *this;
	this->minutes++;
	return checkTime(temp);
}

int Time::operator-(const Time &t)
{
	minutes = ((this->getHours() - t.getHours()) * 60) + this->getMinutes() - t.getMinutes();
	return minutes;
}

Time& operator+(const Time  &t1, const Time &t2)
{
	Time newTime(t1.hours + t2.hours, t1.minutes + t2.minutes);
	return newTime;
}

Time& operator+(const Time &t, const int x)
{
	Time newTime(t.hours + x, t.minutes + x);

	return newTime;
}

Time& operator+(const int x, const Time &t)
{
	Time newTime(t.hours + x, t.minutes + x);
	return newTime;
}

Time::Time()
{
	hours = 0;
	minutes = 0;
}

int Time::check_m(int m)
{
	if (m / 60 >= 1)
	{
		while (m > 60)
		{
			m %= 60;
		}
	}
	return m;
}

int Time::check_h(int h)
{
	if (h % 24 == 0)
	{
		h = 0;
	}
	else if (h > 24)
	{
		while (h > 24)
		{
			h %= 24;
		}
	}
	return h;
}

Time::Time(int h, int m)
{
	int temp_m = m / 60;
	minutes = check_m(m);
	int temp_h = h % 24;
	hours = check_h(h) + temp_m;
}

Time& Time::checkTime(Time &t)
{
	int temp_m = t.minutes / 60;

	t.check_h(t.minutes);
	t.check_h(t.hours);

	t.hours = t.check_h(t.hours) + temp_m;
	return t;
}

void Time::setHours(int h)
{
	hours = h;
}

void Time::setMinutes(int m)
{
	minutes = m;
}

void Time::setTime(int h, int m)
{
	setHours(h);
	setMinutes(m);
}

void Time::reset()
{
	hours = 0;
	minutes = 0;
}
#endif // !TIME_H
