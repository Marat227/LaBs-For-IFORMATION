#include "Triad.h"

// конструкторы
TRIAD::TRIAD(int f, int s, int t)
	: first(f), second(s), third(t) {}
TRIAD::TRIAD()
	: first(0), second(0), third(0) {}
TRIAD::TRIAD(TRIAD& p)
	: first(p.first), second(p.second), third(p.third) {}
TRIAD::~TRIAD() {}

// модификаторы
void TRIAD::setFirst(int f) {
	first = f;
}
void TRIAD::setSecond(int s) {
	second = s;
}
void TRIAD::setThird(int t) {
	third = t;
}

// селекторы
int TRIAD::getFirst() {
	return first;
}
int TRIAD::getSecond() {
	return second;
}
int TRIAD::getThird() {
	return third;
}

// перегрузка оператора присваивания 
TRIAD& TRIAD::operator= (const TRIAD& p) {
	if (&p == this) return *this;
	first = p.first;
	second = p.second;
	third = p.third;
	return *this;
}

// методы увеличения полей на 1
void TRIAD::first_1() {
	first++;
}
void TRIAD::second_1() {
	second++;
}
void TRIAD::third_1() {
	third++;
}

istream& operator >> (istream& in, TRIAD& t) {
	cout << "first: "; in >> t.first;
	cout << "second: "; in >> t.second;
	cout << "third: "; in >> t.third;
	return in;
}

ostream& operator<<(ostream& out, const TRIAD& t)
{
	return (out << t.first << "," << t.second << "," << t.third);
