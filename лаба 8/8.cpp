#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <istream>
using namespace std;

const int buf_s = 32;
struct Student
{
	char surname[buf_s];
	char name[buf_s];
	char patr[buf_s];
	char phone[buf_s];
	int group;
	int mark[3];

	void set_surname(const char* sur)
	{
		strncpy(this->surname, sur, buf_s);
	};
	void set_name(const char* name)
	{
		strncpy(this->name, name, buf_s);
	};
	void set_patr(const char* patr)
	{
		strncpy(this->patr, patr, buf_s);
	};
	void set_phone(const char* phone)
	{
		strncpy(this->phone, phone, buf_s);
	};
	void set_group(const int& g)
	{
		this->group = g;
	};

	void set_marks(const int& f, const int& s, const int& t)
	{
		this->mark[0] = f;
		this->mark[1] = s;
		this->mark[2] = t;
	};

	void show()
	{
		cout << endl;
		cout << "Surname: " << this->surname << endl;
		cout << "Name: " << this->name << endl;
		cout << "Patr: " << this->patr << endl;
		cout << "Phone: " << this->phone << endl;
		cout << "Group: " << this->group << endl;
		cout << "Marks: " << this->mark[0] << ", " << this->mark[1] << ", " << this->mark[2] << endl;
	}

	double average()
	{
		double r = 0;
		for (int i = 0; i < 3; i++)
		{
			r += this->mark[i];
		}
		return r / 3;
	};

	friend istream& operator>>(istream& stream, Student& st)
	{
		string tmp;
		cout << endl;
		cout << "Surname: ";
		stream >> tmp;
		st.set_surname(tmp.c_str());
		cout << "Name: ";
		stream >> tmp;
		st.set_name(tmp.c_str());
		cout << "Patr: ";
		stream >> tmp;
		st.set_patr(tmp.c_str());
		cout << "Phone: ";
		stream >> tmp;
		st.set_phone(tmp.c_str());
		int t;
		cout << "Group: ";
		stream >> t;
		st.set_group(t);
		int j, k;
		cout << "Marks: ";
		stream >> t >> j >> k;
		st.set_marks(t, j, k);
		cout << endl;
		return stream;
	};

	Student& operator=(const Student& st)
	{
		this->set_name(st.name);
		this->set_surname(st.surname);
		this->set_patr(st.patr);
		this->set_phone(st.phone);
		this->set_group(st.group);
		this->set_marks(st.mark[0], st.mark[1], st.mark[2]);
		return *this;
	}

};

template<class T>
void PushBack(T*& mas, int& size, const T& value)
{
	T* tmp = new T[size + 1];
	for (int i = 0; i < size; i++)
	{
		tmp[i] = mas[i];
	}
	tmp[size] = value;
	delete[] mas;
	mas = tmp;
	size++;
};

void DeleteLowerAverage(Student*& mas, int& size, const double& value)
{
	int tmp_size = 0;
	Student* tmp = new Student[tmp_size];

	for (int i = 0; i < size; i++)
	{
		if (mas[i].average() >= value)
		{
			PushBack(tmp, tmp_size, mas[i]);
		}
	}
	delete[] mas;
	mas = tmp;
	size = tmp_size;
};

template <class T>
void InsertAt(T*& mas, int& N, const int& index, const T& value)
{
	T* result_mas = new T[N + 1];
	int c = 0;
	for (int i = 0; i < index; i++)
	{
		result_mas[c++] = mas[i];
	}
	result_mas[c++] = value;
	for (int i = index; i < N; i++)
	{
		result_mas[c++] = mas[i];
	}
	delete[] mas;
	mas = result_mas;
	N++;
};

int N;

std::string tmp;

int main()
{
	cout << "Amount of elements: ";
	cin >> N;
	cout << endl;
	Student* students = new Student[N];
	for (int i = 0; i < N; i++)
	{
		cin >> students[i];
		students[i].show();
		cout << students[i].average() << endl;
	}
	double average;
	cout << endl << "Input Average: ";
	cin >> average;

	DeleteLowerAverage(students, N, average);
	cout << endl << "After delete: " << endl;
	for (int i = 0; i < N; i++)
	{
		students[i].show();
		cout << students[i].average() << endl;
	}

	char surname[buf_s];
	cout << endl << "Input surname: ";
	cin >> surname;
	int index = -1;
	for (int i = 0; i < N; i++)
	{
		if (strcmp(students[i].surname, surname) == 0)
		{
			index = i;
			break;
		}
	}

	if (index != -1)
	{
		cout << endl << "Input student: ";
		Student ins;
		cin >> ins;
		cout << endl;
		InsertAt(students, N, index + 1, ins);
		cout << endl << "After Inserting: " << endl;
		for (int i = 0; i < N; i++)
		{
			students[i].show();
		}
	}
	else
	{
		cout << "No matching found! " << endl;
	}
	delete[] students;
	return 0;
}
