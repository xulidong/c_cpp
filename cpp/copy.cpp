#include <iostream>

using namespace std;

class Name {
	public:
		Name(const char* p) {
			m_len = strlen(p) + 1;
			m_p = (char *)malloc(strlen(p) + 1);	
			strcpy(m_p, p);
		}
		// 默认构造函数执行的是浅拷贝
		Name(const Name &n) {
			m_len = n.m_len;
			m_p = (char *)malloc(m_len);
			strcpy(m_p, n.m_p);
		} 

		~Name() {
			if (m_p != NULL) {
				free(m_p);
				m_p = NULL;
				m_len = 0;
			}
		}
		// 返回引用支持连等
		Name& operator=(Name& n) {
			// 先释放旧的内存
			if (m_p != NULL) {
				free(m_p);
				m_p = NULL;
			}
			m_len = n.m_len;
			m_p = (char *)malloc(m_len);
			strcpy(m_p, n.m_p);
			return *this;
		}
	private:
		char* m_p;
		int m_len;
};

void fun() {
	Name obj1("abc");
	Name obj2(obj1);
	Name obj3 = obj2;// 默认的赋值操作浅拷贝，要实现深拷贝需重载赋值操作符
}

int main() {
	fun();
	return 0;
}
