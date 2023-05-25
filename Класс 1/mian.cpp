include <iostream>
#include <Fraction.h>
#include <Windows.h>
using namespace std;

Fraction makeFraction(double, int);

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Fraction A;
	Fraction B;
	A.Init(3.0, 2);
	B.Read();
	A.Show();
	B.Show();
	int j1, j2;
	cout << "Введите номер какого элемента вы хотите получить " << endl;
	cout << "j1: "; cin >> j1;
	cout << "j2: "; cin >> j2;
	cout << A.Element(5) << endl;
	cout << B.Element(6) << endl;

	Fraction* X = new Fraction;
	X->Init(2.0, 5);
	X->Show();

	Fraction mas[3];
	for (int i = 0; i < 3; i++) mas[i].Read();
	for (int i = 0; i < 3; i++) mas[i].Show();
	for (int i = 0; i < 3; i++) {
		cout << " Степень? " << endl;
		cout << "j:"; cin >> j1;
		mas[i].Element(j1);
	}
	Fraction* p_mas = new Fraction[3];
	for (int i = 0; i < 3; i++) p_mas[i].Read();
	for (int i = 0; i < 3; i++) p_mas[i].Show();
	for (int i = 0; i < 3; i++) {
		cout << " Степень? " << endl;
		cout << "j:"; cin >> j1;
		cout << mas[i].Element(j1) << endl;
	}
	double y; int z;
	cout << "first?"; cin >> y;
	cout << "second?"; cin >> z;
	//переменная F формируется с помощью функции make_fraction()
	Fraction F = makeFraction(y, z);
	F.Show();
	return 0;
}

Fraction makeFraction(double f, int s) {
	Fraction t;
	t.Init(f, s);
	return t;
}

