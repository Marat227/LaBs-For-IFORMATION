#pragma once
#include "Pair.h"
using namespace std;

int file_makeFile_userInput(const char* filename) {
	fstream outStream(filename, ios::out | ios::trunc);
	if (!outStream) return -1;

	int numberOfPairs;
	cout << "number of pairs?" << endl;
	cin >> numberOfPairs;
	Pair pair;
	for (int i = 0; i < numberOfPairs; i++) {
		cout << "--------" << endl;
		cin >> pair;
		cout << "--------" << endl;
		outStream << pair;
	}
	outStream.close();
	return numberOfPairs;
}

void file_print(const char* filename) {
	fstream inStream(filename, ios::in);
	if (!inStream) {
		cout << "ошибка чтения" << endl;
		return;
	}
	Pair pair;
	while (inStream >> pair) {
		cout << pair << '\n';
	}
	inStream.close();
}

int file_deleteRecordsUnderValue(const char* filename, int limitValue) {
	fstream fromStream(filename, ios::in);
	fstream inStream("tmpFile", ios::out | ios::trunc);

	int numberOfPairs = 0;
	Pair p;
	while (fromStream >> p) {
		if (p.getFirst() > limitValue && p.getSecond() > limitValue && !fromStream.eof()) {
			inStream << p;
			numberOfPairs++;
		}
	}
	fromStream.close();
	inStream.close();
	remove(filename);
	rename("tmpFile", filename);
	return numberOfPairs;
}

template <typename type, typename type1>
void file_addRecordsWithValue(const char* filename, type currentValue, type1 additionalValue) {
	fstream fromStream(filename, ios::in);
	fstream inStream("tmpFile", ios::out | ios::trunc);

	Pair p;
	while (fromStream >> p) {
		if ((p.getFirst() == currentValue || p.getSecond() == currentValue) && !fromStream.eof()) {
			p + additionalValue;
		}
		inStream << p;
	}
	fromStream.close();
	inStream.close();
	remove(filename);
	rename("tmpFile", filename);
}

int file_addNumberOfRecordsAfterPair(const char* filename, int pairPosition, int numberOfElements) {
	fstream fromStream(filename, ios::in);
	fstream inStream("tmpFile", ios::out | ios::trunc);

	int numberOfPairs = 0;
	Pair p;

	for (int i = 0; i < pairPosition - 1 && !fromStream.eof(); i++) {
		fromStream >> p;
		if (!fromStream.eof()) inStream << p;
		numberOfPairs++;
	}

	for (int i = 0; i < numberOfElements; i++) {
		cout << "--------" << endl;
		cin >> p;
		cout << "--------" << endl;
		inStream << p;
		numberOfPairs++;
	}
	while (!fromStream.eof() && fromStream >> p) {
		if (!fromStream.eof()) {
			inStream << p;
		}
		numberOfPairs++;
	}

	fromStream.close();
	inStream.close();
	remove(filename);
	rename("tmpFile", filename);
	return numberOfPairs;
}
