#include <iostream>

using namespace std;

class Class {
	public:
		// const 修饰的是this指针(const Class *const this)，因为this是匿名的，没有地方写，所以写在这个位置
		// this默认就是Class *const this
		void fun(int a) const {
			a = 100;
			this->m_a = a;	
		}
		int const getA() {
			return m_a;
		}
	private:
		int m_a;
};

int main() {
	Class c;
	return 0;
}
