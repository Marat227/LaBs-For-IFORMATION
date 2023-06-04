#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
using namespace std;
struct point // узел
{
	string key; // Информация в узле
	point* prev, * next; // Указатель на следующий элемент
};

point* MakeStack(int n) // Создание и заполнение стэка
{
	cout << "Введите информацию, которую хотите записать: " << endl;
	string s;
	getline(cin, s);
	getline(cin, s);
	point* p, * r, * van;
	p = new (point);
	p->key = s;
	p->prev = nullptr;
	p->next = nullptr;
	van = p;

	for (int i = 1; i < n; i++) //добавить элементы в конец стека
	{
		r = new(point);
		cout << "Введите информацию, которую хотите записать: " << endl;
		string s;
		getline(cin, s);
		r->key = s;
		p->next = r;
		r->prev = p;
		r->next = nullptr;
		p = r;
	}
	return van;
}

void print_list(point* van) // Вывод стэка на консоль
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	if (van == 0) //если стэк пустой
	{
		cout << "Стэк пустой\n" << endl;
		return;
	}
	point* p = van;
	int i = 1;
	cout << "Ваш стэк:" << endl;
	while (p != 0) //пока не конец стэка
	{
		cout << i << ". " << p->key << endl; // Вывод информации, содержащейся в узле
		p = p->next; //перейти на следующий элемент
		i++;
	}
	cout << "\n";
}

point* pop(point* van) // Удаляет последний элемент
{
	point* p = van;
	if (van == nullptr) return nullptr;
	if (p->next == nullptr) {
		van = van->next;
		if (van == nullptr) return nullptr;
		van->prev = nullptr;
		delete p;
		return van;
	}
	while (p->next != nullptr) p = p->next;
	point* r = p->prev;
	delete p;
	r->next = nullptr;
	return van;
}

point* push(point* ctrl) // Добавляет элемент в конец
{
	setlocale(LC_ALL, "ru");
	point* p;
	p = new(point);
	cout << "Введите новую информацию: " << endl; // Заполнение нового нового узла информацией
	string s;
	getline(cin, s);
	getline(cin, s);
	p->key = s;
	point* r = ctrl; //встать на начало стэка
	while (r->next != nullptr)  r = r->next;
	r->next = p; //связать р с концом стэка
	p->prev = r; //связать р и r
	p->next = nullptr;
	return ctrl;
}
point* delete_list(point* van) // Удалить стэк
{
	while (van) van = pop(van);
	return van;
}

void printINfile(point* van, string path) // Запись стэка в файл
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	ofstream fout;
	fout.open(path);
	if (!fout.is_open()) { cout << "Ошибка открытия файла!" << endl; }
	else {
		point* p = van;
		while (p != nullptr) {
			fout << p->key;
			fout << endl;
			p = p->next;
		}
	}
	cout << "Информация была внесена в файл" << endl;
	fout.close();
}

point* ReadFromFile(string path) // Восстановление информации из файла
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	ifstream fin;
	fin.open(path);
	point* van = new(point);
	if (!fin.is_open()) { cout << "Ошибка открытия файла!" << endl; }
	else {
		cout << "Информация была восстановлена!" << endl;
		string word;
		point* p, * r;
		p = new (point);
		fin >> word;
		p->key = word;
		p->prev = nullptr;
		p->next = nullptr;
		van = p;

		while (!fin.eof())
		{
			word = "";
			fin >> word;
			r = new(point);
			r->key = word;
			p->prev = nullptr;
			p->next = r;
			r->prev = p;
			r->next = nullptr;
			p = r;
		}
		p = p->prev;
		p = nullptr;
	}
	fin.close();
	return van;
}
void menu(int a, point* first, int n)
{
	setlocale(LC_ALL, "ru");
	int num;
	string path = "myFile.txt";
	point* second;
	switch (a)
	{
	case 0:
		exit(777);
	case 1:
		cout << "Введите размер стэка: " << endl;
		cin >> n;
		first = MakeStack(n);
		print_list(first);
		break;
	case 2:
		first = pop(first);
		print_list(first);
		break;
	case 3:
		push(first);
		print_list(first);
		break;
	case 4:
		first = delete_list(first);
		print_list(first);
		break;
	case 5:
		printINfile(first, path);
		break;
	case 6:
		first = ReadFromFile(path);
		print_list(first);
		break;
	default:
		cout << "Пожалуйста, введите номер операции верно" << endl;
		break;
	}
	system("pause");
	system("cls");
}
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int a = 1, n;
	cout << "Для работы с программой требуется создать стэк." << endl;
	cout << "Введите размер стэка: " << endl;
	cin >> n;
	point* first = MakeStack(n);
	while (true)
	{
		system("pause");
		system("cls");
		cout << "0. Выход" << endl;
		cout << "1. Создать стэк." << endl;
		cout << "2. Удалить элементы из стэка. " << endl;
		cout << "3. Добавить элементы в стэк" << endl;
		cout << "4. Удалить стэк." << endl;
		cout << "5. Записать стэк в файл." << endl;
		cout << "6. Восстановить стэк." << endl;
		cout << "Выберите действие: ";
		cin >> a;
		system("cls");
		menu(a, first, n);
	}
	return 0;
}
