#include "stdafx.h"
#include <iostream>
#include "Time.h"
#include <cmath>
using namespace std;

class Appointment
{
	friend ostream& operator<<(ostream& out, const Appointment &a);
public:
	Appointment(const Time &t = Time(), char *name = ""); 
	Appointment(const Appointment &a);
	~Appointment();
	Appointment& operator=(const Appointment &a);

	void removeAppointment(Time &temp);
	Appointment& getAppointment() { return *this; }
	unsigned setTime();
	Time& getTime() { return time; }
private:
	void copy(const Appointment &a);
	void del();
	Time time;
	char* person;
};

Appointment::Appointment(const Time &t, char *name) 
{
	int len = strlen(name) + 1;
	person = new char[len];
	strcpy_s(person, len, name);
	time = t;
} 

Appointment::Appointment(const Appointment &a)
{
	copy(a);
}

Appointment::~Appointment()
{
	del();
}

Appointment& Appointment::operator=(const Appointment &a)
{
	if (this != &a)
	{
		del();
		copy(a);
	}
	return *this;
}

void Appointment::del()
{
	//delete time;
	delete[] person;
}

void Appointment::copy(const Appointment &a)
{
	time = a.time;
	int len = strlen(a.person) + 1;
	person = new char[len];
	strcpy_s(person, len, a.person);
}

ostream& operator<<(ostream& out, const Appointment &a)
{
	return out << a.time << a.person << endl;
}

void Appointment::removeAppointment(Time &temp)
{
	delete &temp;
	this->person = " ";
}


class Schedule
{
	friend ostream& operator<<(ostream &out, const Schedule &s);
public:
	Schedule();
	Schedule(const Schedule &s);
	~Schedule();
	Schedule& operator=(const Schedule &s);
	int getSize() const { return size; }
	void addAppointment(const Appointment &a);
	void clearBetween(Time &t1, Time &t2);
	void clear();
	void sort();
	Time& operator[](int pos);
private:
	void copy(const Schedule &a);
	void del();
	unsigned size;
	unsigned capacity;
	Appointment *container;
};

Schedule::Schedule(): container{nullptr}
{
	size = 0;
	capacity = 0;
}

Schedule::Schedule(const Schedule &s)
{
	copy(s);
}

Schedule::~Schedule()
{
	del();
}

Schedule& Schedule::operator=(const Schedule &s)
{
	if (this != &s)
	{
		del();
		copy(s);
	} return *this;
}

void Schedule::copy(const Schedule &a)
{
	size = a.size;
	capacity = a.capacity;

	if (container != nullptr)
	{
		delete[] container;
	}

	container = new Appointment[capacity];

	for (int i = 0; i < size; i++)
	{
		container[i] = a.container[i];

	}
}

void Schedule::del()
{
	delete[] container;
}

void Schedule::addAppointment(const Appointment &a)
{
	if (size == capacity)
	{
		capacity = size == 0 ? capacity = 1 : capacity * 2;
		Appointment *temp = container;
		container = new Appointment[capacity];
		for (int i = 0; i < size; i++)
		{
			container[i] = temp[i];
		}
		delete[] temp;
	};
	container[size++] = a;
}

void Schedule::clearBetween(Time &t1, Time &t2)
{
	for (int i = 0; i < size; i++)
	{
		if (container[i].getTime() > t1 && container[i].getTime() < t2)
		{
			for (int i = 0; i < size -1; i++)
			{
				container[i] = container[i + 1];
			}
			size--;
		}
	}
}

//грешна!
void Schedule::clear()
{
	sort();
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - 1; j++)
		{
			if ((container[i].getTime().getMinutes() - container[j].getTime().getMinutes() < 30) 
				|| (container[i].getTime().getHours() - container[j].getTime().getHours() == 1 
				&& (container[i].getTime().getMinutes() - container[j].getTime().getMinutes() > 30))
				&& i !=j)
			{
				container[i].removeAppointment(container[i].getTime());
			}
		}
		
	}
}

void Schedule::sort()
{
	for (int i = 0; i < size-1; i++)
	{
		if (container[i].getTime().getTime() < container[i + 1].getTime().getTime()) swap(container[i], container[i + 1]);
	}
}


Time& Schedule::operator[](int pos)
{
	return container[pos].getTime().getTime();
}

ostream& operator<<(ostream &out, const Schedule &s)
{
	for (int i = 0; i < s.size; i++)
	{
		out << s.container[i].getAppointment() << endl;
	}
	return out;
}


int main()
{
	Time t1(20, 30), t2(15,40), t3(16, 00);
	Appointment container[] = { {t1, "Ivan Mihov"}, {t2, "Sisa Radoeva"}, {t3, "Momchil Pussev"} };
	Schedule s1;
	s1.addAppointment(container[0]);
	s1.addAppointment(container[1]);
	s1.addAppointment(container[2]);

	cout << s1 << endl;
	s1.sort();
	cout << s1 << endl;
	s1.clear();
	cout << s1 << endl;
	cin.get();
    return 0;
}