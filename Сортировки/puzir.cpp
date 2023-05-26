#include <iostream>
using namespace std;

void bubbleSort(int list[], int listLength)
{
	while (listLength--)
	{
		bool swapped = false;

		for (int i = 0; i < listLength; i++)
		{
			if (list[i] > list[i + 1])
			{
				swap(list[i], list[i + 1]);
				swapped = true;
			}
		}

		if (swapped == false)
			break;
	}
}

int main()
{
	int list[5] = { 3,19,8,0,48 };
	cout << "Input array ..." << endl;
	for (int i = 0; i < 5; i++)
		cout << list[i] << '\t';
	cout << endl;

	bubbleSort(list, 5);

	cout << "Sorted array ..." << endl;
	for (int i = 0; i < 5; i++)
		cout << list[i] << '\t';
	cout << endl;
}