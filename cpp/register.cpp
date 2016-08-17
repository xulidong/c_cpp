#include <iostream>

using namespace std;

int main() {
	//  C++ 中寄存器变量可以取地址
	register int i = 0;
	cout << &i << endl;
	return 0;
}
