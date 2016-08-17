#include <iostream>

using namespace std;

struct Class {
	char name[8];// 8
	int age; // 4

	int &a;// 4 相当于一个指针
	char &b;// 4 相当于一个指针
};

int& getVal() {
	int val = 10;
	cout << "val = " << val << ", &val = " << &val << endl;
	// 返回栈变量，不能成为其他变量的初始值，如果是静态变量或者全局变量时可以的
	return val;
}

int main() {
	int a = 10;
	int &b = a;
	int &c = a;

	b = 100;
	 
	cout << "a = " << a << " , &a = " << &a << endl;
	cout << "b = " << b << " , &b = " << &b << endl;
	cout << "c = " << c << " , &c = " << &c << endl;
	cout << "size:" << sizeof(Class) << endl;

	int &d = getVal();
	d = 100;
	cout << "d = " << d << " , &d = " << &d << endl;

	int &e = getVal();
	e = 100;
	cout << "e = " << e << " , &e = " << &e << endl;

	return 0;
}
