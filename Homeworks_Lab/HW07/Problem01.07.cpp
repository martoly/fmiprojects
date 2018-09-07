#include "stdafx.h"
#include <iostream>
using namespace std;


int main()
{
	char input[100];
	cin >> input;

	for (int i = 0; i < strlen(input); i++)
	{
		if ((input[i] >= 97) && (input[i] <= 122)) {
			input[i] -=  32;
		}
	}

	cout << input << endl;

    return 0;
}

