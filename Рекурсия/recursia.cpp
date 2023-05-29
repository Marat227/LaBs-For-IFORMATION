#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;
void prefix(const string& s2, int* pi) //Префикс-функция
{
    int n2 = s2.length();
    pi[0] = 0;
    int j = 0;
    int i = 1;
    while (i < n2)
    {
        if (s2[i] != s2[j]) //Проверка на несовпадение символов строки
        {
            if (j == 0) // Первому элементу префиксной функции присваивается значение 0
            {
                pi[i] = 0;
                i++;
            }
            else
            {
                if (j > 0) j = pi[j - 1]; // индексу j присваевается значение предыдущего элемента префиксной функции
            }
        }
        else // Если символы совпадают 
        {
            pi[i] = j + 1; // Присваивается следующее по величине значение (первый элемент - 0, следующий 1..)
            i++;
            j++;
        }
    }
}
int KMP(const string& s1, const string& s2)
{
    setlocale(LC_ALL, "RUS");
    int n1 = s1.length();
    int n2 = s2.length();
    int* p = new int[n2];
    prefix(s2, p);
    int i = 0;
    int j = 0;
    while (i < n1) // Идёт до конца строки
    {
        if (s1[i] == s2[j]) // проверка элементов строки и образа на совпадение
        {
            i++;
            j++;
            if (j == n2) return i - n2 + 1; // Если количество совпавших символов равняется длине подстроки, выводится сообщение
        }
        else
        {
            if (j > 0) j = p[j - 1]; // Если встречается несовпадение, то указатель перемещается в соответствии с префикс-функцией
            else
            {
                i++; // Если не совпал самый первый элемент, указатель смещвается на один вправо по строке
            }
        }
    }
    return -1;
    delete[] p;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string s1, s2;
    cout << "Введите строку: ";
    getline(cin, s1);
    cout << "Введите подстроку для поиска: ";
    getline(cin, s2);
    if (KMP(s1, s2) == -1) cout << "Подстрока не найдена!" << endl;
    else cout << "Номер первого вхождения первого символа подстроки: " << KMP(s1, s2) << endl;
    return 0;
}
