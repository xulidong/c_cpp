#include <iostream>

using namespace std;

/*
 * 备忘录模式
 * 在不破坏封闭的前提下，捕获一个对象的内部状态，并在该对象之外保存这个状态
 * */

class Memento {
    public:
        Memento(string name, int age) {
            this->name = name;
            this->age = age;
        }
        string getName() {
            return name;
        }
        void setName(string name) {
            this->name = name;
        }
        int getAge() {
            return age;
        }
        void setAge(int age) {
            this->age = age;
        }
    private:
        string name;
        int age;
};

class Person{
    public:
        Person(string name, int age) {
            this->name = name;
            this->age = age;
        }
        void showInfo() {
            cout << "name:" << name << " ,age:" << age << endl;
        }
        string getName() {
            return name;
        }
        void setName(string name) {
            this->name = name;
        }
        int getAge() {
            return age;
        }
        void setAge(int age) {
            this->age = age;
        }
        Memento* createMemento() {
            return new Memento(name, age);
        }
        void setMemento(Memento* mem) {
           name = mem->getName();
           age = mem->getAge();
        }
    private:
        string name;
        int age;
};

class Caretaker{
    public:
        Caretaker(Memento* mem) {
            this->mem = mem;
        }
        Memento* getMemento() {
            return mem;
        }
        void setMemento(Memento* mem) {
            this->mem = mem;
        }
    private:
        Memento* mem;
};

int main() {
    Person* p = new Person("Jun", 25); 
    p->showInfo();

    Memento* mem = p->createMemento();
    Caretaker* care = new Caretaker(mem);

    p->setAge(18);
    p->showInfo();

    p->setMemento(care->getMemento());
    p->showInfo();

    delete care;
    delete mem;
    delete p;

    return 0;
}
