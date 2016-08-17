#include <iostream>

/*
 * C++ 类
 * 成员数据：
 *   static
 *   nonstatic
 * 成员函数：
 *   static
 *   nonstatic
 *   virtual
 * */

using namespace std;

class Class {
	public:
		// 静态成员函数中的无this指针
		static int* printAddr() {
			return &m_cnt;
		}
	private:
		static int m_cnt;
};

int Class::m_cnt = 0;

struct Struct{
	int a;
	static int b;
};

int main() {
	Class c1, c2;
	cout << "Class::&m_cnt::" << Class::printAddr() << ", &c1.m_cnt: " << c1.printAddr() << ", &c2.m_cnt: " << c2.printAddr() << endl; 
	
	cout << "sizeof(Struct): " << sizeof(Struct) << endl;

	return 0;
}
