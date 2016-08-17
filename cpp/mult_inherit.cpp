#include <iostream>

using namespace std;

class Base1 {
	public:
		int b1;
};

class Base2 {
	public:
		int b2;
};

class Derive: public Base1, public Base2 {
	public:
		int d;
		void print() {
			cout << b1 << endl;
			cout << b2 << endl;
			cout << d << endl;
		}
};

int main() {
	Derive d;
	d.b1 = 1;
	d.b2 = 2;
	d.d = 3;
	d.print();

	return 0;
}
