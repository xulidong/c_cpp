#include <iostream>

using namespace std;

/*
 * 外观模式:将子系统中的一组接口提供一个一致的界面
 * 外观模式定义了一个高层接口，这个接口使得这一子系统更加容易使用
 * */

class SubsysA {
	public:
		void dothing() {
			cout << "SubsysA do thing" << endl;
		}
};

class SubsysB {
	public:
		void dothing() {
			cout << "SubsysB do thing" << endl;
		}
};

class SubsysC {
	public:
		void dothing() {
			cout << "SubsysC do thing" << endl;
		}
};

class Facade {
	public:
		Facade() {
			m_sysA = new SubsysA;
			m_sysB = new SubsysB;
			m_sysC = new SubsysC;
		}
		~Facade() {
			if (m_sysA != NULL) {
				delete m_sysA;
				m_sysA = NULL;
			}
			if (m_sysB != NULL) {
				delete m_sysB;
				m_sysB = NULL;
			}
			if (m_sysC != NULL) {
				delete m_sysC;
				m_sysC = NULL;
			}
		}
		void dothing() {
			m_sysA->dothing();
			m_sysB->dothing();
			m_sysC->dothing();
		}
	private:
		SubsysA* m_sysA;
		SubsysB* m_sysB;
		SubsysC* m_sysC;
};

int main() {
	// 使用外观模式之前
	SubsysA* a = new SubsysA;
	a->dothing();
	delete a;
	
	SubsysB* b = new SubsysB;
	b->dothing();
	delete b;
	
	SubsysC* c = new SubsysC;
	c->dothing();
	delete c;

	cout << endl;

	// 使用外观模式之前
	Facade* facade = new Facade;
	facade->dothing();
	delete facade;

	return 0;
}

