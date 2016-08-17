#include <iostream>
#include <list>

using namespace std;

/*
 * 命令模式
 * 一个对象调用另一个对象的一般过程：
 * 1 创建目标对象的实例
 * 2 设置调用参数
 * 3 调用目标对象的方法
 * 但在有时候我们需要对这种调用过程用类Command加以封装
 * 降低两个对象之间的耦合度
 * */

class Doctor{
    public:
        void diagnoseEye() {
           cout << "diagnose eye" << endl; 
        } 
        void diagnoseNose() {
           cout << "diagnose nose" << endl; 
        } 
};

class Command {
    public:
        virtual ~Command() {}
        virtual void diagnose() = 0;
};

class CommandEye: public Command {
    public:
        CommandEye(Doctor* doc) {
            m_doc = doc;
        }
        virtual void diagnose() {
            m_doc->diagnoseEye();
        }
    public:
        Doctor* m_doc;
};

class CommandNose: public Command {
    public:
        CommandNose(Doctor* doc) {
            m_doc = doc;
        }
        virtual void diagnose() {
            m_doc->diagnoseNose();
        }
    public:
        Doctor* m_doc;
};

class Nurse {
    public:
        Nurse(Command* cmd) {
            m_cmd = cmd;
        }
        void submitCmd() {
            m_cmd->diagnose();
        }
    private:
        Command* m_cmd;
};

class HeadNurse {
    public:
        HeadNurse() {
            m_list.clear();
        }
        void submitCmd() {
           for (list<Command*>::iterator it = m_list.begin(); it != m_list.end(); ++it) {
                (*it)->diagnose();
           } 
        }
        void setCmd(Command* cmd) {
            m_list.push_back(cmd);
        }
    private:
        list<Command*> m_list;
};

int main() {
    Doctor* doc = new Doctor;
    CommandEye* cmdEye = new CommandEye(doc);
    CommandNose* cmdNose = new CommandNose(doc);
    cmdEye->diagnose();
    cmdNose->diagnose();

    cout << endl;

    Nurse* nurse = new Nurse(cmdEye);
    nurse->submitCmd();

    cout << endl;

    HeadNurse* headNurse = new HeadNurse;
    headNurse->setCmd(cmdEye);
    headNurse->setCmd(cmdNose);
    headNurse->submitCmd();

    delete headNurse;
    delete nurse;
    delete cmdEye;
    delete cmdNose;
    delete doc;
    
    return 0;
}
