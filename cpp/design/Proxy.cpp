#include <iostream>

using namespace std;

/*
 * 代理模式:为其他对象提供一种代理，并以控制对这个对象的访问
 * a类中b类，a类和b类中都实现协议类protocol
 * */

class Shop{
	public:
		virtual ~Shop() {}
		virtual void sell() = 0;
};

class BookShop: public Shop {
	public:
		virtual void sell() {
			cout << "sell book" << endl;
		}
};

class NetShop: public Shop {
	public:
		NetShop() {
			m_shop = new BookShop();
		}
		virtual ~NetShop() {
			if ( m_shop != NULL ) {
				delete m_shop;
				m_shop = NULL;
			} 
		}
		virtual void sell() {
			discount();
			m_shop->sell();
		}
		void discount() {
			cout << "discount" << endl;
		}
	private:
		Shop* m_shop;
};

int main() {
	NetShop* netShop = new NetShop;
	netShop->sell();
	delete netShop;
	return 0;
}
