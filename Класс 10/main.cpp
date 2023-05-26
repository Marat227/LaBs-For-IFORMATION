#include "Pair.h"
#include "fileWork.h"
using namespace std;

int main() {
	const char filename[] = "name";
	int numberOfPairs = 0;
	int c;
	while (true) {
		system("cls");
		cout << "1. create file" << endl;
		cout << "2. print file" << endl;
		cout << "3. delete records from file under limit value" << endl;
		cout << "4. increase records with current value" << endl;
		cout << "5. add k elements on the current position" << endl;


		cout << "enter c: "; cin >> c;
		switch (c) {
		case 1:
			numberOfPairs = file_makeFile_userInput(filename);
			break;
		case 2:
			if (numberOfPairs > 0) file_print(filename);
			else { cout << "empty file" << endl; }
			break;
		case 3:
			double limitValue;
			cout << "limit value?: "; cin >> limitValue;
			numberOfPairs = file_deleteRecordsUnderValue(filename, limitValue);
			break;
		case 4:
			double currentValue;
			double additionalValue;
			cout << "current value?: "; cin >> currentValue;
			cout << "current value?: "; cin >> additionalValue;
			file_addRecordsWithValue(filename, currentValue, additionalValue);
			break;
		case 5:
			int k, pos;
			cout << "k? "; cin >> k;
			cout << "pos? "; cin >> pos;
			numberOfPairs = file_addNumberOfRecordsAfterPair(filename, pos, k);
			break;
		default:
			cout << numberOfPairs;
		}

		system("pause");
	}

	return 0;
}
