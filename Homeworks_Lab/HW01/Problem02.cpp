// Problem02.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	int x, y, q, z;

	cin >> x >> y >> q >> z;
	if ( (q == (x + 1)) && ( (z == (y + 2)) || (z == (y-2)) ) || (q== (x - 1)) && ( (z == (y - 2)) || (z == (y+2))) 
		(q == (x + 2)) && ((z == (y + 1)) || (z == (y -1))) || (q == (x - 2)) && ((z == (y - 1)) || (z == (y + 1))))
	{
		cout << "Valid" << endl;
	}
	else {
		cout << "Invalid" << endl;
	}
    return 0;
}

