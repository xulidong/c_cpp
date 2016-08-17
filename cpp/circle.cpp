#include <iostream>

#define PI 3.14

using namespace std;

int mainC() {
	double r = 0;
	scanf("%lf", &r);
	printf("周长：%lf, 面积：%lf\n", 2 * PI * r, PI * r * r);
	return 0;
}

class Circle {
	public:
		void setR(double r) {
			m_r = r;
		}
		double getR() {
			return m_r;
		}

		double getArea() {
			return PI * m_r * m_r;
		}

		double getLength() {
			return 2 * PI * m_r;
		}
	private:
		double m_r;
};

int main() {
	double r = 0.0;
	cin >> r;
	
	Circle circle;
	circle.setR(r);
	cout << "面积：" << circle.getArea() << endl;
	cout << "周长：" << circle.getLength() << endl;

	return 0;
}
