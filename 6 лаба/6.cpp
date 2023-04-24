#include <iostream>
#include <string>

int main()
{
    setlocale(LC_ALL, "Russian");
    std::string s1;
    std::string tempStr;
    std::string spb = " ";
    int n;

    n = 0;

    std::cout << "Введите строку" << std::endl;
    std::getline(std::cin >> std::ws, s1);

    for (int i = 0; i < s1.size(); i++)
    {
        if (s1[i] == spb[0])
        {
            tempStr.assign(s1, n, i - n);
            if ((s1.find(tempStr) == n) && (s1.rfind(tempStr) == n))
            {
                std::cout << "Слово " << tempStr << " встречается один раз" << std::endl;
            }
            n = i += 1;
        }
    }
    tempStr.assign(s1, n, s1.size() - n);
    if ((s1.find(tempStr) == n) && (s1.rfind(tempStr) == n))
    {
        std::cout << "Слово " << tempStr << " встречается один раз" << std::endl;
    }
    return 0;
}

