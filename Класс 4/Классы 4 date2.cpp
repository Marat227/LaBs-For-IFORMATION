#include "Date.h"

void DATE::data_(int n) {
	third = day + n;
	int t = 0;
	while (third > 31) {
		t++;
		third -= 31;
	}
	second += t;
	t = 0;

	while (second > 12) {
		t++;
		second -= 12;
	}
	first += t;
}

void DATE::year_1() {
	first++;
}

void DATE::month_1() {
	second++;
}

void DATE::day_1() {
	third++;
}
