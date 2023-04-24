﻿#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	setlocale(0, "RUS");
	int j = 0, z = 0, count = 0, max = -1, k = 0, num_s = 0;
	string row;
	char words[10][50];
	char word1[50];
	char word2[50];
	bool check = true;

	ifstream F1("F1.txt");
	ofstream F2("F2.txt");

	while (F1.eof() == false)
	{
		getline(F1, row);
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 50; j++)
			{
				words[i][j] = '*';
			}
		}
		j = 0; z = 0;
		for (int i = 0; i < row.length(); i++)
		{
			if (row[i] != ' ')
			{
				words[j][z] = row[i];
				z++;
			}

			if (row[i] == ' ' && row[i + 1] != ' ')
			{
				j++;
				z = 0;
			}
		}
		z = 0;
		for (int i = 0; i < 10; i++)
		{
			if (words[i][0] != '*')
			{
				count++;
			}
		}
		for (int i = 0; i < count - 1; i++)
		{
			for (int z = 0; z < 50; z++)
			{
				word1[z] = '*';
			}
			for (int z = 0; z < 50; z++)
			{
				word1[z] = words[i][z];
			}
			for (int j = i + 1; j < count; j++)
			{
				for (int z = 0; z < 50; z++)
				{
					word2[z] = words[j][z];
				}
				for (int z = 0; z < 50; z++)
				{
					if (word1[z] != word2[z])
					{
						check = false;
						break;
					}
				}
				if (check == true)
				{
					F2 << row << endl;
					break;
				}
				check = true;
				for (int z = 0; z < 50; z++)
				{
					word2[z] = '*';
				}
			}
		}
		for (int i = 0; i < count; i++)
		{
			for (int j = 0; j < 50; j++)
			{
				if (words[i][j] == 'a' || words[i][j] == 'A')
				{
					k++;
				}
			}
			if (k > max)
			{
				max = k;
				num_s = i + 1;
			}
			k = 0;
		}
		cout << "Больше всего букв 'A' в слове под номером " << num_s << " в строке " << row << endl;
	}

	F1.close();
	F2.close();
	return 0;
}
