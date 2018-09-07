#include "stdafx.h"
#include <iostream>	
using namespace std;

class Worker 
{
public:
	Worker(const char *_name = nullptr, int _age = 18, double _salary = 0);
	Worker(const Worker &other);
	Worker& operator=(const Worker &other);
	~Worker();

	void setName(char const *_name);
	void setAge(int _age);
	void setSalary(double _salary);

	const char* getName() const { return name; }
	const int getAge() const { return age; }
	const double getSalary() const { return salary; }
	void print() const;
private:
	char* name;
	double salary;
	int age;
};
Worker::Worker(const char *_name, int _age, double _salary) : name{nullptr} /*  ÂÀÆÍÎ ÄÀ ÑÅ ÄÎBAVI nullptr */
{
	setName(_name);
	setAge(_age);
	setSalary(_salary);
}
Worker::Worker(const Worker &other) : name{other.name}, age{other.age}, salary{other.salary} 
{}
Worker& Worker::operator=(const Worker &other)
{
	
	if (this != &other)
	{
		setName(other.name);
		setAge(other.age);
		setSalary(other.salary);


		/*
			if (other.name != nullptr)
			{
				int len = strlen(other.name) + 1;
				name = new char[len];
				strcpy_s(name, len, other.name);
			}
			age = other.age;
			salary = other.salary;

		*/
	}
return *this;
}
Worker::~Worker()
{
	delete[] name; 
	//cout << "Worker destructor called" << endl; // for debuging purposes only
}
void Worker::setName(const char *_name)
{
	if (_name == nullptr) _name = " ";
	int len = strlen(_name) + 1;
	delete[] name;
	name = new char[len];
	strcpy_s(name, len, _name);
}
void Worker::setAge(int _age)
{
	age = _age;
}
void Worker::setSalary(double _salary)
{
	salary = _salary;
}
void Worker::print() const
{
	cout << name << ", " << age << ", " << salary << endl;
}

class Company
{
public:
	Company(char *_name = nullptr, int _capacity = 0);
	Company(const Company &other);
	Company& operator=(const Company &other);
	~Company();

	void setName(char *_name);
	void setCapacity(int _capacity);
	void setSize(int _size);
	
	const char getName() const { return *name; }
	const int getCapacity() const { return capacity; }
	const int getSize() { return size; }

	void hireWorker(const Worker newWorker);
	void fireWorker(const Worker retWorker);
	void promotion();
	void print() const; 
private:
	void resize();
	char *name;
	int size;
	int capacity;
	Worker *arr;
};
Company::Company(char *_name, int _capacity) : arr{nullptr}, size{-1}
{
	setName(_name);
	setCapacity(_capacity);
}
Company::Company(const Company &other) : arr{ nullptr }, name{ other.name }, size{ other.size }, capacity{ other.capacity }
{}
Company& Company::operator=(const Company &other)
{
	if (this != &other) 
	{
		setName(other.name);
		setSize(other.size);
		setCapacity(other.capacity);
	}
	return *this;
}
Company::~Company()
{
	delete[] name;
	delete[] arr;
//	cout << "Company destructor called" << endl; // for debuging purposes only
}
void Company::setName(char *_name)
{
	if (_name == nullptr) _name = " ";
	delete[] name;
	int len = strlen(_name) + 1;
	name = new char[len];
	strcpy_s(name, len, _name);
}
void Company::setCapacity(int _capacity) 
{
	capacity = _capacity;
}
void Company::setSize(int _size)
{
	size = _size;
}
void Company::hireWorker(Worker newWorker)
{
	++size;
	resize();
	if (size == 0)
	{
		arr = new Worker[1];
	}
	else
	{
		Worker *newWorkers = new Worker[capacity];

		for (int i = 0; i < size; ++i)
			newWorkers[i] = arr[i];

		delete[] arr;
		arr = newWorkers;
	}
	
	arr[size] = newWorker;
	cout << "Worker " << arr[size].getName() << " added!" << endl;
	cout << endl;

}
void Company::fireWorker(Worker retWorker)
{
	for (int i = 0; i <= size; i++)
	{
		if (strcmp(retWorker.getName(), arr[i].getName()) == 0)
		{
			arr[i] = arr[size--];
			cout << "Worker " << retWorker.getName() << " removed." << endl;
			cout << endl;
			break;
		}
	}
	resize();

}
void Company::promotion()
{
	for (int i = 0; i < size; i++)
	{
		arr[i].setSalary(arr[i].getSalary()*1.1);
	}
	cout << "All salaries increased with 10%" << endl;
}
void Company::resize()
{
	if (size * 2 <= capacity)
	{
		capacity /= 2;
		cout << "Capacity reduced twice!" << endl;
	}
	else if (size == capacity)
	{
		capacity *= 2;
		cout << "Capacity increased twice" << endl;
	}
}
void Company::print() const
{
	for (int  i = 0; i <= size; i++)
	{
		cout << arr[i].getName() << ", " << arr[i].getAge() << ", " << arr[i].getSalary() << endl;
	}
	cout << endl;
}

void testApp()
{
	Worker w1("Dimitur Hicov", 50, 2000);
	Worker w2("Petko Petkov", 25, 200);
	Worker w3("Stoqn Bratovanov", 30, 7000);
	Worker w4("Georgi Matev", 27, 2100);
	Worker w5("Martin Mihalev", 19, 600);

	Company c1("FMI OOD", 2);

	c1.hireWorker(w1);
	c1.hireWorker(w2);
	c1.hireWorker(w3);
	c1.hireWorker(w4);
	c1.hireWorker(w5);
	c1.print();

	c1.fireWorker(w1);

	c1.print();
	c1.promotion();
	c1.print();
}

int main()
{
	testApp();
    return 0;
}