#include "stdafx.h"
#include <iostream>
using namespace std;

const int a = 1000;

int main()
{
	int arr[a], size, n = 1, q = 0, s;
	bool check = 0;
	cin >> size;
	for (int i = 0; i < size; i++) { cin >> arr[i]; }

	for (q; q < size; q++) {
		for(n; n<=size; n++){
			if (arr[q] == arr[n] && q !=n ) { 
				check = 1; 
				s = n;
				break;
			}
		}
		n = 1;
	}
	
	if (check) { cout << arr[s] << endl; }
	
	return 0;
}

