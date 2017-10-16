#include <iostream>
#include "Stack.hpp"

using namespace std;

void pop_ex() {
	try {
		cout << endl << "POP" << endl;
		Stack<double> Double_arr;
		for (int i = 0; i < 8; i++) { Double_arr.push(double(i)); }

		cout << "RESULT ";

	}
	catch (const std::exception& e) {
		cout << e.what() << endl;
	}
}

int main() {
	pop_ex();
}
