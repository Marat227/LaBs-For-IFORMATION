#include "list.h"
#include <iostream>
#include <exception>

/// <summary>
/// int data,
/// Node* ptrNext
/// </summary>
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
	Node* curr = head;
	for (int i = 0; i < indx; i++) {
		curr = curr->ptrNext;
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
	for (int i = 0; i < n && curr->ptrNext != nullptr; i++) {
		curr = curr->ptrNext;
	}
}
int& Iterator::operator*() {
	return curr->data;
}
