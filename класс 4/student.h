#pragma once
#include "Person.h"

class Student : public Person {
	string subject;
	int mark;

public:
	Student();
	Student(string, int, string, int);
	Student(const Student&);
	~Student();

	void setSubject(string);
	string getSubject();
	void setMark(int);
	int getMark();

	bool isGoodMark();

	Student& operator=(const Student&);
	friend istream& operator>>(istream&, Student&);
	friend ostream& operator<<(ostream&, const Student&);
};
