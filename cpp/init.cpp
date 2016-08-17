#include <iostream>

/*
 * 类没有定义会自动提供默认的构造函数：无参构造函数，拷贝构造函数
 * 如果定义有参构造函数之后，编译器不再提供无参构造函数
 * */
using namespace std;

class Test {
	public:
		Test() {
			m_num = 10;
			m_p = (char *)malloc(100); 
			strcpy(m_p, "hello world.");
			cout << "无参构造函数" << endl;
		}
		Test(int num) {
			m_num = num;
			m_p = (char *)malloc(100); 
			strcpy(m_p, "hello world.");
			cout << "有参构造函数" << endl;
		}
		// 用1个对象去初始化另一个对象
		// 拷贝构造函数的固定形式：类名(const 类名& 参数名)
		Test(const Test& t) {
			m_num = t.m_num;
			m_p = (char *)malloc(100); 
			strcpy(m_p, t.m_p);
			cout << "拷贝构造函数" << endl;
		}
		~Test() {
			if (m_p != NULL) {
				free(m_p);	
				m_p = NULL;
			}
			cout << "析勾函数" << endl;
		}
		void print() {
			cout << m_num << endl;
			cout << m_p << endl;
		}
	private:
		int m_num;
		char *m_p;
};

void func() {
	Test t1, t2(20), t3 = (100);
	t1.print();
	t2.print();
	t3.print();
	Test t4(t3);
	t4.print();
	Test t5 = (100, 200, 300);// 相当于t5 = (300)，因为(100, 200, 300)是一个逗号表达式，返回300
	t5.print();
	Test t6 = Test(800);
	t6.print();
}

int main() {
	func();
	return 0;
}
