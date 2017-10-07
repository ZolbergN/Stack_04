#include <iostream>
#include "Stack.hpp"

using namespace std;

void init_ex() {
	cout << endl << "INIT" << endl;

	Stack<int> Int_arr;
	Stack<char> Char_arr;

	cout << "RESULT " << "IntArr & CharArr" << endl << endl;
}

int main() {
init_ex();
return 0;
}
