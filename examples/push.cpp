#include <iostream>
#include "Stack.hpp"

using namespace std;

void push_ex() {
	cout << endl << "PUSH" << endl;

	Stack<int> Int_arr;
	for (int i = 0; i < 8; i++) { Int_arr.push(i * 2); }

	cout << "RESULT ";

	for (size_t j = 0; j < Int_arr.count(); j++) { cout << Int_arr[j] << " "; }

	cout << endl << endl;
}

int main() {
	push_ex();
}
