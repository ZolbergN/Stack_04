#include <iostream>
#include "stack.hpp"

using namespace std;

void empty_ex() {
	try {
		cout << endl << "EMPTY" << endl;
		Stack<char> arr_;

		char cet[] = "RODROM";

		for (int i = 0; i < sizeof(cet); i++) { arr_.push(cet[i]); }

		cout << "RESULT ";
		while (!arr_.empty()) {
			cout << arr_.pop() << " ";
		}
		cout << endl << endl;
	}
	catch (const std::exception& e) {
		cout << e.what() << endl;
	}
}

int main() {
	empty_ex();
}
