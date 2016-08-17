#include <iostream>
#include <map>

using namespace std;

/*
 * 享元模式
 * 享元：共享元素
 * 以共享的方式来避免大量拥有相同内容对象的开销
 * 理解：
 * 对于经常使用且仅参数不同的对象，不是每次都重新创建一个不同的对象，
 * 而是创建一个对象之后，每次使用时传入不同的参数
 * */

class Person {
	public:
		Person(string name, int age) {
			m_name = name;
			m_age = age;
		}
		virtual ~Person() {}
		virtual void showInfo() = 0;
	protected:
		string m_name;
		int m_age;
};


class Teacher: public Person {
	public:
		Teacher(string id, string name, int age): Person(name, age) {
			m_id = id;
		}
		void showInfo() {
			cout << "name: " << m_name << endl;
			cout << "age: " << m_age << endl;
			cout << "id: " << m_id << endl;
		}

	private:
		string m_id;
};

class FlyweightFactory {
	public:
		FlyweightFactory() {
			m_map.clear();
		}
		~FlyweightFactory() {
			while(!m_map.empty()) {
				map<string, Person*>::iterator it = m_map.begin();
				Person* p = it->second;
				m_map.erase(it);
				delete p;
			}
		}
		Person* getTeachar(string id) {
			map<string, Person*>::iterator it = m_map.find(id);
			if (it == m_map.end()) {
				Teacher* tmp = new Teacher(id, "default", 0);
				m_map.insert(pair<string, Person*>(id, tmp));
				return tmp;
			}
			return it->second;
		}
	private:
		map<string, Person*>m_map;
};

int main() {
	FlyweightFactory* fac = new FlyweightFactory;
	Person* p1 = fac->getTeachar("001");
	p1->showInfo();
	Person* p2 = fac->getTeachar("001");
	p2->showInfo();

	delete fac;

	return 0;
}
