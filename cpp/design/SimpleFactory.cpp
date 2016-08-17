#include <iostream>

using namespace std;

/*
 * 不符合开闭原则，不是23种标准的设计模式
 * */

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
		Fruit* create(char* p) {
			if (strcmp(p, "banana")) {
				return new Banana;	
			} else if (strcmp(p, "apple")) {
				return new Apple;	
			} else {
				return NULL;	
			}	
		}
};

int main() {
	Factory* fac = new Factory;

	Fruit* banana = fac->create("banana");
	banana->sayName();
	delete banana;

	Fruit* apple = fac->create("apple");
	apple->sayName();
	delete apple;

	delete fac;

	return 0;
}
