#include "stdafx.h"
#include <iostream>
using namespace std;

const int N = 1000;

int max(int *arr, int size) {
	int maxArr, i = 0;
	for (int i = 0; i < size; i++) cin >> arr[i];
	maxArr = arr[0];

	if (maxArr < arr[i]) maxArr = arr[i];
	if (i = size - 1) return maxArr;
	i++;
	return max(arr, size);
	
}

int main()
{
	int *arr[N], length;
	cin >> length;

	max(*arr, length);

	return 0;
}

