﻿#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;

//Сортировка Хоара
void Hoar(int arr[], int first, int last)
{
    int mid, count;
    int f = first, l = last;
    mid = arr[(f + l) / 2];
    do
    {
        while (arr[f] < mid) f++;
        while (arr[l] > mid) l--;
        if (f <= l)
        {
            count = arr[f];
            arr[f] = arr[l];
            arr[l] = count;
            f++;
            l--;
        }
    } while (f < l);
    if (first < l) Hoar(arr, first, l);
    if (f < last) Hoar(arr, f, last);
}

//Сортировка Шелла
void Shell(int arr[], int n) {
    int d = n;
    d = d / 2;
    int temp = 0;
    while (d > 0) {
        for (int i = 0; i < n - d; i++) {
            int j = i;

            while (j >= 0 && arr[j] > arr[j + d]) {
                temp = arr[j];
                arr[j] = arr[j + d];
                arr[j + d] = temp;
                j--;
            }
        }
        d = d / 2;
    }
    for (int k = 0; k < n; k++) cout << arr[k] << ' '; //вывод массива 

}

int main() {
    srand(time(NULL));
    setlocale(LC_ALL, "RUS");
    int n;
    cout << "Сортировка Хоара" << endl;
    cout << "Введите количество элементов массива: "; cin >> n;
    int* arr = new int[n];
    cout << "Элементы массива: ";
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 50 - 20;
        cout << arr[i] << ' ';
    }
    cout << endl << "Отсортированный массив: ";
    Hoar(arr, 0, n - 1);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << ' ';
    }
    cout << endl << endl;
    delete[] arr;
    cout << "Сортировка Шелла" << endl;
    cout << "Введите количество элементов массива: "; cin >> n;
    int* arr1 = new int[n];
    cout << "Элементы массива: ";
    for (int i = 0; i < n; i++) {
        arr1[i] = rand() % 50 - 20;
        cout << arr1[i] << ' ';
    }
    cout << endl << "Отсортированный массив: ";
    Shell(arr1, n);
    cout << endl << endl;
    delete[] arr1;
}