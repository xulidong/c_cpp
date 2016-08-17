#include <iostream>

using namespace std;
/*
 * 策略模式
 * 策略模式定义了一系列的算法，并将每一个算法封装起来，而且使它们还可以相互替换。
 * 策略模式让算法独立于使用它的客户而独立变化。
 * */
class Strategy {
    public:
        virtual ~Strategy() {}
        virtual void crypt() = 0;
};

class AES: public Strategy {
    public:
        virtual void crypt() {
            cout << "AES crypt" << endl;
        }
};

class DES: public Strategy {
    public:
        virtual void crypt() {
            cout << "DES crypt" << endl;
        }
};

class Context {
    public:
        void setStrategy(Strategy* strategy) {
            m_strategy = strategy;
        }

        void operate() {
            m_strategy->crypt();
        }
    private:
        Strategy* m_strategy;
};

int main() {
    Strategy* des = new DES;
    des->crypt();

    cout << endl;

    Context* context = new Context;
    context->setStrategy(des);
    context->operate();

    delete context;
    delete des;

    return 0;
}
