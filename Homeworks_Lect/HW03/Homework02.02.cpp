#include "stdafx.h"
#include <iostream>
using namespace std;

const int max = 10;

class Time {
private: 
	int hour, minutes, seconds;
public:
	Time();
	Time(int h, int m, int s);

	void setHour(int h);
	int getHour() const;

	void setMin(int m);
	int getMin() const;

	void setSec(int s);
	int getSec() const;

	void print();
	void read();
	bool isValid();
	void sort(int size, Time** list);
};

Time::Time() {
	hour = 24;
	minutes = 60;
	seconds = 60;
}

Time::Time(int h, int m, int s) {
	hour = h;
	minutes = m;
	seconds = s;
}

void Time::setHour(int h) {hour = h;}
int Time::getHour() const {return hour;}

void Time::setMin(int m) {minutes = m;}
int Time::getMin()const {return minutes;}

void Time::setSec(int s) {seconds = s;}
int Time::getSec()const { return seconds; }

void Time::print() {
	cout << hour << " HOURS - " << minutes << " MINUTES - " << seconds << " SECONDS" << endl;

}

void Time::read() {
	do {
		cout << "Enter the hours: "; cin >> hour;
		cout << "Enter the minutes: "; cin >> minutes;
		cout << "Enter the seconds: "; cin >> seconds;
		if (!isValid()) cout << "Enter a VALID time!" << endl;

	} while (!isValid());
}


bool Time::isValid() {
	return (!((hour >= 24 || hour < 0) || (minutes < 0 || minutes >= 60) || (seconds < 0 || seconds >= 60)));
}

void Time::sort(int size, Time** list) {
	for (int i = 0; i < size-1; i++)
	{
		if (list[i]->hour > list[i + 1]->hour) swap(list[i], list[i + 1]);
		if ((list[i]->hour >= list[i + 1]->hour) || (list[i]->minutes > list[i + 1]->minutes)) swap(list[i], list[i + 1]);
		if ((list[i]->minutes >= list[i + 1]->minutes) || (list[i]->seconds > list[i + 1]->seconds)) swap(list[i], list[i + 1]);

	}
}

int main()
{
	Time t;
	Time* list[max];

	int size; cout << "Enter the number of time values you would like to enter(<" <<  max << "): "; cin >> size;

	for (int i = 0; i < max; i++) list[i] = &t;

	cout << "Default time: ";  t.print();


	for (int i = 0; i < size; i++)
	{
		list[i]->read();
	}
	/*
	for (int i = 0; i < size; i++)
	{
		list[i]->print();
	}
	*/
    cout << "UNSORTED time values: " << endl;  t.print();
	cout << "SORTED time values: " << endl; t.sort(size, list); t.print();



    return 0;
}

