﻿#include "Pair.h"
#include "file_work.h" 
#include <iostream> 
#include <fstream>
#include <string> 
#include <Windows.h>
using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Pair p, temp;
	int k, c, num, count;
	double plus;
	char filename[30];
	do {
		system("pause");
		system("cls");
		cout << "1. Создать файл" << endl;
		cout << "2. Вывести из файла" << endl;
		cout << "3. Удалить записи, меньшие заданного значения" << endl;
		cout << "4. Добавить K записей после элемента с заданным номером" << endl;
		cout << "5. Увеличить все записи с заданным значнением на число типа int/double" << endl;
		cout << "0. Выход" << endl;
		cout << "Номер операции: ";
		cin >> c;
		switch (c)
		{
		case 1:
			cout << "Имя файла: ";
			cin >> filename;
			k = make_file(filename); // Size of the file
			if (k < 0) cout << "Укажите размер корректно!\n";
			break;
		case 2:
			cout << "Имя файла: ";
			cin >> filename;
			k = PrintFromFile(filename);
			if (k == 0) cout << "Файл пуст\n";
			if (k < 0) cout << "Файл не удалось прочитать\n";
			break;
		case 3:
			cout << "Имя файла: ";
			cin >> filename;
			cout << "Введите значение, все пары меньше которого будут удалены" << endl;
			cin >> temp;
			k = del_file(filename, temp);
			if (k < 0) cout << "Произошла ошибка\n";
			break;
		case 4:
			cout << "Имя файла: ";
			cin >> filename;
			cout << "введите номер позиции, с которой будут вставляться пары: ";
			cin >> num;
			cout << "Количество новых пар: ";
			cin >> count;
			k = add_file(filename, num, count);
			if (k < 0) cout << "Произошла ошибка\n";
			if (k == 0) k = add_end(filename, count);
			break;
		case 5:
			cout << "Имя файла: "; cin >> filename;
			cout << "Введите число, которое будете прибавлять: ";
			cin >> plus;
			k = change_file(filename, plus);
			if (k < 0) cout << "Произошла ошибка\n";
			break;
		case 0:
			return 0;
		}
	} while (c != 0);
	return 0;
}