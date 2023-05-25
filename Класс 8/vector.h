#include "Magazin.h"
#include "Print.h"
#pragma once

class Vector {
protected:
	Object** vector;
	int curr;
	int size;
public:
	Vector();
	Vector(int);
	~Vector();

	void handleEvent(const tEvent& e) {
		if (e.eventWhat == eventMessage) {
			Object** p = vector;
			for (int i = 0; i < curr; i++) {
				(*p)->handleEvent(e);
				p++;
			}
		}
	}

	void show();
	void add();
	void del();
	void add(Object*);
	Object& operator[](int);
	friend ostream& operator<<(ostream&, const Vector&);
	friend istream& operator>>(istream&, Vector&);
};

Vector::Vector() {
	vector = 0;
	curr = 0;
	size = 0;
}

Vector::Vector(int size) {
	this->size = size;
	curr = 0;
	vector = new Object * [size];
}

Vector::~Vector() {
	if (vector != 0) {
		delete vector;
	}
}

void Vector::show() {
	cout << *this;
}

void Vector::add() {

	if (curr < size) {
		cout << "1.Print, 2.Magazine" << endl;
		int m;
		cin >> m;

		if (m == 1) {
			Print* p = new Print;
			cout << "Enter name and author" << endl;
			p->input();
			add(p);
		}
		else if (m == 2) {
			Magazin* p = new Magazin;
			cout << "Enter name, author and pages quantity" << endl;
			p->input();
			add(p);
		}
	}
	else {
		cout << "add(): size overflow" << endl;
	}
}
void Vector::add(Object* o) {
	if (curr < size) {
		vector[curr] = o;
		curr++;
	}
	else throw "awfaw";
}

void Vector::del() {
	if (curr = 0) return;
	delete vector[curr];
	curr--;
}


Object& Vector::operator[](int pos) {
	return *vector[pos];
}

ostream& operator<<(ostream& out, const Vector& v) {
	for (int i = 0; i < v.curr; i++) {
		out << "-----" << i + 1 << "-----" << endl;
		v.vector[i]->output();
	}
	return out;
}
istream& operator>>(istream& in, Vector& v) {
	for (int i = 0; i < v.curr; i++) {
		v.vector[i]->input();
	}
	return in;
}
