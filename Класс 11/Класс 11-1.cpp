﻿#include <iostream>
#include <Windows.h>
#include <list> 
#include <cstdlib> 
#include <ctime>
using namespace std;
typedef list<double>List; // Type of work with my list

List make_list(int n) // Create a list
{
	srand(time(0));
	List l;
	for (int i = 0; i < n; ++i)
	{
		double a = round(((double)(rand()) / RAND_MAX * 10 + 1) * 100) / 100; // filling the list with random double
		l.push_back(a); // add "l" to the end of the list
	}
	return l; // return created list
}

void print(List& l) // print list
{
	for (auto it = l.begin(); it != l.end(); ++it) // print list from start (with begin()) to finish (with end())
		cout << *it << " ";
	cout << endl;
}

double average(List& l) // finding the arithmetic mean
{
	double a = 0;
	for (auto it = l.begin(); it != l.end(); ++it) a += *it;
	a = a / l.size();
	l.insert(l.end(), a); // add to the end of the list
	return a;
}

void range(List& l)
{
	double one, two;
	cout << "Укажите границы (ключи)" << endl;
	cout << "Введите первую границу: "; 
	cin >> one;
	cout << "Введите вторую границу:  "; 
	cin >> two;
	if (one > two) swap(one, two);
	for (auto it = l.begin(); it != l.end();)
	{
		if (*it >= one && *it <= two) it = l.erase(it);
		else ++it;
	}
}


void add_minmax(List& l)
{
	double maxi = l.front(), mini = l.front();
	for (auto it = l.begin(); it != l.end(); ++it)
	{
		if (*it > maxi) maxi = *it;
		if (*it < mini) mini = *it;
	}
	cout << "Минимальное знаечние: " << mini << endl;
	cout << "Максимальное значение: " << maxi << endl;
	for (auto it = l.begin(); it != l.end(); ++it) 
		*it = *it + mini + maxi;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	List l; int n;
	cout << "Введите размер: ";
	cin >> n;
	l = make_list(n);
	cout << "\nСреднее арифметическое  значение: " << average(l) << endl;
	print(l);
	cout << "\nПрибавление к каждому элементу списка суммы минимального и максимального значений\n";
	add_minmax(l);
	print(l);
	cout << "\nСписок с удалёнными элементами\n";
	range(l);
	print(l);
	return 0;
}