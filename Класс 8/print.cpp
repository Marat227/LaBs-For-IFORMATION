#include "Print.h"
using namespace std;

Print::Print() {
	name = "";
	author = "";
}
Print::Print(string n, string a) : name(n), author(a) {}
Print::Print(const Print& t) {
	name = t.name;
	author = t.author;
}
string Print::getName() {
	return name;
}
string Print::getAuthor() {
	return author;
}
void Print::setName(string n) {
	name = n;
}
void Print::setAuthor(string a) {
	author = a;
}

Print& Print::operator=(const Print& t) {
	name = t.name;
	author = t.author;
	return *this;
}
ostream& operator<<(ostream& out, const Print& p) {
	out << p.name << ": " << p.author << ": ";
	return out;
}
istream& operator>>(istream& in, Print& p) {
	in >> p.name >> p.author;
	return in;
}
