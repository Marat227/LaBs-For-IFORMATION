#include "Vector.h"

Vector::Vector() {
	beg = 0;
	size = 0;
	curr = 0;
}

Vector::Vector(int size) {
	this->size = size;
	curr = 0;
	beg = new Object * [size];
}

Vector::~Vector() {
	if (beg != 0) delete[] beg;
	beg = 0;
}

void Vector::add(Object* someObj) {
	if (curr < size) {
		beg[curr] = someObj;
		curr++;
	}
}

ostream& operator<<(ostream& out, const Vector& vect) {
	if (vect.size == 0) out << "Empty" << endl;
	Object** p = vect.beg;

	// суть в вызове метода show некоторого объекта

	for (int i = 0; i < vect.curr; i++) {
		(*p)->show();
		p++;
	}
	return out;
}
