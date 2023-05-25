#include "Header.h"
#include "Pair.h"
#include <iostream>

using namespace std;

int main() {
	List<int> listInt;

	List<Pair> listPair;

	Pair c;

	listPair.push(c);
	c.first = 3;
	c.second = 5.5;
	listPair.push(c);

	cout << "listPair: " << listPair << endl;

	cout << "Enter first elem in da listPair" << endl;
	cin >> listPair[1];
	cout << "listPair[1] " << listPair[1] << endl;


	listInt.push(3);
	listInt.push(5);

	cout << "listInt: " << listInt << endl;

	List<double> listDouble;

	listDouble.push(4.5);
	listDouble.push(6.4);

	cout << "listDouble: " << listDouble << endl;

	cout << "Enter elements in da list double" << endl;
	cin >> listDouble;
	cout << listDouble;

	return 0;
}

void listFillFunction(List& tList, int n) {
	for (int i = 0; i < n; i++) {
		cin >> tList;
	}
}
