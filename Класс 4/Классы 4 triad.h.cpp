#pragma once
#include <iostream>
using namespace std;

class TRIAD
{
protected:
	int first;
	int second;
	int third;
public:
	// конструкторы
	TRIAD(int, int, int);
	TRIAD();
	TRIAD(TRIAD&);
	~TRIAD();

	// модификаторы
	void setFirst(int);
	void setSecond(int);
	void setThird(int);

	// селекторы
	int getFirst();
	int getSecond();
	int getThird();

	// перегрузка оператора присваивания 
	TRIAD& operator= (const TRIAD& p);

	// методы увеличения полей на 1
	void first_1();
	void second_1();
	void third_1();


	friend istream& operator>>(istream& in, TRIAD& t);
	friend ostream& operator<<(ostream& out, const TRIAD& tmp);
};
