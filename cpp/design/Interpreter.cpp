#include <iostream>

using namespace std;

/*
 * 解释器模式
 * */
class Context {
    public:
        Context(int num) {
            this->num = num;
        }
        void setNum(int num) {
            this->num = num;
        }
        int getNum() {
            return num;
        }
        void setRes(int res) {
            this->res = res;
        }
        int getRes() {
            return res;
        }
    private:
        int num;
        int res;
};

class Expression {
    public:
        virtual ~Expression() {}
        virtual void interpreter(Context* context) = 0;
    private:
        Context* context;
};

class PlusExpression: public Expression {
    public:
        virtual void interpreter(Context* context) {
            int num = context->getNum();  
            num++;
            context->setNum(num);
            context->setRes(num);
        }
};

class MinusExpression: public Expression {
    public:
        virtual void interpreter(Context* context) {
            int num = context->getNum();  
            num--;
            context->setNum(num);
            context->setRes(num);
        }
};

int main() {
    Expression *ex = NULL;
    Context* ct = NULL;

    ct = new Context(10);
    cout << ct->getNum() << endl;

    ex = new PlusExpression();
    ex->interpreter(ct);
    cout << ct->getNum() << endl;
    cout << ct->getRes() << endl;
    delete ex;

    ex = new MinusExpression();
    ex->interpreter(ct);
    cout << ct->getNum() << endl;
    cout << ct->getRes() << endl;
    delete ex;
    delete ct;

    return 0;
}
