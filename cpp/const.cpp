#include <iostream>

using namespace std;

int main() {
	const int a = 10;
	// 在C语言中 对const常量取地址返回常量的地址
	// 在C＋＋中 对const常量去地址，会另外在分配一块内存空间
	int *p = (int *)&a;
	*p = 20;
	cout << "a = " << a << endl;
	cout << "*p = " << *p << endl;
	return 0;
}
