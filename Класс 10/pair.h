#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class Pair
{
	int first;
	double second;
public:
	Pair()
	{
		first = 0; second = 0;
	}
	Pair(int f, double s) { first = f; second = s; }
	Pair(const Pair& p) { first = p.first; second = p.second; }
	~Pair() {};
	Pair operator =(const Pair&);
	Pair operator -(const Pair& p);
	Pair& operator +(const int x);
	Pair& operator +(const double x);
	bool operator <(const Pair&); 
	friend istream& operator>>(istream& in, Pair& p);
	friend ostream& operator<<(ostream& out, const Pair& p);
	
	friend fstream& operator>>(fstream& fin, Pair& p);
	friend fstream& operator<<(fstream& fout, const Pair& p);
};