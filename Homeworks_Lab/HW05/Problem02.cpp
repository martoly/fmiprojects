#include "stdafx.h"
#include <iostream>
using namespace std;

const int a = 1000;

int main()
{
	int arr[a], arr2[a] = {}, counter = 1, size, n;
	cin >> size;
	for (int i = 0; i < size; i++)
	{
		cin >> arr[i];
	}

	for (int i = 0; i < size; i++)
	{

		arr2[arr[i]] = counter;

		for (int j = 0; j < size; j++)
		{
			if (arr[i] == arr[i + j]) counter++;
			arr2[arr[i]] = counter;

		}
	}



    return 0;
}

