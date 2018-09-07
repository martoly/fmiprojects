#include "stdafx.h"
#include <iostream>
#include <cmath>
using namespace std;

int digitCounter[100]{};
long double numbers[100]{};
int numCounter = 0;

bool containsOnlyAllowedSymbols(const char* x) {
	bool test = 1;
	for (int i = 0; i < strlen(x); i++)
	{
		if ( ((x[i] >= 40) && (x[i] <= 43)) || ((x[i] >= 47) && (x[i] <= 57)) || 
			(x[i] == 45 )|| (x[i] == 91) || (x[i] == 93) || (x[i] == 123) || (x[i] == 125) ) {
			continue;
		}
		else test = 0;
	}
	
	if (!test) {
		return 0;
	}
	else return 1;
}
void printAllNumbers(const char* x) {
	int j = 0, newLine;
	for (int i = 0; i < strlen(x); i++)
	{
		if (x[i] >= 48 && x[i] <= 57) {
			//newLine = 0;
			cout << x[i];
			digitCounter[j]++; // counts the number of digits
			numCounter++;
		}
		else {
			//if(newLine == 0) cout << '\n';
			//newLine++;
			cout << '\n';
			j++;
		}

	}
	return;
}
bool hasCorrectBrackets(const char* x) {
	//INVALID FUNCTION!
	bool test1, test2, test3, check1 = 1, check2 = 1, check3 = 1;
	
	for (int i = 0; i < strlen(x); i++)
	{
		for (int j = 0; j < strlen(x); j++)
		{
			//check if both brackets are placed and no closing brackets are placed first
			if (x[i] == 40) {
				if (x[j] == 41) {
					check1 = 0;
				}
			}
			else if (x[i] == 41 && check1) test1 = 0;

			if (x[i] == 91) {
				if (x[j] == 93) {
					check2 = 0;
				}
			}
			else if (x[i] == 93 && check2) test2 = 0;

			if (x[i] == 123) {
				if (x[j] == 125) {
					check3 = 0;
				}
			}
			else if (x[i] == 125 && check3) test3 = 0;




			/*
			if (x[s] == 40 || x[s] == 41) check1 = 1;//if there are any small brackets
			if (x[s] == 91 || x[s] == 93) check2 = 1;//if there are any medium brackets
			if (x[s] == 123 || x[s] == 125) check3 = 1;//if there are any big brackets

			if (check1 && !(check2 || check3)) {//if there are only small brackets
				if (!((x[i] == 41 && !(x[j] == 40)))) {
					test1 = 1;
					return 1;
				}
			}

			if (check1 && check2 && !check3) {//if there are small and medium brackets
				if (!((x[i] == 41 && !(x[j] == 40)) && (x[i] == 93 && !(x[j] == 91)))) {
					if (x[i] == 91 && x[j] == 40) test2 = 1;
					return 1;

				}
			}

			if (check1 && check2 && check3) {//if there are all three brackets
			if (!((x[i] == 41 && !(x[j] == 40)) && (x[i] == 93 && !(x[j] == 91)) && (x[i] == 125 && !(x[j] == 123)))) {
				if (x[i] == 123 && x[j] == 91 && x[s] == 41) test3 = 1;
				return 1;

			}
			}

			if (check2 && !(check1 || check3)) {//if there are only medium brackets
				if (!((x[i] == 93 && !(x[j] == 91)))) {
					test4 = 1;
					return 1;

				}
			}

			if (check3 && !(check2 || check1)) {//if there are only big brackets
				if (!((x[i] == 125 && !(x[j] == 123)))) {
					test5 = 1;
					return 1;

				}
			}

			if (check1 && check3 && !check2) {//if there are small and big brackets
			if (!((x[i] == 41 && !(x[j] == 40)) && (x[i] == 125 && !(x[j] == 123)))) {
				if (x[i] == 123 && x[j] == 41) test6 = 1;
				return 1;

			}
			}

			if (check3 && check2 && !check1) {  //if there are big and medium brackets
			if (!((x[i] == 93 && !(x[j] == 91)) && (x[i] == 125 && !(x[j] == 123)))) {
				if (x[i] == 123 && x[j] == 91) test7 = 1;
				return 1;

			}
			}
			*/
		}
	}

	if (test1 && test2 && test3) return 1;
	else return 0;
} 
void calculateAndPrint(const char* x) {

	bool test = 1;
	char sign;
	//if all signs are the same
	for (int i = 0; i < strlen(x); i++)
	{
		for (int j = 0; j < strlen(x); j++)
		{
			if (!((x[i] >= 48) && (x[i] <= 57)) && (containsOnlyAllowedSymbols(x)) && !((x[j] >= 48) && (x[j] <= 57))) {

				if (!(x[i] == x[j])) {
					test = 0;
				}
				else sign = x[i];
			}
		}
	} 
	
	int k = 0, t = 0, j = 0;
	//storing numbers from char to numbers in array
	for (int i = 0; i < numCounter; i++)
	{
		if (!(x[j] >= 48 && x[j] <= 57)) j++; //checks if the char is number or not
		numbers[k] += (-48 + x[j]) * pow(10, digitCounter[k] - (t + 1)); // stores the chars as numbers 
		if (digitCounter[k] - (t + 1) == 0) {
			k++;
			t = 0;
		}
		else t++;
		j++;
	}

	long double product;
	//calculates the value
	if (test)
	{
		product = numbers[0];
		for (int i = 1; i < k; i++)
		{
			if (sign == 42) product *= numbers[i]; // *
			else if (sign == 43) product += numbers[i]; // +
			else if (sign == 47) product /= numbers[i]; // /
			else if (sign == 45)product -= numbers[i]; // -
		}
		cout << product << endl;

	}
	else cout << "Cannot calculate the expression!" << endl;
	return;
}

int main()
{
	char input[100];
	cin >> input;
	
	cout << boolalpha << containsOnlyAllowedSymbols(input) << endl;
	cout << endl; 

	printAllNumbers(input);
	cout << endl;

	//cout << boolalpha << hasCorrectBrackets(input) << endl;
	//cout << endl;

	calculateAndPrint(input);
	cout << endl;

	return 0;
}