#include <iostream>

using namespace std;

/*
 * 懒汉式：只有在getInstance时才会创建对象
 * 懒汉式的缺点是每次都需要判断
 * 懒汉式线程不安全，需要做线程同步 
 * static Singleton* getInstance() {
 *		// double check
 *		if (m_instance -- NULL) {
 *			cs.Lock();
 *			if (m_instance == NULL) {
 *				m_instance = new Singletion;
 *			}
 *			cs.Unlock();
 *		}	
 * }
 * */
/*
class Singleton {
	private:
		Singleton() {
			cout << "Singleton()" << endl;
		}

	public:
		~Singleton() {
			cout << "~Singleton()" << endl;
		}
		
		static Singleton* getInstance() {
			if (m_instance == NULL) {
				m_instance = new Singleton;
			}	
			return m_instance;
		}

		static void freeInstance() {
			if (m_instance != NULL) {
				delete m_instance;
				m_instance = NULL;
			}	
		}

private:
		static Singleton* m_instance;
};
*/

/*
 * 饿汉式：默认就会创建一个对象
 * 饿汉式的缺点是不会用不用得到都会创建一个对象
 * 饿汉式线程安全
 * */
class Singleton {
	private:
		Singleton() {
			cout << "Singleton()" << endl;
		}

	public:
		~Singleton() {
			cout << "~Singleton()" << endl;
		}
		
	public:
		static Singleton* getInstance() {
			return m_instance;
		}

		static void freeInstance() {
			if (m_instance != NULL) {
				delete m_instance;
				m_instance = NULL;
			}	
		}

	private:
		static Singleton* m_instance;
};

Singleton* Singleton::m_instance = new Singleton;

int main() {
	Singleton* p1 = Singleton::getInstance();
	Singleton* p2 = Singleton::getInstance();
	
	cout << p1 << endl;
	cout << p2 << endl;

	Singleton::freeInstance();

	return 0;
}
