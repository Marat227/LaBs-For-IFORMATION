#include <iostream>
#include "Magazin.h"
#include "Print.h"
#include "Dialog.h"
#include <Windows.h>
using namespace std;

int main() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	cout << "m + число - создать группу" << endl;
	cout << "+ добавить элемент в группу" << endl;
	cout << "- удалить элемент из группы" << endl;
	cout << "s вывести информацию об элементах группы" << endl;
	cout << "z вывести информацию об названиях группы" << endl;
	cout << "q конец" << endl;



	Dialog D;
	D.execute();

	return 0;
}
