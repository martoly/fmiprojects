#include "stdafx.h"
#include <iostream>

template <typename T>
struct Node {
	T data;
	Node<T>* next;
	Node(T _data = 0, Node<T> *_next = nullptr)
	{
		data = _data;
		next = _next;
	}
};

template <typename T>
class Comparator {
public:
	virtual int compare(const T& left, const T& right) = 0;
};

template <typename T>
class SortedList : public Comparator<T>
{
private:
	Comparator<T> *c;
	Node<T> *n;
	int size;
public:
	SortedList(Comparator<T> *c = nullptr, Node<T> *_n = nullptr, int _size = 0) : n{ nullptr }, size{ 0 }
	{
		
	}
	void add(const T& elem)
	{
		size++;
		n = new Node<T>(elem);
		n = n->next;
	}
	virtual int compare(const T &left, const T &right) override
	{
		return 0;
	}
};

int main()
{
	SortedList<int> s1;
	s1.add(5);
	s1.add(0);
	return 0;
}