#include "Triad.h"
#include "Date.h"

using namespace std;
int main()
{
	setlocale(LC_ALL, "Rus");
	DATE D(2003, 03, 05);
	cout << "D (year, month, day): " << D << endl << endl;

	// увеличение даты на 45 дней
	D.data_(45);
	cout << "Увеличение даты на 45 дней\n";
	cout << "D: " << D << endl;

	// увеличение поля год на 1
	cout << "Увеличение поля год на 1\n";
	D.year_1();
	cout << "D: " << D << endl;

	// увеличение поля месяц на 1
	cout << "Увеличение поля месяц на 1\n";
	D.month_1();
	cout << "D: " << D << endl;

	// увеличение поля день на 1
	cout << "Увеличение поля день на 1\n";
	D.day_1();
	cout << "D: " << D << endl;

	return 0;
}
