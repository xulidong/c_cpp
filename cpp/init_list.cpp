#include <iostream>

using namespace std;

class A{
	public:
		A(int _a) {
			m_a  = _a;
			cout << "A:" << m_a << endl;
		}
		~A(){
			cout << "~A:" << m_a << endl;
		}
	private:
		int m_a;
};

class B {
	public:
		B(int _b1, int _b2): m_a1(0), m_a2(0), m_c(0) {
			m_b1 = _b1;
			m_b2 = _b2;
			cout << "B:" << m_b1 << ", " << m_b2 << endl;
		}
		B(int _b1, int _b2, int _a1, int _a2): m_a1(_a1), m_a2(_a2), m_c(0) {
			m_b1 = _b1;
			m_b2 = _b2;
			cout << "B:" << m_b1 << ", " << m_b2 << endl;
		}
		// 拷贝构造函数也可以有参数初始化列表
		B(const B &b): m_a1(0), m_a2(0), m_c(0) {
			m_b1 = b.m_b1;
			m_b2 = b.m_b2;
		}
		~B(){
			cout << "~B:" << m_b1 << ", " << m_b2 << endl;
		}
	private:
		int m_b1;
		int m_b2;
		A m_a1;
		A m_a2;
		const int m_c;// const变量必须使用参数初始化列表初始化
};

void fun() {	
	// A a(10);
	// B b1(1, 2);
	B b2(1, 2, 3, 4);
}

int main() {
	fun();	
	return 0;
}
