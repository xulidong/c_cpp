#include <iostream>

/*
 * 符合开闭原则，添加新的产品不需要修改原有的代码，只需要添加新的代码
 * 添加一种新的水果只需要添加一个水果类，然后添加一种心的工厂即可
 * */

using namespace std;

class Fruit {
	public:
		virtual ~Fruit() {}
		virtual void sayName() = 0;
};

class Banana: public Fruit {
	public:
		virtual void sayName() {
			cout << "Banana" << endl;
		}
};

class Apple: public Fruit {
	public:
		virtual void sayName() {
			cout << "Apple" << endl;
		}
};

class Factory {
	public:
		virtual ~Factory() {}
		virtual Fruit* create() = 0;
};

class BananaFactory: public Factory {
	public:
		Fruit* create() {
			return new Banana;	
		} 
};

class AppleFactory: public Factory {
	public:
		Fruit* create() {
			return new Apple;	
		}
};

int main() {
	Factory* fac = NULL;
	Fruit* fruit = NULL;
	
	fac = new BananaFactory;
	fruit = fac->create();
	fruit->sayName();
	delete fruit;
	delete fac;

	fac = new AppleFactory;
	fruit = fac->create();
	fruit->sayName();
	delete fruit;
	delete fac;

	return 0;
}
