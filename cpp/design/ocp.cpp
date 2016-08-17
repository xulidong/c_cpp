#include <iostream>

using namespace std;
/*
 * OCP（open-close principle）
 * 软件对扩展应用时开放的，而对修改应用时关闭的
 * 通俗的说就是拓展软件功能的时候不需要修改原有的代码，而只需要增加新的代码
 * */

class BaseBanker {
	public:
		virtual void dothing() = 0;
};

class SaveBanker : public BaseBanker {
	public:
		virtual void dothing() {
			cout << "save money" << endl;
		}
};

class MoveBanker : public BaseBanker {
	public:
		virtual void dothing() {
			cout << "move money" << endl;
		}
};

void howDo(BaseBanker* banker) {
	banker->dothing();
}

int main() {
	SaveBanker* sb = new SaveBanker;
	howDo(sb);
	MoveBanker* mb = new MoveBanker;
	howDo(mb);
	return 0;
}
