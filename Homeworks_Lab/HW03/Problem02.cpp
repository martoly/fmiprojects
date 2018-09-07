#include "stdafx.h"
#include <iostream>
using namespace std;

const int a = 1000;
const int b = 1000;

int main()
{
	int arr[a], arr2[b], real_size, m = 0, q = 0, t = 0;
	cin >> real_size;

	for (int i = 0; i < real_size; i++) { cin >> arr[i]; }
	for (int i = 0; i < real_size; i++) {
		if (arr[q] < arr[q + 1]|| m <= real_size) {
			arr2[q] = arr[q];
			q++;
			m++;
		}

		if (arr[t] > arr[t + 1] && m <= real_size) {
			arr2[t] = arr[t];
			t++;
		}
	}


	return 0;
}