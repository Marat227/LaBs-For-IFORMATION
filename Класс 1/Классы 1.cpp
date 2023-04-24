#include <iostream>
#include <cmath>
#include "legs.h"			// подключение заголовочного файла

using namespace std;

// метод инициализации
void legs::Init(double f, double s) {
	first = f;
	second = s;
}

// ввод с клавиатуры
void legs::Read() {
	cout << "\nfirst? ";
	cin >> first;
	cout << "\nsecond? ";
	cin >> second;
}

// вывод на экран
void legs::Show() {
	cout << "\nfirst = " << first;
	cout << "\nsecond = " << second;
	cout << "\n";
}

// вычисление гипотенузы
double legs::hipotenuse() {
	return sqrt(pow(first, 2) + pow(second, 2));


#pragma once

	struct legs
	{
		double first;    // катет a
		double second;   // катет b

		void Init(double, double);	// метод инициализации
		void Read();				// ввод с клавиатуры
		void Show();				// вывод на экран
		double hipotenuse();		// вычисление гипотенузы

	};


#include <iostream>
#include "legs.h"

	using namespace std;

	legs make_legs(double f, double s) {
		legs temp;
		temp.Init(f, s);
		return temp;
	}

	int main()
	{
		// определение переменных A и B
		legs A;
		legs B;
		// инициализация переменных A и B, с помощью метода Init и Read, соответственно
		A.Init(4.02, 5.25);
		B.Read();
		// Вывод значений полей переменных A и B
		A.Show();
		B.Show();

		// вывод значения гипотенузы, вычисленной с помощью функции hipotenuse
		cout << "A.hipotenuse(" << A.first << ", " << A.second << ")=" << A.hipotenuse() << endl;
		cout << "B.hipotenuse(" << B.first << ", " << B.second << ")=" << B.hipotenuse() << endl;

		// указатели
		legs* X = new legs;
		X->Init(1.56, 12.3);
		X->Show();
		cout << "X.hipotenuse(" << X->first << "," << X->second << ") = " << X->hipotenuse();

		// массивы
		legs mas[3];
		for (int i = 0; i < 3; i++) {
			mas[i].Read();
		}
		for (int i = 0; i < 3; i++) {
			mas[i].Show();
		}
		for (int i = 0; i < 3; i++) {
			cout << "mas[" << i << "].hipotenuse(" << mas[i].first << "," << mas[i].second << ")=";
			cout << mas[i].hipotenuse() << endl;
		}

		// динамические массивы
		legs* p_mas = new legs[3];
		for (int i = 0; i < 3; i++) {
			p_mas[i].Read();
		}
		for (int i = 0; i < 3; i++) {
			p_mas[i].Show();
		}
		for (int i = 0; i < 3; i++) {
			cout << "p_mas[" << i << "].hipotenuse(" << p_mas[i].first << "," << p_mas[i].second << ")=";
			cout << p_mas[i].hipotenuse() << endl;
		}

		// вызов функции make_legs()
		double y, z;
		cout << "\nfirst? ";
		cin >> y;
		cout << "\nsecond? ";
		cin >> z;

		// переменная F формируется с помощью функции make_legs()
		legs F = make_legs(y, z);
		F.Show();

		return 0;
	}
}
