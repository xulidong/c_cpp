#include <iostream>

using namespace std;

/*
 * 原型模式：让对象拥有自我复制的功能
 * 注意深拷贝和浅拷贝
 * */

class Programmer{
	public:
		virtual ~Programmer() {}
		virtual Programmer* clone() = 0;
		virtual void print() = 0;

};

class CProgrammer: public Programmer {
	public:
		CProgrammer() {
			m_name = "";
			m_age = 0;
			m_des = NULL;
		}
		CProgrammer(string name, int age, char* des) {
			m_name = name;
			m_age = age;
			m_des = new char[strlen(des) + 1];
			strcpy(m_des, des);
		}
		~CProgrammer() {
			if (m_des != NULL) {
				delete[] m_des;
				m_des = NULL;
			}
		}
		virtual Programmer* clone() {
			CProgrammer* tmp = new CProgrammer;
			// *tmp = *this;// 对象默认的赋值操作符，浅拷贝
			tmp->m_name = this->m_name;
			tmp->m_age = this->m_age;
			// 实现深拷贝
			tmp->m_des = new char[strlen(this->m_des) + 1];
			strcpy(tmp->m_des, this->m_des);
			return tmp;
		}

		virtual void print() {
			cout << m_name << endl;
			cout << m_age << endl;
			cout << m_des << endl;
		}
	private:
		string m_name;
		int m_age;
		char* m_des;
};

int main() {
	Programmer* p = new CProgrammer("Jun", 26, "C Programmer");
	p->print();

	Programmer* p2 = p->clone();
	p2->print();

	delete p;
	delete p2;

	return 0;
}
