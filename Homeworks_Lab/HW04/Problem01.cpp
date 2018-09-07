#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

const int a = 26;

int main()
{
	int n, b = 0;
	string arr[a];
	cin >> n;
	for (int i = 0; i < 26; i++) { arr[i] = 97 + i; }

	for (int i = 0; i < n; i++) {
		for (int i = 0; i <= b; i++) { cout << arr[b]; }
		++b;
		cout << "\n";
	}

	for (int i = n-1; i >= 0; i--) {
		--b;
		for (int i = 0; i < b; i++) { cout << arr[b - 1]; }
		if (b != 0) { cout << "\n"; }
	}

    return 0;
}

