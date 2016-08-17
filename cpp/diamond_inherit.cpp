#include <iostream>

using namespace std;

class Base {
	public:
		int b;
};

class Base1:virtual public Base {
	public:
		int b1;
};

class Base2:virtual public Base {
	public:
		int b2;
};

class Derive: public Base1, public Base2 {
	public:
		int d;
};

int main() {
	Derive derive;
	derive.b = 0;
	derive.b1 = 0;
	derive.b2 = 0;
	derive.d = 0;
	
	return 0;
}
