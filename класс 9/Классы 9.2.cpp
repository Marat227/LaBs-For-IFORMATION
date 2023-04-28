#include<iostream>
#include<ctime>
#include<string>
using namespace std;
int max_size = 6;
class error
{
private:
	string msg;
public:
	error(string msg)
	{
		this->msg = msg;
	}
	void what()
	{
		cout << "Произошла ошибка: " << msg << endl;
	}
};
class host
{
private:
	int size;
	int* array;
public:
	host()
	{
		size = 0;
		array = 0;
	}
	host(int size)
	{
		this->size = size;
		if (size > max_size) { throw error("Недопустимый размер множества!"); }
		array = new int[size];
		for (int i = 0; i < size; i++)
		{
			array[i] = rand() % 100 + 1;
		}

	}
	host(int size, int* array)
	{
		this->size = size;
		array = new int[size];
		for (int i = 0; i < size; i++)
		{
			this->array[i] = array[i];
		}


	}
	host(const host& other)
	{
		this->size = other.size;
		array = new int[size];
		for (int i = 0; i < size; i++)
		{
			array[i] = other.array[i];
		}
	}
	~host()
	{
	}
	void show()
	{
		for (int i = 0; i < size; i++)
		{
			cout << array[i] << " ";
		}
		cout << endl;
	}
	int& operator () () { return size; }
	host operator - (const host& other)
	{
		host tmp(size);
		for (int i = 0; i < size; i++)
		{
			tmp.array[i] = array[i] - other.array[i];
		}
		delete[]array;
		return tmp;
	}
	int& operator [](int index)
	{

		if (index >= 0 && index < size)
		{
			return array[index];
		}
		else
		{
			cout << endl;
			throw error("Недопустимый индекс");
		}
	}
	host operator --()
	{
		if (size == 0) { throw error("Невозможно удалить элемент, размер множества равен 0"); }
		if (size == 1)
		{
			size = 0;
			delete[]array;
			array = 0;
			return*this;
		}
		int tmp_size = size--;
		host tmp(tmp_size);
		for (int i = 0; i < tmp_size; i++)
		{
			tmp.array[i] = 0;
		}
		for (int i = 0; i < tmp_size; i++)
		{
			tmp.array[i] = array[i];
		}
		return tmp;
		delete[]array;
	}


};


int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(0));
	try
	{
		host first(3);//host first(0) - ошибка при удалении. host first(8)-ошибка при создании
		first.show();
		--first;
		first.show();
		cout << "Элемент с избранным индексом: " << first[0] << endl;//first[5] - ошибка вывода, такого элемента нет.
		cout << "Размер множества: " << first() << endl;
		host second(2);
		second.show();
		host third(2);
		third = first - second;
		third.show();
	}
	catch (error ER)
	{
		ER.what();
	}
	return 0;
}
