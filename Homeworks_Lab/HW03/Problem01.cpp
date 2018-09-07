#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

const int a = 1000;

int main()
{
	int arr[a], realSize, y = 0,counter;
	string x;
	bool isMonotonic = true;
	bool test1 = 0,test2=0;
	cin >> realSize;
	counter = realSize-1;

	for (int i = 0; i < realSize; i++) { cin >> arr[i]; }

	for (int i =0; i < realSize;i++) {
		if (arr[y] < arr[y + 1] && test2 == 0) { 
			test1 = 1; 
			x = "\nIncreasing";
			y++;
			counter--;
		}
		else if (arr[y] > arr[y + 1] && test1 == 0) { 
			test2 = 1; 
			x = "\nDecreasing";
			y++;
			counter--;
		}
		else if(arr[y] == arr[y+1] || arr[y] == arr[y-1]){ y++; counter--; }
	}

	if (counter != 0 && counter > 0) { isMonotonic = false; x = ""; }
	cout <<boolalpha << isMonotonic << x << endl;
    return 0;
}
