#include <iostream>
#include <string>
#include <list>
using namespace std;

struct DoubleList
{
	int data;
	DoubleList* next;
	DoubleList* prev;
};
DoubleList* head;

void Add(int value, int position)
{

	DoubleList* node = new DoubleList;
	node->data = value;

	if (head == NULL)
	{
		node->next = node;
		node->prev = node;
		head = node;
	}

	else
	{
		DoubleList* p = head;

		for (int i = position; i > 0; i--)

			p = p->next;
		p->prev->next = node;
		node->prev = p->prev;
		node->next = p;
		p->prev = node;
	}
}

int Delete(int position)
{
	if (head == NULL)
	{
		cout << "\nСписок пуст\n\n";
		return 0;
	}

	if (head == head->next)
	{
		delete head;
		head = NULL;
	}

	else
	{
		DoubleList* a = head;

		for (int i = position; i > 1; i--)
		{
			a = a->next;
		}

		if (a == head)
		{
			head = a->next;
		}
		a->prev->next = a->next;
		a->next->prev = a->prev;
		delete a;
	}
}

void Print()
{
	DoubleList* a = head;

	do
	{
		cout << a->data << " ";
		a = a->next;
	} while (a != head);
	cout << "\n\n";
}

void double_list()
{
	int numbersCount = -1;
	int k, j = -1;

	while (numbersCount <= 0)
	{
		cout << "Введите количество элементов списка: ";
		cin >> numbersCount;
	}

	cout << "Введите элементы списка:" << endl;
	for (int i = 0; i < numbersCount; i++)
	{
		cin >> k;

		Add(k, i);

		if (k % 2 == 0)
		{
			j = i + 1;
		}
	}

	if (j == -1)
	{
		cout << "Четных элементов нет";
	}
	else
	{
		Delete(j);
		cout << "Измененный список: ";
		Print();
	}
}

int main()
{
	setlocale(LC_ALL, "ru");

	double_list();

	return 0;
}
