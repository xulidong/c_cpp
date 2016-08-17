#include <iostream>

using namespace std;

/*
 * 桥接模式
 * 解决类与类之间多对多的关系
 * */

class Engine {
	public:
		virtual ~Engine() {}
		virtual void install() = 0;
};

class EngineA: public Engine {
	public:
		virtual void install() {
			cout << "engine A is installed" << endl;
		}
};

class EngineB: public Engine {
	public:
		virtual void install() {
			cout << "engine B is installed" << endl;
		}
};

class Car {
	public:
		Car(Engine* engine) {
			this->m_engine = engine;	
		}
		virtual ~Car() {}
		virtual void installEngine() = 0;
	protected:
		Engine* m_engine;
};

class CarAD: public Car {
	public:
		CarAD(Engine* engine): Car(engine) {
		
		}
		virtual void installEngine() {
			cout << "CarAD: ";
			m_engine->install();
		} 
};

class CarBMW: public Car {
	public:
		CarBMW(Engine* engine): Car(engine) {
		
		}
		virtual void installEngine() {
			cout << "CarBMW: ";
			m_engine->install();
		} 
};

int main() {
	Engine* engine = NULL;
	Car* car = NULL;
	
	engine = new EngineA;
	car = new CarAD(engine);
	car->installEngine();

	delete car;
	delete engine;
	
	return 0;
}
