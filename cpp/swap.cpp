#include <iostream>

using namespace std;

void swap1(int &a, int &b) {
	a ^= b;
	b ^= a;
	a ^= b;
}

void swap2(int &a, int &b) {
	a = a - b;
	b = a - b;
	a = a - b;
}

int main() {
	int x = 1;
	swap2(x, x);
	cout << "x = " << x << endl;
	int y = 2;
	int &a = y;
	int &b = y;
	a ^= b;
	cout << "a = " << a << ",b = " << b << endl;	
	y = 3;
	cout << "a = " << a << ",b = " << b << endl;

	return 0;
}
