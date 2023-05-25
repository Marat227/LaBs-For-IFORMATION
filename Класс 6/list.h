#include <iostream>
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
	friend class List;
public:
	Iterator();
	Iterator(const Iterator&);

	void operator++();
	void operator+(int);
	int& operator*();
private:
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
