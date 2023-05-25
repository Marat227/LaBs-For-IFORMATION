#include <iostream>
#include "stack.h"
using namespace std;

Stack createAndFillStack(size_t);

int main() {
	size_t stackSize = 0;
	cout << "Enter the stack size: "; cin >> stackSize;
	cout << "Enter da elements: " << endl;
	Stack stack1 = createAndFillStack(stackSize);

	cout << "Enter the stack size: "; cin >> stackSize;
	cout << "Enter da elements: " << endl;
	Stack stack2 = createAndFillStack(stackSize);

	Stack stack3 = stack1 * stack2;

	cout << "Mult: " << endl;
	cout << stack3;

	return 0;
}

Stack createAndFillStack(size_t stackSize) {
	Stack stack;
	for (int i = 0; i < stackSize; i++) {
		cin >> stack;
	}
	return stack;
}
