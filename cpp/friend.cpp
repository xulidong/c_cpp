#include <iostream>

using namespace std;

/*
 * 1.java --->1.class（字节吗）==> 反射机制分析1.class，找到类对象，直接修改类的私有属性
 * 反射机制成为了一种标准，jdk，sun做成了标准，jdk的api函数中有体现
 * AOP
 * 1.cpp ==> 预编译 编译 链接 生成 gcc -E, gcc -s, gcc -o 1.ext 1.c
 * 反汇编很难，所以cpp开了一个后门，就是friend关键字
 * */

class Circle;

class Point {
	public:
		Point(int _x, int _y) {
			this->m_x = _x;
			this->m_y = _y;
		}
		// 友员函数的声明位置(public,protected,private)无关
		friend void resetPoint(Point* p);
		// 友员类
		friend class Circle;
	private:
		double m_x;
		double m_y;
};

void resetPoint(Point* p) {
	// 友员函数可以访问类的私有成员
	p->m_x = 0;
	p->m_y = 0;
}

class Circle {
	public:
		Circle(double _r): m_p(0, 0) {
			this->m_r = _r;
			// 友员类可以访问其私有成员
			this->m_p.m_x = 1;
			this->m_p.m_y = 1;
		}
	private:
		Point m_p;
		double m_r;
};

int main() {
	Point p(1, 1);
	resetPoint(&p);
	Circle(1.0);
	
	return 0;
}
