#include <iostream>

using namespace std;

class Parent {
	public:
		Parent(int a){
			this->a = a;
		}
		// vptr：8
		virtual void print() {
			cout << "Parent" << endl;
		}
	private:
		int a;
};

class Child : public Parent {
	public:
		Child(int b): Parent(0) {
			this->b = b;
		}
		// vptr：8
		virtual void print() {
			cout << "Child" << endl;
		}
	private:
		// int：4
 		int b;
		// 字节对齐：4
};

int main() {
	Parent p(0);
	Child c(0);
	
	cout << sizeof(p) << endl;
	cout << sizeof(c) << endl;

	return 0;
}
