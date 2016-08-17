#include <iostream>

using namespace std;

class A {
	public:
		A() {
			p = new char[20];
			strcpy(p, "A");
		}
		virtual ~A() {
			delete[] p;
			cout << "~A" << endl;
		}
	private:
		char* p;
};

class B: public A {
	public:
		B() {
			p = new char[20];
			strcpy(p, "B");
		}
		virtual ~B() {
			delete[] p;
			cout << "~B" << endl;
		}
	private:
		char* p;
};

class C: public B {
	public:
		C() {
			p = new char[20];
			strcpy(p, "C");
		}
		virtual ~C() {
			delete[] p;
			cout << "~C" << endl;
		}
	private:
		char* p;
};

void fun(A *base) {
	// 如果不是虚析勾函数，只会调用基类A的析勾函数:~A
	// 虚析勾函数，会调用基类A的析勾函数:~C, ~B, ~A
	delete base;
}

int main() {
	C *c = new C;
	fun(c);
	
	return 0;
}
