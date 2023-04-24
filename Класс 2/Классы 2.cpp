#pragma once
#include <string>

using namespace std;

class exam {
	// атрибуты
	string FIO;
	string subject;
	int grade;
public:
	exam();						// конструктор без параметров
	exam(string, string, int);	// конструктор с параметрами
	exam(const exam&);			// конструктор копирования
	~exam();					// дестркутор

	// селекторы (геттеры)
	string get_FIO();
	string get_subject();
	int get_grade();

	// модификаторы (сеттеры)
	void set_FIO(string);
	void set_subject(string);
	void set_grade(int);

	// вывод атрибутов в консоль
	void show();
};


#include "exam.h"
#include <iostream>
// конструктор без параметров
exam::exam() {
	FIO = "";
	subject = "";
	grade = 0;
	//cout << "Конструктор без параметров\n";
}

// конструктор с параметрами
exam::exam(string f, string s, int g) {
	FIO = f;
	subject = s;
	grade = g;
	//cout << "Конструктор с параметрами\n";
}

// конструктор копирования
exam::exam(const exam& t) {
	FIO = t.FIO;
	subject = t.subject;
	grade = t.grade;
	//cout << "Конструктор копирования\n";
}

// дестркутор
exam::~exam() {
	//cout << "Деструктор\n";
}

// селекторы (геттеры)
string exam::get_FIO() {
	return FIO;
}
string exam::get_subject() {
	return subject;
}
int exam::get_grade() {
	return grade;
}

// модификаторы (сеттеры)
void exam::set_FIO(string f) {
	FIO = f;
}
void exam::set_subject(string s) {
	subject = s;
}
void exam::set_grade(int g) {
	grade = g;
}

// вывод атрибутов в консоль
void exam::show() {
	cout << "FIO : " << FIO << endl;
	cout << "subject : " << subject << endl;
	cout << "grade : " << grade << endl << endl;
}

#include <iostream>
#include <string>
#include "exam.h"

using namespace std;

// функция для возврата объекта как результата
exam make_exam() {
	string fio;
	string subject;
	int grade;

	cout << "fio? ";
	cin >> fio;
	cout << "subject? ";
	cin >> subject;
	cout << "grade? ";
	cin >> grade;

	exam t(fio, subject, grade);
	return t;
}

// функция для передачи объекта как параметра
void print_exam(exam t) {
	t.show();
}

int main()
{
	// конструктор без параметров
	exam t1;
	t1.show();
	// конструктор с параметрами
	exam t2("Vysotskaya Alena", "Math", 4);
	t2.show();

	// конструктор копирования
	exam t3 = t2;
	t3.show();
	t3.set_FIO("Ivanov Ivan");
	t3.set_subject("physics");
	t3.set_grade(3);

	t3.show();

	// использование функций 
	t1 = make_exam();
	print_exam(t1);

	return 0;
}
