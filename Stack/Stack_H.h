#pragma once

#ifndef STACK_H
#define STACK_H

#include <cassert>

template <typename T>
struct Node
{
	Node(const T &data_, Node<T> *next_ = nullptr);

	T data;
	Node<T> *next;
};

template <typename T>
class Stack
{
public:
	Stack();
	Stack(const Stack<T> &other);
	Stack<T> &operator=(const Stack<T> &other);
	~Stack();

	void push(const T &elem);
	T pop();

	size_t size() const;
	bool empty() const;

private:
	void copy(const Stack<T> &other);
	void del();
	Node<T> *start;
	size_t size_;
};


template <typename T>
Node<T>::Node(const T &data_, Node<T> *next_ = nullptr) : next(next_), data(data_)
{}

template <typename T>
Stack<T>::Stack()
{
	start = nullptr;
	size_ = 0;
}

template <typename T>
Stack<T>::Stack(const Stack<T> &other)
{
	copy(other);
}

template <typename T>
Stack<T> &Stack<T>::operator=(const Stack<T> &other)
{
	if (this != &other)
	{
		del();
		copy(other);
	}
	return *this;
}

template <typename T>
Stack<T>::~Stack()
{
	del();
}

template <typename T>
void Stack<T>::copy(const Stack<T> &other)
{
	size_ = other.size_;

	Node<T> *temp = other.start;

	if (temp)
	{
		start = new Node<T>(temp->data);
		temp = temp->next;
	}

	Node<T> *curr = start;

	while (temp)
	{
		curr->next = new Node<T>(temp->data);
		curr = curr->next;
		temp = temp->next;
	}
}

template <typename T>
void Stack<T>::del()
{
	Node<T> *temp;
	while (start)
	{
		temp = start->next;
		delete start;
		start = temp;
	}
}

template <typename T>
void Stack<T>::push(const T &elem)
{
	Node<T> *temp = new Node<T>(elem, start);
	start = temp;
	size_++;
}

template <typename T>
T Stack<T>::pop()
{
	assert(start);
	Node<T> *temp = start;
	start = start->next;

	T result = temp->data;
	delete temp;
	size_--;
	return result;
}

template <typename T>
size_t Stack<T>::size() const
{
	return size_;
}

template <typename T>
bool Stack<T>::empty() const
{
	return size_ == 0;
}

#endif