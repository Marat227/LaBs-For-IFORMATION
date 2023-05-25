#include <iostream>
#include "Person.h"
#include "Student.h"

void interestingFunction(Person&);
Student secondInterestingFunction();

int main() {
	Student a;
	cin >> a;
	cout << a;

	Person a2;
	cin >> a2;
	cout << a2;
	cout << endl;

	interestingFunction(a);
	a = secondInterestingFunction();
	cout << endl;
	cout << a;

	return 0;
}

void interestingFunction(Person& person) {
	person.setName("Torwalds");
	cout << person;
}
Student secondInterestingFunction() {
	Student student("Vasya", 19, "math", 4);
	return student;
}
