#include <iostream>

using namespace std;

/*
 * 建造者模式
 * 对象的创建和对象的表示分离
 * */

class House {
	public:
		void setFloor(string floor) {
			m_floor = floor;
		}
		void setWall(string wall) {
			m_wall = wall;
		}
		void setDoor(string door) {
			m_door = door;
		}
		void show() {
			cout << m_floor << endl;
			cout << m_wall << endl;
			cout << m_door << endl;
		}
	private:
		string m_floor;
		string m_wall;
		string m_door;
};

class Builder {
	public:
		virtual ~Builder() {}
		virtual void makeFloor() = 0;
		virtual void makeWall() = 0;
		virtual void makeDoor() = 0;
		virtual House* getHouse() = 0;
};

class FlatBuilder: public Builder {
	public:
		FlatBuilder() {
			m_house = new House();
		}
		virtual ~FlatBuilder() {
			if (m_house != NULL) {
				delete m_house;
				m_house = NULL;
			}
		}
		void makeFloor() {
			m_house->setFloor("flat floor");
		}

		void makeWall() {
			m_house->setWall("flat wall");	
		}

		void makeDoor() {
			m_house->setDoor("flat door");	
		}

		House* getHouse() {
			return m_house;
		}
	private:
		House* m_house;
};

class VillaBuilder: public Builder {
	public:
		VillaBuilder() {
			m_house = new House();
		}
		virtual ~VillaBuilder() {
			if (m_house != NULL) {
				delete m_house;
				m_house = NULL;
			}
		}
		void makeFloor() {
			m_house->setFloor("villa floor");
		}

		void makeWall() {
			m_house->setWall("villa wall");	
		}

		void makeDoor() {
			m_house->setDoor("villa door");	
		}

		House* getHouse() {
			return m_house;
		}
	private:
		House* m_house;
};

class Director {
	public:
		Director(Builder* builder) {
			m_builder = builder;	
		}
		void construct() {
			m_builder->makeFloor();
			m_builder->makeWall();
			m_builder->makeDoor();
		}
	private:
		Builder* m_builder;
};

int main() {
	Director* director = NULL;
	Builder* builder = NULL;
	House* house = NULL;
	
	builder = new VillaBuilder;
	director = new Director(builder);
	director->construct();
	house = builder->getHouse();
	house->show();

	delete builder;
	delete director;

	builder = new FlatBuilder;
	director = new Director(builder);
	director->construct();
	house = builder->getHouse();
	house->show();

	delete builder;
	delete director;

	return 0;
}
