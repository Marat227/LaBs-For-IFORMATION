#pragma once
#include "Pair.h"
#include <iostream> 
#include <fstream> 
#include <string> 
using namespace std;

int make_file(const char* filename)
{
	fstream stream(filename, ios::out | ios::trunc); // îòêðûòü äëÿ çàïèñè
	if (!stream) return -1;
	int n;
	Pair p;
	cout << "Ðàçìåð: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> p;
		stream << p << '\n'; // çàïèñü îáúåêòà â ôàéëîâûé ïîòîê
	}
	stream.close();
	return n;
}

int PrintFromFile(const char* filename)
{
	fstream stream(filename, ios::in);
	if (!stream) return -1;
	Pair p;
	int i = 0;
	while (stream >> p)
	{
		cout << p;
		i++;
	}
	stream.close();
	return i;
}

int del_file(const char* filename, Pair t)
{
	fstream temp("temp", ios::out);
	fstream stream(filename, ios::in);
	if (!stream) return -1;
	int i = 0;
	Pair p;
	while (stream >> p && !stream.eof())
	{
		i++;
		if (t < p) temp << p;
	}
	stream.close();
	temp.close();
	remove(filename); // Óäàëåíèå ôàéëà ñ èìåíåì filename
	rename("temp", filename); // Ïåðåèìèíîâûâàíèå ôàéëà
	return i;
}

int add_file(const char* filename, int k, int count)
{
	fstream temp("temp", ios::out);
	fstream stream(filename, ios::in);
	if (!stream) return -1;
	Pair p;
	int i = 0, l = 0;
	while (stream >> p && !stream.eof())
	{
		i++;
		temp << p;
		if (i == k)
		{
			for (int j = 0; j < count; j++)
			{
				Pair new_Pair;
				cout << "Ââåäèòå íîâóþ ïàðó ÷èñåë" << endl;
				cin >> new_Pair;
				temp << new_Pair;
				l++;
			}
		}
	}
	stream.close();
	temp.close();
	remove(filename);
	rename("temp", filename);
	return l;
}

int add_end(const char* filename, int count)
{
	fstream stream(filename, ios::app); // çàïèñü â êîíåö ôàéëà
	if (!stream) return -1;
	for (int i = 0; i < count; i++)
	{
		Pair new_Pair;
		cout << "Ââåäèòå íîâóþ ïàðó ÷èñåë" << endl;
		cin >> new_Pair;
		stream << new_Pair;
	}
	return 1;
}

int change_file(const char* filename, double k)
{
	fstream temp("temp", ios::out);
	fstream stream(filename, ios::in);
	if (!stream) return -1;
	Pair p;
	int l = 0;
	while (stream >> p && !stream.eof())
	{
		if (k == (int)k) p + (int)k;
		else p + k;
		temp << p;
	}
	stream.close();
	temp.close();
	remove(filename);
	rename("temp", filename);
	return l;
}