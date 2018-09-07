#include "stdafx.h"
#include <iostream>
#include <cmath>

using namespace std;
int main()
{
	double a;
	int b;
	cin >> a >> b;
	double temp = a;
	if (b == 0) {
		temp = 1;
	}
	else if (b < 0) {
		for (int i = 0; i < (-b) - 1; i++) {
			temp *= a;
		}
		temp = 1 / temp;
	}
	else {
		for (int i = 0; i < b - 1; i++) {
			temp *= a;
		}
	}
	cout << temp << endl;
	return 0;
}