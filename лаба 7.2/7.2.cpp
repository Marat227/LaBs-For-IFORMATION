﻿#include <iostream>
using namespace std;

void d2t(int cnt, ...)
{
	int* p = &cnt;
	for (; cnt != 0; cnt--)
	{
		int dec = *(++p);
		cout << "Число " << dec << " в троичной системе счисления: ";

		string result = "";
		while (dec > 0)
		{
			result.insert(result.begin(), (dec % 3) + '0');
			dec /= 3;
		}
		if (result == "")
		{
			result += "0";
		}
		cout << result << endl;
	}
}

int main()
{
	setlocale(0, "RUS");
	cout << "Написать функцию с переменным числом параметров для перевода чисел из десятичной системы счисления в" << endl
		<< "троичную. Написать вызывающую функцию main, которая обращается к этой функции не менее трех раз с" << endl
		<< "количеством параметров 3, 4, 7" << endl << endl;
	cout << "d2t(2, 15, 33)" << endl;
	d2t(3, 2, 15, 33);
	cout << "d2t(3, 0, 3, 10)" << endl;
	d2t(4, 3, 0, 3, 10);
	cout << "d2t(6, 30, 45, 50, 1001, 500, 9999)" << endl;
	d2t(7, 6, 30, 45, 50, 1001, 500, 9999);
	return 0;
}
