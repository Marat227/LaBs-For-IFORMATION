#pragma once
#include <string>
#include <iostream>
using namespace std;

class Error {
public:
	virtual void what() {};
};

class IndexError : public Error {
protected:
	string msg;
public:
	IndexError() {
		msg = "Index Error\n";
	}
	virtual void what() { cout << msg; }
};

class SizeError : public Error {
protected:
	string msg;
public:
	SizeError() {
		msg = "Size Error\n";
	}
	virtual void what() { cout << msg; }
};

class MaxSizeError : public SizeError {
protected:
	string msg_;
public:
	MaxSizeError() : SizeError() {
		msg_ = "size>MAXSIZE\n";
	}
	virtual void what() { cout << msg << msg_; }
};

class EmptySizeError : public SizeError {
protected:
	string msg_;
public:
	EmptySizeError() : SizeError() {
		msg_ = "List is empty\n";
	}
	virtual void what() { cout << msg << msg_; }
};

class IndexError1 : public IndexError {
protected:
	string msg_;
public:
	IndexError1() : IndexError() {
		msg_ = "index < 0\n";
	}
	virtual void what() { cout << msg << msg_; }
};

class IndexError2 : public IndexError {
protected:
	string msg_;
public:
	IndexError2() : IndexError() {
		msg_ = "index>size\n";
	}
	virtual void what() { cout << msg << msg_; }
};

Файл List.h:
#include <iostream>
#include "Error.h"
class Iterator;
class List;

class Node {
	friend class List;
	friend class Iterator;
public:
	Node();
	Node(int);
	~Node();

	int getData();
	Node* getPtr();
private:
	int data;
	Node* ptrNext;
};

class Iterator {
public:
	Iterator();
	Iterator(const Iterator&);

	void operator++();
	void operator+(int);
	int& operator*();
private:
	friend class List;
	Node* curr;
};

class List {
public:
	List();
	List(int);
	List(const List&);
	~List();

	int& operator[](int);

	List& operator=(const List&);
	size_t operator()();

	friend List operator*(List&, List&);
	friend std::ostream& operator<<(std::ostream&, const List&);
	friend std::istream& operator>>(std::istream&, List&);

	void push(int);

	Iterator first() { return beg; }

private:
	Node* head;
	size_t size;
	Iterator beg;
};



Node::Node() {
	data = 0;
	ptrNext = nullptr;
}
Node::Node(int data) {
	this->data = data;
	ptrNext = nullptr;
}
Node::~Node() {
	if (ptrNext != nullptr) {
		delete ptrNext;
	}
}
int Node::getData() {
	return data;
}
Node* Node::getPtr() {
	return ptrNext;
}

/// <summary>
/// Node* head;
/// </summary>
List::List() {
	head = nullptr;
	size = 0;
	beg.curr = head;
}
List::List(int data) {
	head = new Node(data);
	size = 1;
	beg.curr = head;
}
List::List(const List& tList) {
	Node* curr = tList.head;
	beg.curr = tList.head;
	while (curr != nullptr) {
		int a = curr->data;
		this->push(a);
		curr = curr->ptrNext;
	}
}
List::~List() {
	if (head != nullptr) {
		delete head;
		head = head->ptrNext;
	}
	size = 0;
	beg.curr = head;
}

void List::push(int data) {
	if (head == nullptr) {
		head = new Node(data);
		beg.curr = head;
	}
	else {
		Node* curr = head;
		while (curr->ptrNext != nullptr) {
			curr = curr->ptrNext;
		}
		curr->ptrNext = new Node(data);
	}
	size++;
}
int& List::operator[](int indx) {
	if (indx < 0) throw IndexError1();

	Node* curr = head;
	for (int i = 0; i < indx; i++) {
		curr = curr->ptrNext;
		if (curr == nullptr) throw IndexError2();
	}

	return curr->data;
}

size_t List::operator()() {
	return size;
}
List operator*(List& fList, List& sList) {
	List tmpList;
	int maxSize = fList.size > sList.size ? fList.size : sList.size;
	int minSize = fList.size <= sList.size ? fList.size : sList.size;

	for (int i = 0; i < minSize; i++) {
		int a = fList[i];
		int b = sList[i];
		tmpList.push(a * b);
	}
	for (int i = 0; i < maxSize - minSize; i++) {
		tmpList.push(0);
	}

	return tmpList;
}
List& List::operator=(const List& tList) {
	Node* curr = tList.head;
	beg.curr = tList.head;
	while (curr != nullptr) {
		int a = curr->data;
		this->push(a);
		curr = curr->ptrNext;
	}
	return *this;
}
std::ostream& operator<<(std::ostream& out, const List& tList) {
	Node* curr = tList.head;
	for (int i = 0; i < tList.size; i++) {
		out << curr->getData() << " ";
		curr = curr->getPtr();
	}
	return out;
}
std::istream& operator>>(std::istream& in, List& tList) {
	int a;
	in >> a;
	tList.push(a);
	return in;
}

/// <summary>
/// Node* curr
/// </summary>
Iterator::Iterator() {
	curr = nullptr;
}
Iterator::Iterator(const Iterator& it) {
	curr = it.curr;
}

void Iterator::operator++() {
	curr = curr->ptrNext;
}
void Iterator::operator+(int n) {
	for (int i = 0; i < n; i++) {
		curr = curr->ptrNext;
		if (curr->ptrNext == nullptr) throw MaxSizeError();
	}
}
int& Iterator::operator*() {
	return curr->data;
}
