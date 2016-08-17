#include <iostream>

using namespace std;

class Base {
	public:
		Base() {
			b = 1;
		}
		void print() {
			cout << "base: " << b << endl;
		}
		
		virtual void show() {
			cout << "base: " << b << endl;
		}
	private:
		int b;
};

class Derive: public Base {
	public:
		Derive() {
			d = 2;
		}
		void print() {
			cout << "derive:" << d << endl;
		}
		
		virtual void show() {
			cout << "derive:" << d << endl;
		}
	private:
		int d;
};

int main() {
	Base b;
	Derive d;

	// 未声明为虚函数，子类对象付给基类指针（引用），调用的还是基类的函数
	Base* pd = &d;
	pd->print();

	Base &rd = d;
	rd.print();

	// 虚函数，子类对象付给基类指针（引用），子类调用的子类的函数，基类调用积累的函数
	pd->show();
	rd.show();

	return 0;
}
