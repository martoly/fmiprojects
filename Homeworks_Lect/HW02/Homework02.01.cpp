#include "stdafx.h"
#include <iostream>
#include <cmath>
using namespace std;

struct Rect {
	double	x1, y1, 
			x2, y2, 
			height, width, 
			p, s,
			x3, y3;
};

void readPoints(Rect &t) {
	bool flag = 0;
	cout << "Enter the X of the TOP LEFT point: "; cin >> t.x1;
	cout << "Enter the Y of the TOP LEFT point: "; cin >> t.y1;
	cout << "Firs point: " << "( " << t.x1 << " , "
		<< t.y1 << " )" << endl;
	cout << endl;

	do {
		if (flag) cout << "The second point must be to the botoom right cordner! Please enter correct coordinates: " << endl;
		flag = 1;
		cout << "Enter the X of the BOTTOM RIGHT point: "; cin >> t.x2;
		cout << "Enter the Y of the BOTTOM RIGHT point: "; cin >> t.y2;
		cout << "Second point: " << "( " << t.x2 << " , "
			<< t.y2 << " )" << endl;
		cout << endl;
	} while (t.x2 <= t.x1 || t.y2 >= t.y1);
}

void parameters(Rect &t) {
	t.width = abs(t.x2 - t.x1);

	t.height = abs(t.y1 - t.y2);

	cout << "The HEIGHT of the figure is: " << t.height << endl;
	cout << "The WIDTH of the figure is: " << t.width << endl;
	cout << endl;
}

void findSP(Rect &t) {
	t.s = t.height*t.width;
	t.p = 2 * t.height + 2 * t.width;
	cout << "The AREA of the figure is: " << t.s << endl;
	cout << "The PERIMETER of the figure is: " << t.p << endl;
	cout << endl;
}

bool isInside(Rect &p) {
	cout << "Enter coordinates of the new point:" << endl;
	cout << "Enter X: "; cin >> p.x3;
	cout << "Enter Y: "; cin >> p.y3;
	cout << "Is the point in the rectangle: ";

	if (p.x3 >= p.x1 && p.x3 <= p.x2
		&& p.y3 <= p.y1 && p.y3 >= p.y2) return 1;

	return 0;
}


int main()
{
	Rect t;

	readPoints(t);
	parameters(t);
	findSP(t);
	cout << boolalpha << isInside(t) << endl;
	
	return 0;
}