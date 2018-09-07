#include "stdafx.h"
#include <iostream>
using namespace std;

const int a = 1000;

int main()
{
	int arr[a], arr2[a], arr3[2 * a], size, size2, size3, counter = 0;
	cin >> size;
	for (int i = 0; i < size; i++) cin >> arr[i];
	cin >> size2;
	for (int i = 0; i < size2; i++) cin >> arr2[i];
	
	size3 = size + size2;

	for (int i = 0; i < size3; i++)
	{
		if (size > 0) {
			arr3[i] = arr[i];
			size--;
		}
		else if (size2 > 0 && size <=0) {
			arr3[i] = arr2[counter];
			size2--;
			counter++;
		}
	}


	for (int i = 0; i <size3 - 1; i++) {
		for (int j = 0; j < size3 - 1 - i; j++)
		{
			if (arr3[j] > arr3[j + 1]) {
				 swap(arr3[j], arr3[j + 1]);
			}
		}
	}

	for (int i = 0; i < size3; i++)	cout << arr3[i] << '\t';

    return 0;
}

