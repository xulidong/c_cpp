#include <iostream>

using namespace std;

/*
 * 电压适配器
 * 将220v适配到18v
 * */

class Cur18v {
    public:
        virtual void useCur18v() = 0;
};

class Cur220v {
    public:
        virtual void useCur220v() {
            cout << "220v" << endl;
        }   
};

class Adapter: public Cur18v {
    public:
        Adapter(Cur220v* cur) {
            this->cur = cur;
        }   
        virtual void useCur18v() {
           cur->useCur220v();
           cout << "couvert to 18v" << endl;
        }   
    private:
        Cur220v* cur;
};

int main() {
    Cur220v* cur220v = new Cur220v();
    Adapter* adapter = new Adapter(cur220v);
    adapter->useCur18v();
    delete adapter;
    delete cur220v;

    return 0;
}