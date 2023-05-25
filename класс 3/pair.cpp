#include <iostream>
#include "Pair.h"

Pair::Pair() {
	first = 0;
	second = 0.0;
}
Pair::Pair(int a, double b) {
	first = a;
	second = b;
}
Pair::Pair(Pair& t) {
	first = t.first;
	second = t.second;
}
int Pair::getFirst() {
	return first;
}
void Pair::setFirst(int tf) {
	first = tf;
}
double Pair::getSecond() {
	return second;
}
void Pair::setSecond(double tf) {
	second = tf;
}
Pair& Pair::operator=(const Pair& ptr) {
	if (&ptr == this) return *this;
	first = ptr.first;
	second = ptr.second;
	return *this;
}

std::istream& operator>>(std::istream& in, Pair& p) {
	std::cout << "First? " << std::endl;  in >> p.first;
	std::cout << "Second?" << std::endl; in >> p.second;
	return in;
}
std::ostream& operator<<(std::ostream& out, Pair& p) {
	return out << p.first << ":" << p.second;
}
void Pair::show() {
	std::cout << first << ":" << second << std::endl;
}
Pair& Pair::operator-(const Pair& a) {
	first -= a.first;
	second -= a.second;
	return *this;
}
