#include "stack.h"

Node::Node() {
	data = 0;
	ptrNext = nullptr;
}
Node::Node(int data) : data(data) {
	ptrNext = nullptr;
}
Node::~Node() {
	if (ptrNext != nullptr) delete ptrNext;
}

void Node::setData(int data) {
	this->data = data;
}
int Node::getData() {
	return data;
}
Node* Node::getPtrNext() {
	return ptrNext;
}

Stack::Stack() {
	size = 0;
	tail = nullptr;
	iter.curr = nullptr;
}

Stack::Stack(int data) {
	tail = new Node(data);
	size = 1;
	iter.curr = tail;
}
Stack::~Stack() {
	tail->~Node();
}
Stack::Stack(const Stack& stack) {
	size = 0;
	if (tail != nullptr) tail->~Node();

	Node* stackPointer = stack.tail;
	while (stackPointer != nullptr) {
		int data = stackPointer->data;
		this->push(data);
		stackPointer = stackPointer->ptrNext;
	}
	iter.curr = tail;
}

void Stack::pop() {
	if (tail != nullptr) {
		Node* tailPointer = tail;
		if (tail->ptrNext != 0) tail = tail->ptrNext;
		else tail = 0;
		delete tailPointer;
		size--;
	}
	iter.curr = tail;
}
void Stack::push(int data) {
	if (tail == nullptr) {
		tail = new Node(data);

	}
	else {
		Node* tailPrevPointer = tail;
		tail = new Node(data);
		tail->ptrNext = tailPrevPointer;
	}
	iter.curr = tail;
	size++;
}

Iterator Stack::iterBegin() {
	return iter;
}

Stack& Stack::operator=(const Stack& stack) {
	size = 0;
	if (tail != nullptr) tail->~Node();

	Node* stackPointer = stack.tail;
	while (stackPointer != nullptr) {
		int data = stackPointer->data;
		this->push(data);
		stackPointer = stackPointer->ptrNext;
	}
	iter.curr = tail;
	return *this;
}

size_t Stack::operator()() {
	return size;
}

int& Stack::operator[](int index) {
	Node* nodePointer = tail;
	for (int i = 0; i < index && nodePointer != nullptr; i++) {
		if (nodePointer->ptrNext != nullptr) nodePointer = nodePointer->ptrNext;
	}
	return nodePointer->data;
}

ostream& operator<<(ostream& out, const Stack& stack) {
	Node* nodePointer = stack.tail;
	while (nodePointer != nullptr) {
		out << nodePointer->getData() << '\n';
		nodePointer = nodePointer->getPtrNext();
	}
	return out;
}

istream& operator>>(istream& in, Stack& stack) {
	int data;
	in >> data;
	stack.push(data);
	stack.iter.setCurrent(stack.tail);
	return in;
}

Stack operator*(Stack& fStack, Stack& sStack) {
	Stack tmpStack;
	int maxSize = fStack.size > sStack.size ? fStack.size : sStack.size;
	int minSize = fStack.size <= sStack.size ? fStack.size : sStack.size;

	for (int i = 0; i < minSize; i++) {
		int a = fStack[i];
		int b = sStack[i];
		tmpStack.push(a * b);
	}
	for (int i = 0; i < maxSize - minSize; i++) {
		tmpStack.push(0);
	}

	return tmpStack;
}

Iterator::Iterator() {
	curr = nullptr;
}

Iterator::Iterator(const Iterator& iter) {
	curr = iter.curr;
}

void Iterator::setCurrent(Node* node) {
	curr = node;
}

int& Iterator::operator*() {
	return curr->data;
}

Iterator& Iterator::operator=(const Iterator& iter) {
	curr = iter.curr;
	return *this;
}

void Iterator::operator+(int num) {
	for (int i = 0; i < num && curr != nullptr; i++) {
		if (curr->ptrNext != nullptr) curr = curr->ptrNext;
	}
}
