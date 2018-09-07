#include "stdafx.h"
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	char x[100];
	int numbers[100]{}, times[100]{}, counter[100]{}, t = 0, r = 0, j = 0;
	cin >> x;
	
	for (int i = 0; i < strlen(x); i++)
	{
		if ((x[i] >= 48) && (x[i] <= 57)) {
			numbers[j] = x[i] - 48; //kakvi cifri ima v string-a
			j++;
			r++;
			counter[t] = r; //kolko cifreni sa chislata
		}
		else {
			r = 0;
			t++;
		}
	}

	int k = 0, s = 0, y = 0, p = 0;
	for (int i = 0; i < strlen(x); i++) {

		if ((x[y+p] >= 48) && (x[y+p] <= 57)) {
			times[y+p] += numbers[i] * pow(10, counter[k] - (s + 1));
			if (counter[k] - (s + 1) == 0) {
				k++;
				s = 0;
				y++;
			}
			else s++;

		}

		if (((x[i] >= 91) && (x[i] <= 122)) && ((x[i + 1] >= 91) && (x[i + 1] <= 122))) {
			times[y] = 1;
			p = 1;
			i--;
		}
	}

	bool isChar = 1;
	int z = 0, c = 0;
	for (int i = 0; i < strlen(x); i++)
	{
		if (((x[i] >= 91) && (x[i] <= 122)) && isChar) {
			do {
				cout << x[i];
				z++;
			} while (z < times[c]);
			z = 0;
			c++;
		}
	}
	cout << endl;
	
	
	return 0;
}

