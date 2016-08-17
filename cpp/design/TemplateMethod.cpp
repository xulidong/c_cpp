#include <iostream>

using namespace std;

/*
 * 模版方法模式
 * 将一组方法封装起来，隐藏实现细节，提供一个接口
 * */

class CarFactory {
    public:
        virtual ~CarFactory() {}
        virtual void produteEngine() = 0;
        virtual void produteBody() = 0;
        virtual void produteTire() = 0;

        void produte() {
           produteEngine();
           produteBody();
           produteTire();
        }
};

class CarFactoryJeep: public CarFactory {
    public:
        virtual void produteEngine() {
            cout << "produte engine jeep" << endl;
        }
        virtual void produteBody() {
            cout << "produte body jeep" << endl;
        }
        virtual void produteTire() {
            cout << "produte tire jeep" << endl;
        }
};

class CarFactoryBus: public CarFactory {
    public:
        virtual void produteEngine() {
            cout << "produte engine bus" << endl;
        }
        virtual void produteBody() {
            cout << "produte body bus" << endl;
        }
        virtual void produteTire() {
            cout << "produte tire bus" << endl;
        }
};

int main() {
    CarFactory* fac = new CarFactoryJeep;
    fac->produte();
    delete fac;

    fac = new CarFactoryBus;
    fac->produte();
    delete fac;

	return 0;
}
