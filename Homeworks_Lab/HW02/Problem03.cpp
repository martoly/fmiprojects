#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	int a;
	cin >> a;
	//взел съм кода за проверка за прости числа на готово... не се сетих сам :( 
	for (int i = 2; i <= a / 2; ++i)
	{
		if (a % i == 0)
		{
			cout << i << endl;
		}
	}

    return 0;
}