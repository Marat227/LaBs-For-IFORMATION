#include <iostream>
#include <Windows.h>
#include <string>
#include <Salary.h>
using namespace std;

Salary makeStaff();
void print(Salary);

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Salary s1;		// конструктор без параметров
	s1.show();

	Salary s2("Графинин Граф Евграфович", 200000, 34);	// Конструктор с параметрами
	s2.show();

	Salary s3 = s2;			// Конструктор копирования
	print(s3);				// конструктор копирования
	// Вызов деструктора (так как в пар-рах функции не ссылка)
	Salary s4 = makeStaff();
	s4.show();

	// Деструктор вызывается для каждого объекта

	return 0;
}

Salary makeStaff() {
	string name; double r; int i;
	cout << "Введите имя?" << endl;
	getline(cin, name);
	cout << "Зарплата?" << endl;
	cin >> r;
	cout << "Премия (%)?" << endl;
	cin >> i;

	Salary t(name, r, i);			// конструктор с параметрами
	return t;						// конструктор копирования, затем деструктор, так как заканчивается время жизни
}

void print(Salary t) {
	t.show();
}
