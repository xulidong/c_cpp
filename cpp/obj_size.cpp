#include <iostream>

using namespace std;

class Parent {
	public:
		Parent(){
		}
		virtual void print() {
			cout << "Parent" << endl;
		}
};

class Child: public Parent {
	public:
		Child(int b) {
			this->b = b;
		}
		virtual void print() {
			cout << "Child" << endl;
		}
	private:
 		int b;
};

int main() {
	Child arr[] = {Child(1), Child(2), Child(3)};
	Parent* pp = arr;
	Child* pc = arr;
	cout << sizeof(Parent) << " " << sizeof(Child) << " " << sizeof(pp) << " " << sizeof(pc) << endl;

	cout << pp << " " << pc << endl;
		
	pp->print();
	pc->print();
	
	// 当父类大小和子类一样时，执行成功
	pp++;
	pc++;
	cout << pp << " " << pc << endl;
	pp->print();
	pc->print();

	// 定义成员变量之后，父类和子类的大小不同
	// ++操作之后，父类指向的位置不是一个子类对象的起点，所以用它来调用函数会报错
	pp++;
	pc++;
	cout << pp << " " << pc << endl;
	pp->print();
	pc->print();

	return 0;
}
