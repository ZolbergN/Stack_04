#include <iostream>
#include "Stack.hpp"

int main() {
	try {
		Stack<int> st(8);

		st.push(2);
		st.push(4);
		st.push(7);
		st.push(5);
		st.push(8);
		st.push(766);
		st.push(9);
		st.push(32);
	}
	catch (const exception& e) {
		cout << e.what() << endl;
	}
	
	return 0;
}
