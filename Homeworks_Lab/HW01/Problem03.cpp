// Problem03.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cmath>
#include <iostream>

using namespace std;
int main()
{ 
	int day, month;
	cin >> month >> day;
	int a = (14 - month) / 12;
	int b = 2017 - a; 
	int c = month + (12 * a) - 2;
	int d = (5 + day + b + (b / 4) + ((31 * c) / 12)) % 7;
	++d;
	switch (d)
	{
	case(1): cout << "Monday" << endl;
		break;
	case(2): cout << "Thuesday" << endl;
		break;
	case(3): cout << "Wednesday" << endl;
		break;
	case(4): cout << "Thursday" << endl;
		break;
	case(5): cout << "Friday" << endl;
		break;
	case(6): cout << "Saturday" << endl;
		break;
	case(7): cout << "Sunday" << endl;
		break;
	}
}

