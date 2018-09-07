#include <iostream>
#include "Patient.h"
#include "Nurse.h"

using namespace std;


int main() {

	Patient p;
	Nurse n;

	p.print();
	
	p.read(n);
	p.print();
	n.readNurse();
	

	int test;
	cin >> test;
	return 0;
}