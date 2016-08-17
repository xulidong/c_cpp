#include <iostream>

using namespace std;

class Complex {
	public:
		Complex(double _a = 0, double _b = 0) {
			this->m_a = _a;
			this->m_b = _b;
		}

		// 友员函数重载
		friend Complex operator+(Complex &c1, Complex &c2);
		friend Complex& operator++(Complex &c);
		friend Complex operator++(Complex &c, int);
		friend ostream& operator<<(ostream &out, Complex &c);
		friend istream& operator>>(istream &in, Complex &c);

		// 成员函数重载
		Complex operator-(Complex &c) {
			return Complex(this->m_a - c.m_a, this->m_b - c.m_b);
		}
		// 一元运算符，默认前置运算符
		Complex& operator--() {
			this->m_a--;
			this->m_b--;
			return *this;
		}
		// 一元运算符，后置运算符，增减一个默认的int型参数
		Complex operator--(int) {
			Complex tmp(this->m_a, this->m_b);
			this->m_a--;
			this->m_b--;
			return tmp;
		}
	private:
		double m_a;
		double m_b;
};

Complex operator+ (Complex &c1, Complex &c2) {
	return Complex(c1.m_a + c2.m_a, c1.m_b + c2.m_b);
}

Complex& operator++(Complex &c) {
	c.m_a++;
	c.m_b++;
	return c;
}

Complex operator++(Complex &c, int) {
	Complex tmp(c.m_a, c.m_b);
	c.m_a++;
	c.m_b++;
	return tmp;
}

ostream& operator<<(ostream &out, Complex &c) {
	out << c.m_a << " + " << c.m_b << "i" << endl;
	return out;
}

istream& operator>>(istream &in, Complex &c) {
	in >> c.m_a >> c.m_b;
	return in;
}

int main() {
	Complex c1(1, 1), c2(-1, -1);
	Complex c3 = c1 + c2;
	Complex c4 = c1 - c2;
	++c1;
	--c2;
	c1++;
	c2--;
	Complex c;
	cin >> c;
	cout << c << endl;
	return 0;
}
