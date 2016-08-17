#include <iostream>

using namespace std;

/*
 * 状态模式
 * */

class Worker;
class State;
class StateOne;
class StateTwo;

class Worker {
    public:
        Worker();
        ~Worker();
        void dothing();
        int getHour() {
            return hour;
        }
        void setHour(int hour) {
            this->hour = hour;
        }
        State* getCurState() {
            return state;
        }
        void setState(State* state) {
            this->state = state;
        }
    private:
        int hour;
        State* state;
};

class State {
    public:
        virtual ~State() {}
        virtual void dothing(Worker* worker) = 0;
};

class StateOne: public State {
    public:
        virtual void dothing(Worker* worker);
};

class StateTwo: public State {
    public:
        virtual void dothing(Worker* worker); 
};

void StateOne::dothing(Worker* worker) {
    int h = worker->getHour();
    if (h == 7 || h == 8) {
        cout << "eat" << endl; 
    } else {
        delete worker->getCurState();
        worker->setState(new StateTwo);
        worker->getCurState()->dothing(worker); 
    }
}

void StateTwo::dothing(Worker* worker) {
    int h = worker->getHour();
    if (h >= 9) {
        cout << "work" << endl; 
    } else {
        delete worker->getCurState();
        worker->setState(new StateTwo);
        worker->getCurState()->dothing(worker); 
    }
}

Worker::Worker() {
    state = new StateOne;
}

Worker::~Worker() {
    if (state != NULL){
        delete state;
        state = NULL;
    }
}

void Worker::dothing() {
    state->dothing(this);
}

int main() {
    Worker* w = new Worker;
    w->setHour(7);
    w->dothing();

    w->setHour(10);
    w->dothing();

    delete w;

    return 0;
}
