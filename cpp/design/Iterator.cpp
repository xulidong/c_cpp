#include <iostream>

using namespace std;

/*
 * 迭代器模式
 * */

typedef int Object;
#define SIZE 5

class Iterator {
    public:
        virtual ~Iterator() {}
        virtual void first() = 0;
        virtual void next() = 0;
        virtual bool end() = 0;
        virtual Object curItem() = 0;
};

class Aggregate {
    public:
        virtual ~Aggregate() {}
        virtual Iterator* createIterator() = 0;
        virtual Object getItem(int index) = 0;
        virtual int getSize() = 0;
};

class ConcreteIterator: public Iterator {
    public:
        ConcreteIterator(Aggregate *ag) {
            this->ag = ag; 
            index = 0;
        }
        virtual void first() {
            index = 0; 
        }
        virtual void next() {
            if (index < ag->getSize()) {
                index++; 
            }
        }
        virtual bool end() {
            return (index == ag->getSize()); 
        }
        Object curItem() {
            return ag->getItem(index); 
        }
    private:
        int index;
        Aggregate* ag;
};

class ConcreteAggregate: public Aggregate {
    public:
        ConcreteAggregate() {
            for(int i = 0; i < SIZE; ++i) {
                object[i] = i + 1; 
            }
        }
        virtual Iterator* createIterator() {
            return new ConcreteIterator(this); 
        } 
        virtual Object getItem(int index) {
            return object[index]; 
        }
        virtual int getSize() {
            return SIZE; 
        }
    private:
        Object object[SIZE];
};

int main() {
    Aggregate* ag = new ConcreteAggregate;
    Iterator* it = ag->createIterator(); 
    for (;!(it->end()); it->next()) {
        cout << it->curItem() << endl;
    }
    delete ag;
    delete it;
    return 0;
}
