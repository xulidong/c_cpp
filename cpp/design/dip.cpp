#include <iostream>

/*
 * DIP（Dependency Inversion Principle）原则:
 * 要依赖于抽象，不要依赖具体
 * 要针对接口编程，不要针对实现编程
 * */

using namespace std;

/*
 * 如果一个类中定义了虚函数，析勾函数也要定义为虚函数 
 * */
class Cpu {
	public:
		virtual ~Cpu() {}
		virtual void work() = 0;
};

class Memory {
	public:
		virtual ~Memory() {}
		virtual void work() = 0;
};

class HandDisk {
	public:
		virtual ~HandDisk() {}
		virtual void work() = 0;
};

class IntelCpu : public Cpu{
	public:
		virtual ~IntelCpu() {}
		virtual void work() {
			cout << "Intel Cup work" << endl;
		}
};

class KingstonMemory: public Memory {
	public:
		virtual ~KingstonMemory() {}
		virtual void work() {
			cout << "Kingstion Memory work" << endl;
		}
};

class WDHandDisk: public HandDisk {
	public:
		virtual ~WDHandDisk() {}
		virtual void work() {
			cout << "WD HandDisk work" << endl; 
		} 
};


class Computer {
	public:
		Computer(Cpu* cpu, Memory* memory, HandDisk* handdisk) {
			m_cpu = cpu;
			m_memory = memory;
			m_handdisk = handdisk;
		}
		void work() {
			m_cpu->work();
			m_memory->work();
			m_handdisk->work();
		}
	private:
		Cpu* m_cpu;
		Memory* m_memory;
		HandDisk* m_handdisk;
};

int main() {
	Cpu* cpu = new IntelCpu;
	Memory* memory = new KingstonMemory;
	HandDisk* handdisk = new WDHandDisk;
	Computer* computer = new Computer(cpu, memory, handdisk);
	computer->work();	
	delete computer;
	//delete handdisk;
	//delete memory;
	//delete cpu;
	return 0;
}
