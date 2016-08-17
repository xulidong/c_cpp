#include <iostream>
/*
 * 构造函数调用顺序：父类 成员变量 自己
 * 析勾函数调用顺序：自己 成员变量 父类
 * */
using namespace std;

class Item {
	public:
		Item(int i) {
			this->i = i;
			cout << "Item" << endl;
		}
		~Item() {
			cout << "~Item" << endl;	
		}
		int getI() {
			return i;
		}
	private:
		int i;
};

class Parent {
	public:
		Parent(int a, int b, int c) {
			this->a = a;
			this->b = b;
			this->c = c;
			cout << "Patent" << endl;
		}
		~Parent() {
			cout << "~patent" << endl;
		}
		void print(){
			cout << "a = " << a << endl;
			cout << "b = " << b << endl;
			cout << "c = " << c << endl;
		};
		int a;
	protected:
		int b;
	private:
		int c;
};

class Child: public Parent{
	public:
		Child(int a, int b, int c, int d): Parent(a, b, c), item(0){
			this->d = d;
			cout << "Child" << endl;	
		}
		~Child() {
			cout << "~Child" << endl;
		}
		void print(){
			Parent::print();	
			cout << "d = " << d << endl;
			cout << "i = " << item.getI() << endl;
		};
	private:
		int d;
		Item item;
};

int main() {
	Child c(1, 2, 3, 4);
	c.print();
	return 0;
}
