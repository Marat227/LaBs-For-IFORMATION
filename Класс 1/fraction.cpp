#include <iostream>
#include <Fraction.h>
#include <cmath>
using namespace std;

void Fraction::Init(double F, int S) {
	first = F; second = S;
}

void Fraction::Show() {
	cout << "First: " << first << endl;
	cout << "Second: " << second << endl;
}

void Fraction::Read() {
	cout << "First? " << endl; cin >> first;
	cout << "Second? " << endl; cin >> second;
}

double Fraction::Element(int j) {
	return first * pow(second, j);
}
