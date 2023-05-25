#include <iostream>
using namespace std;
#pragma once
class Stack;

class Node {
	friend class Stack;
	friend class Iterator;
protected:
	Node* ptrNext;
	int data;
public:
	Node();
	Node(int);
	~Node();

	void setData(int);
	int getData();
	Node* getPtrNext();
};

class Iterator {
	friend class Stack;
protected:
	Node* curr;
public:
	Iterator();
	Iterator(const Iterator&);

	void setCurrent(Node*);

	Iterator& operator=(const Iterator&);
	int& operator*();
	void operator+(int);
};

class Stack
{
protected:
	size_t size;
	Iterator iter;
	Node* tail;
public:
	Stack();
	Stack(int);
	Stack(const Stack&);
	~Stack();

	void pop();
	void push(int);

	Iterator iterBegin();

	Stack& operator=(const Stack&);
	size_t operator()();

	int& operator[](int);

	friend ostream& operator<<(ostream&, const Stack&);
	friend istream& operator>>(istream&, Stack&);

	friend Stack operator*(Stack&, Stack&);
};
