#pragma once
#include "Triad.h"

class DATE : public TRIAD {
	int year = first;
	int month = second;
	int day = third;
public:

	DATE() {}
	DATE(int year, int month, int day) :TRIAD(year, month, day) {};
	~DATE() {}

	void data_(int);

	void year_1();

	void month_1();

	void day_1();

};
