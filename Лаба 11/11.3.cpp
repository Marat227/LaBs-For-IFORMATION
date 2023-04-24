#include <iostream>
using namespace std;
char el;

struct Stack
{
	char data;
	Stack* prev;
};

Stack* Create(int n)
{
	if (n == 0)
	{
		return NULL;
	}
	Stack* top, * p;
	top = NULL;
	p = new Stack;

	cout << "Введите элементы: ";
	cin >> el;
	p->data = el;
	p->prev = NULL;
	top = p;

	for (int i = 2; i <= n; i++)
	{
		Stack* h = new Stack;

		cin >> el;
		h->data = el;
		h->prev = top;
		top = h;
	}
	return top;
}

void Print(Stack* top)
{
	if (top == NULL)
	{
		cout << "Стек пуст" << endl;
	}

	else
	{
		Stack* p = top;

		while (p != NULL)
		{
			cout << p->data << " ";
			p = p->prev;
		}
		cout << endl;
	}
}

void Add(Stack*& first, int n)
{
	Stack* p = first;
	Stack* h = new Stack;

	cout << "Введите элементы для добавления: ";
	cin >> h->data;
	h->prev = p;
	first = h;

	while (p->prev != NULL)
	{
		Stack* h = new Stack;

		cin >> h->data;
		h->prev = p->prev;
		p->prev = h;

		if (p->prev->prev != NULL)
		{
			p = p->prev->prev;
		}
		else
		{
			p = p->prev;
		}
	}
}

int main()
{
	setlocale(LC_ALL, "Rus");
	cout << "Введите количество элементов: ";
	int count;
	cin >> count;
	Stack* st = Create(count);
	cout << "Стек: ";
	Print(st);
	Add(st, count);

	cout << "Изменённый стек: ";
	Print(st);
	return 0;
}
