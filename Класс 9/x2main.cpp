#include <iostream>
#include "List.h"
using namespace std;

int main() {

	try {
		List a;
		int n;
		cout << "n? "; cin >> n;
		for (int i = 0; i < n; i++) {
			int data;
			cin >> data;
			a.push(data);
		}
		int indx;
		cout << "indx? " << endl; cin >> indx;

		cout << "your elem: " << a[indx] << endl;

		cout << "-------------" << endl;
		Iterator beg = a.first();
		cout << "elem? " << endl;
		cin >> n;
		beg + --n;
		cout << *beg;

	}
	catch (Error& e) {
		e.what();
	}
	return 0;
}
