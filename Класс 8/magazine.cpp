#include "Magazin.h"
#include <iostream>
using namespace std;

Magazin::Magazin() : Print::Print() {
	pages = 0;
}
Magazin::Magazin(string a, string b, int p) : Print::Print(a, b) {
	pages = p;
}
Magazin::Magazin(const Magazin& m) : Print::Print(m) {
	pages = m.pages;
}

void Magazin::setPages(int p) {
	pages = p;
}
int Magazin::getPages() {
	return pages;
}

Magazin& Magazin::operator=(const Magazin& m) {
	Print::operator=(m);
	pages = m.pages;
	return *this;
}
ostream& operator<<(ostream& out, const Magazin& m) {
	out << static_cast<Print>(m) << m.pages;
	return out;
}
istream& operator>>(istream& in, Magazin& m) {
	in >> static_cast<Print&>(m) >> m.pages;
	return in;
}
