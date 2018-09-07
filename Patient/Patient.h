#pragma once
#ifndef _PATIENT_H
#define _PATIENT_H


class Nurse;
class Patient {
private:
	char name[50];
	int age;
	char illness[50];
	int floor;
	Nurse* nurse;
	bool help;

public:
	//default constructor
	Patient();

	//constructor with patameters
	Patient(char const* _name, int _age, char const* _illness, int _floor, Nurse* _nurse, bool _help);

	//setters
	void setName(char const* _name);
	void setAge(int _age);
	void setIllness(char const* _illness);
	void setFloor(int _floor);
	void setNurse(Nurse* _nurse);
	void setHelp(bool _help);

	//getters
	char const* getName() const;
	int Patient::getAge() const;
	char const* getIllness() const;
	int getFloor()const;
	Nurse* getNuerse()const;
	bool getHelp() const;

	void readNurse(Nurse &n);
	void print() const;
	void read(Nurse &n);
	void callNurse() const;
};

#endif
