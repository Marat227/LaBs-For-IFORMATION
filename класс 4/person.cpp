#include "Person.h"
#include "Student.h"     

///--------------------Person----------------///

Person::Person() {
	name = "";
	age = 0;
}
Person::Person(string name, int age) {
	this->name = name;
	this->age = age;
}
Person::Person(const Person& p) {
	name = p.name;
	age = p.age;
}
Person::~Person() {}

void Person::setName(string name) {
	this->name = name;
}
string Person::getName() {
	return name;
}
void Person::setAge(int age) {
	this->age = age;
}
int Person::getAge() {
	return age;
}

Person& Person::operator=(const Person& p) {
	if (this == &p) return *this;
	name = p.name;
	age = p.age;
	return *this;
}
ostream& operator<<(ostream& out, const Person& p) {
	return out << "name: " << p.name << " age: " << p.age;
}
istream& operator>>(istream& in, Person& p) {
	cout << "name:? " << endl; in >> p.name;
	cout << "age:?" << endl; in >> p.age;
	return in;
}
