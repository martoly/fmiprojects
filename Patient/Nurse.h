#pragma once
#ifndef _NURSE_H
#define _NURSE_H

class Nurse {
private:
	char name[50];
	int duty;
public:
	Nurse();

	void setDuty(int _duty);
	int getDuty() const;

	void readNurse();
	void setName(char const* _name);
	char const* getName() const;

#endif // !_NURSE_H
};