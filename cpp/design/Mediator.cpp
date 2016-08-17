#include <iostream>

using namespace std;
/*
 * 中介者模式 
 * 定义一个中介对象来封装系列对象之间的交互
 * */

class Mediator;

class Person {
    public:
        Person(string name, int sex, int condition, Mediator* mediator) {
            this->name = name;
            this->sex = sex;
            this->condition = condition;
            this->mediator = mediator;
        }
        virtual ~Person() {}
        int getCondition() {
            return condition;
        }
        int getSex() {
            return sex;
        }
        string getName() {
            return name;
        }
        virtual void getParter(Person* p) = 0;
    protected:
        string name;
        int sex;
        int condition;
        Mediator* mediator;
};

class Mediator {
    public:
        void getParter() {
            if (man->getSex() == woman->getSex()) {
                cout << "I am not gay" << endl;  
                return;
            } 
            if (man->getCondition() == woman->getCondition()) {
                cout << man->getName() << "==" << woman->getName() << endl;
            } else {
                cout << man->getName() << "!=" << woman->getName() << endl;
            }
        } 
        void setMan(Person* man) {
            this->man = man; 
        }
        void setWoman(Person* woman) {
            this->woman = woman; 
        }
    private:
        Person* man;
        Person* woman;
};

class Woman: public Person {
    public:
        Woman(string name, int sex, int condition, Mediator* mediator): Person(name, sex, condition, mediator) {
        }
        int getCondition() {
            return condition;
        }
        virtual void getParter(Person* p) {
            mediator->setWoman(this);
            mediator->setMan(p);
            mediator->getParter();
        }
};

class Man: public Person {
    public:
        Man(string name, int sex, int condition, Mediator* mediator): Person(name, sex, condition, mediator) {
        }
        int getCondition() {
            return condition;
        }
        virtual void getParter(Person* p) {
            mediator->setMan(this);
            mediator->setWoman(p);
            mediator->getParter();
        }
};

int main() {
    Mediator* mediator = new Mediator;

    Person* woman1 = new Woman("woman1", 0, 5, mediator);   
    Person* woman2 = new Woman("woman2", 0, 5, mediator);   
    Person* man1 = new Man("man1", 1, 6, mediator);   
    Person* man2 = new Man("man2", 1, 5, mediator);   
    
    woman1->getParter(woman2);
    woman2->getParter(man1);
    woman2->getParter(man2);

    delete woman1;
    delete woman2;
    delete man1;
    delete man2;
    delete mediator;

    return 0; 
} 
