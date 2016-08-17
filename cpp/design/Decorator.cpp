#include <iostream>

using namespace std;

/*
 * 装饰模式：在不改变原类和使用继承的情况下，对类进行功能的增强
 * 对类a功能的增强
 * */

class Car {
	public:
		virtual ~Car() {}
		virtual void go() = 0;
};

class RunCar: public Car {
	public:
		virtual void go() {
			cout << "car can run" << endl;
		}
};

class FlyCar: public Car {
	public:
		FlyCar(Car* car) {
			m_car = car;
		}
		virtual void go() {
			m_car->go();
			fly();
		}
		void fly() {
			cout << "car can fly" << endl;
		}
	private:
		Car* m_car;
};

class SwimCar: public Car {
	public:
		SwimCar(Car* car) {
			m_car = car;
		}
		virtual void go() {
			m_car->go();
			swim();
		}
		void swim() {
			cout << "car can swim" << endl;
		}
	private:
		Car* m_car;
};

int main() {
	Car* run = NULL;
	run = new RunCar();
	run->go();	
	cout << endl;

	FlyCar* fly = new FlyCar(run);	
	run->go();
	cout << endl;

	SwimCar* swim = new SwimCar(fly);
	swim->go();
	cout << endl;

	delete swim;
	delete fly;
	delete run;

	return 0;
}
