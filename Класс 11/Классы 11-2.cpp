﻿#include "Pair.h"
#include <iostream>
#include <list> 
#include <cstdlib> 
using namespace std;
typedef list<Pair>List;

List make_list(int n) // Create a list
{
	List l;
	for (int i = 0; i < n; ++i)
	{
		Pair a;
		cin >> a;
		l.push_back(a); // add "l" to the end of the list
	}
	return l; // return created list
}

void print(List& l) // print list
{
	for (auto it = l.begin(); it != l.end(); ++it) // print list from start (with begin()) to finish (with end())
		cout << *it;
	cout << endl;
}

Pair average(List& l) // finding the arithmetic mean
{
	Pair s;
	for (auto it = l.begin(); it != l.end(); ++it) s += *it;
	s = s / l.size();
	return s;
}

void add_list(List& l, Pair el)
{
	l.insert(l.end(), el);
}

void remove_elements(List& l, Pair rmin, Pair rmax)
{
	if (rmax < rmin) swap(rmin, rmax);
	for (auto it = l.begin(); it != l.end();)
	{
		if (*it <= rmax && *it >= rmin)
			it = l.erase(it);
		else
			++it;
	}
}

Pair max(List& l)
{
	Pair max(INT_MIN, INT_MIN);
	for (auto it = l.begin(); it != l.end(); ++it)
		if (*it > max)
			max = *it;
	cout << "Максимальное значение: " << max << endl;
	return max;
}

Pair min(List& l)
{
	Pair min(INT_MAX, INT_MAX);
	for (auto it = l.begin(); it != l.end(); ++it)
		if (*it < min)
			min = *it;
	cout << "Минимальное значение: " << min << endl;
	return min;
}

void increase_elements(List& l, Pair min, Pair max)
{
	for (auto it = l.begin(); it != l.end(); ++it)
		*it = *it + min + max;
}

int main()
{
	setlocale(LC_ALL, "ru");
	try
	{
		list<Pair> l;
		int n;
		Pair range_min, range_max, min_el, max_el;
		cout << "Введите размер списка: ";
		cin >> n;
		l = make_list(n);
		print(l);
		Pair el = average(l);
		add_list(l, el);
		cout << "Среднее арифметическое было добавлено в конец списка\n";
		print(l);
		min_el = min(l);
		max_el = max(l);
		cout << "Увеличение всех элментов списка на сумму минимального и максимального:\n";
		increase_elements(l, min_el, max_el);
		print(l);
		cout << "Введите ключи пар:\nОТ\n";
		cin >> range_min;
		cout << "ДО\n";
		cin >> range_max;
		cout << "Список с удалёнными элементами:\n";
		remove_elements(l, range_min, range_max);
		print(l);
	}
	catch (int)
	{
		cout << "Произошла ошибка!";
	}
	return 0;
}