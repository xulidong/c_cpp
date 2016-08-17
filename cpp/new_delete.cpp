#include <iostream>

/*
 * 基础类型malloc的变量和数组可以用delete释放，new的基础类型变量和数组也可以用free释放，不规范写法
 * 对象malloc不会调用构造函数，free不会调用析勾函数
 * */

using namespace std;

class Class{
	public:
		Class(int _a) {
			m_a = _a;
		}
		~Class() {
		
		}
	private:
		int m_a;
};


int main() {
	int *pi1 = (int *)malloc(sizeof(int));
	free(pi1);

	int *pi2 = new int;
	delete pi2;

	int* a1 = (int *)malloc(sizeof(int) * 10);
	free(a1);

	int* a2 = new int[10];
	delete[] a2;

	// 不会调用构造函数和析勾函数
	Class* pc1 = (Class *)malloc(sizeof(Class));
	free(pc1);

	// 会调用构造函数和析勾函数
	Class* pc2 = new Class(10);
	delete pc2;
	
	return 0;
}
