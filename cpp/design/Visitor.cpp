#include <iostream>
#include <list>

using namespace std;
/*
 * 访问者模式
 * 把数据结构和对数据结构的操作解耦合
 * */

class ParkElement;

class Visitor {
    public:
        virtual ~Visitor() {}
        virtual void visit(ParkElement* parkelement) = 0;
};

class ParkElement {
    public:
        virtual ~ParkElement() {}
        virtual void accept(Visitor* visitor) = 0;
        virtual string getName() = 0;
};

class ParkA: public ParkElement {
    public:
        virtual ~ParkA() {}
        virtual void accept(Visitor* visitor) {
            visitor->visit(this);
        }
        virtual string getName() {
            return "ParkA";
        }
};

class ParkB: public ParkElement {
    public:
        virtual ~ParkB() {}
        virtual void accept(Visitor* visitor) {
            visitor->visit(this);
        }
        virtual string getName() {
            return "ParkB";
        }
};

class Park: public ParkElement {
    public:
        Park() {
            parks.clear();
        }
        void setParkElement(ParkElement* pe) {
            parks.push_back(pe); 
        }
        string getName() {
            return "park";
        }
        virtual void accept(Visitor* visitor) {
            for (list<ParkElement*>::iterator it = parks.begin(); it != parks.end(); ++it) {
                visitor->visit(*it);
            }
        }
    private:
        list<ParkElement*> parks;
};

class VisitorA: public Visitor {
    public:
        virtual ~VisitorA() {}
        virtual void visit(ParkElement* parkelement) {
            cout << "visitorA : " << parkelement->getName() << endl;
        }
};

class VisitorB: public Visitor {
    public:
        virtual ~VisitorB() {}
        virtual void visit(ParkElement* parkelement) {
            cout << "visitorB : " << parkelement->getName() << endl;
        }
};

class VisitorManager: public Visitor {
    public:
        virtual void visit(ParkElement* park) {
            cout << "visitor Manager : " << park->getName();
            cout << endl;
        }
};

void test1() {
    Visitor* va = new VisitorA;
    Visitor* vb = new VisitorB;

    ParkElement* pa = new ParkA;
    ParkElement* pb = new ParkB;

    pa->accept(va);
    pb->accept(vb);

    delete pb;
    delete pa;
    delete vb;
    delete va;
}

void test2() {
    ParkElement* pa = new ParkA;
    ParkElement* pb = new ParkB;
    Park* p = new Park;
    p->setParkElement(pa);
    p->setParkElement(pb);

    Visitor* vm = new VisitorManager(); 
    p->accept(vm);

    delete pb;
    delete pa;
    delete vm;
}

int main() {
    test1();
    test2();

    return 0;
}
