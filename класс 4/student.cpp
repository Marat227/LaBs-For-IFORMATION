#include "Person.h"
#include "Student.h"

///--------------------Student----------------///

Student::Student() : Person::Person() {
	subject = "";
	mark = 0;
}
Student::Student(string name, int age, string subject, int mark) : Person(name, age) {
	this->subject = subject;
	this->mark = mark;
}
Student::Student(const Student& p) {
	name = p.name;
	age = p.age;
	subject = p.subject;
	mark = p.mark;
}
Student::~Student() {}

void Student::setSubject(string subject) {
	this->subject = subject;
}

string Student::getSubject() {
	return subject;
}

void Student::setMark(int mark) {
	this->mark = mark;
}

int Student::getMark() {
	return mark;
}

bool Student::isGoodMark() {
	if (mark > 3) return true;
	else return false;
}

Student& Student::operator=(const Student& ptr) {
	if (&ptr == this) return *this;
	this->name = ptr.name;
	this->age = ptr.age;
	this->subject = ptr.subject;
	this->mark = ptr.mark;
	return *this;
}

istream& operator>>(istream& in, Student& ptr) {
	cout << "name:? " << endl; in >> ptr.name;
	cout << "age:?" << endl; in >> ptr.age;
	cout << "subject:?" << endl; in >> ptr.subject;
	cout << "mark:?" << endl; in >> ptr.mark;
	return in;
}

ostream& operator<<(ostream& out, const Student& p) {
	return out << "name: " << p.name << " age: " << p.age << "\n" <<
		"subject: " << p.subject << " mark: " << p.mark << endl;
}

///--------------------Student----------------///
