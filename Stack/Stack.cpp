#include "stdafx.h"
#include "Stack_H.h"
#include <iostream>

using namespace std;

int main()
{
	Stack<int> st1;
	st1.push(3.64);
	st1.push(2);
	st1.push(1);

	Stack<int> st2 = st1;
	st2.pop();
	st2.pop();
	st2.pop();


	cout << st1.size() << endl << st2.size() << endl << st1.empty() << endl << st2.empty() << endl;

	st1 = st2;

	cin.get();
	return 0;
}