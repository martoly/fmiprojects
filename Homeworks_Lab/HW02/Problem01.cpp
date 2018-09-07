// Problem01.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	int n,temp = 1, counter = 0;
	cin >> n;
	while (n) 
	{
		temp *= (n % 10);
		n /= 10;
	}
	while (temp) {
		temp /= 10;
		counter++;
	}

	cout << counter << endl;
	return 0;
}

