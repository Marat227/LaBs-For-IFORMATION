#pragma once
#include <iostream>
#include <fstream>

class Pair {
private:
	int first;
	double second;
public:
	Pair();
	Pair(int, double);
	Pair(Pair&);
	~Pair() {};

	int getFirst();
	void setFirst(int);
	double getSecond();
	void setSecond(double);

	void show();

	template <typename T>
	Pair& operator+(const T);

	Pair& operator-(const Pair&);
	Pair& operator=(const Pair&);
	friend std::istream& operator>>(std::istream&, Pair&);
	friend std::ostream& operator<<(std::ostream&, const Pair&);

	friend std::fstream& operator<<(std::fstream&, const Pair&);
	friend std::fstream& operator>>(std::fstream&, Pair&);
};

template <typename T>
Pair& Pair::operator+(const T p) {
	if (p != (int)p) {
		second += p;
	}
	else {
		first += p;
	}
	return *this;
}

