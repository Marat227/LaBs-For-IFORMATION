#include <iostream>
#include <ctime>
#include <string>
#include <iomanip>

float funct(int[], float);
int funct(std::string);

int main()
{
    setlocale(LC_ALL, "Russian");
    std::string s1;
    int arr[100];
    int change;
    float n;
    float sredAr;

    std::cout << "Будем работать со строкой(1) или целочисленными значениями(2)?" << std::endl;
    std::cin >> change;

    switch (change)
    {
    case(1):
    {
        std::cout << "Введите строку на английском" << std::endl;
        std::getline(std::cin >> std::ws, s1);
        int size = funct(s1);
        std::cout << "Количество букв в строке: " << size << std::endl;
        break;
    }
    case(2):
    {
        std::cout << "Введите длину последовательности" << std::endl;
        std::cin >> n;

        std::cout << "Введите последовательность" << std::endl;
        for (int i = 0; i < n; i++)
        {
            std::cin >> arr[i];
        }
        float sredAr = funct(arr, n);
        std::cout << "Среднее арифметическое последовательности:" << sredAr << std::endl;
        break;
    }
    default: {std::cout << "Такого варианта нет" << std::endl; break; }
    }
    return 0;
}

int funct(std::string s1)
{
    int len;
    len = s1.length();
    char alf[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int n = 0;

    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < 118; j++)
        {
            if (s1[i] == alf[j])
            {
                n = n + 1;
            }
        }
    }
    return n;
}

float funct(int arr[100], float n)
{
    float sum;
    float sredAr;

    sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum = sum + arr[i];
    }
    sredAr = sum / n;

    return sredAr;
}
