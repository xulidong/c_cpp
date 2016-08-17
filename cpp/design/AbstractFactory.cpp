#include <iostream>

using namespace std;

class Fruit {
	public:
		virtual ~Fruit() {}
		virtual void sayName() = 0;
};

class LocalApple: public Fruit {
	public:
		virtual void sayName() {
			cout << "LocalApple" << endl;
		}
};

class LocalBanana: public Fruit {
	public:
		virtual void sayName() {
			cout << "LocalBanana" << endl;
		}
};

class ImportApple: public Fruit {
	public:
		virtual void sayName() {
			cout << "ImportApple" << endl;
		}
};

class ImportBanana: public Fruit {
	public:
		virtual void sayName() {
			cout << "ImportBanana" << endl;
		}
};

class Factory {
	public:
		virtual ~Factory() {}
		// 水果种类写死 不符合开闭原则
		virtual Fruit* createApple() = 0;
		virtual Fruit* createBanana() = 0;
};

class LocalFactory: public Factory {
	public:
		Fruit* createApple() {
			return new LocalApple;
		} 

		Fruit* createBanana() {
			return new LocalBanana;
		}
};

class ImportFactory: public Factory {
	public:
		Fruit* createApple() {
			return new ImportApple;
		} 

		Fruit* createBanana() {
			return new ImportBanana;
		}
};

int main() {
	Factory* fac = NULL;
	Fruit* apple = NULL;
	Fruit* banana = NULL;
	
	// 本地水果
	fac = new LocalFactory;
	apple = fac->createApple();
	apple->sayName();
	banana = fac->createBanana();	
	banana->sayName();
	delete apple;
	delete banana;
	delete fac;
	
	// 进口水果
	fac = new ImportFactory;
	apple = fac->createApple();
	apple->sayName();
	banana = fac->createBanana();	
	banana->sayName();
	delete apple;
	delete banana;
	delete fac;

	return 0;
}
