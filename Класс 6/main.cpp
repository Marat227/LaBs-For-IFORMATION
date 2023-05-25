#include <iostream>
#include "list.h"
#include <Windows.h>
using namespace std;

void listFillFunction(List&, int);

int main() {
	int n;
	cout << "Enter the number of elements in da list: "; cin >> n;
	List ListOne;
	listFillFunction(ListOne, n);

	cout << "Your list have length " << ListOne() << "\n"
		<< "And this are your list: " << ListOne << endl;

	cout << "Enter the number of elements in da second list: "; cin >> n;
	List ListTwo;
	listFillFunction(ListTwo, n);

	cout << "Your list have length " << ListTwo() << "\n"
		<< "And this are your list: " << ListTwo << endl;

	List ListThree = ListOne * ListTwo;
	cout << "Their * is: " << ListThree;


	Iterator it = ListThree.first();
	cout << "Enter the number of elements you want to move for: "; cin >> n;
	it + n;
	cout << "Third list have num " << *it << " under " << n + 1 << " number" << endl;

	return 0;
}

void listFillFunction(List& tList, int n) {
	for (int i = 0; i < n; i++) {
		cin >> tList;
	}
}
