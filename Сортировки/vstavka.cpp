#include <iostream>
using namespace std;

void insertionSort(int list[], int listLength)
{
	for (int i = 1; i < listLength; i++)
	{
		int j = i - 1;
		while (j >= 0 && list[j] > list[j + 1])
		{
			swap(list[j], list[j + 1]);
			cout << "\ndid";
			j--;
		}
	}
}

int main()
{
	int list[8] = { 3,19,8,0,48,4,5,12 };
	cout << "Input array ...\n";
	for (int i = 0; i < 8; i++)
	{
		cout << list[i] << "\t";
	}

	insertionSort(list, 8);

	cout << "\n\nSorted array ... \n";
	for (int i = 0; i < 8; i++)
	{
		cout << list[i] << "\t";
	}

	return 0;
}