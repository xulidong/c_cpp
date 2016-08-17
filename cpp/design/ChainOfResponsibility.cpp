#include <iostream>

using namespace std;

/*
 * 责任链模式
 * 很多对象由每一个对象对其下家的引用而连接起来形成一条链。
 * 请求在这个链上传递，直到链上的某一个对象决定处理此请求。
 * 发出这个请求的客户端并不知道链上的哪一个对象最终处理这个请求，
 * 这使得系统可以在不影响客户端的情况下动态地重新组织和分配责任。
 * */

/*
 * 造完车之后需要把任务传递下去
 * */
class CarHandle {
    public:
        CarHandle() {
            m_handle = NULL;
        }
        virtual ~CarHandle() {}
        virtual void handleRequset() = 0;
        virtual CarHandle* setNextHandle(CarHandle* handle){
            m_handle = handle;
            return m_handle;
        }
    protected:
        CarHandle* m_handle;// 下一个处理逻辑
};

class EngineCarHandle: public CarHandle {
    public:
        virtual void handleRequset() {
            cout << "engine" << endl;
            if (m_handle != NULL) {
                m_handle ->handleRequset();
            }
        }
};

class BodyCarHandle: public CarHandle {
    public:
        virtual void handleRequset(){
            cout << "body" << endl;
            if (m_handle != NULL) {
                m_handle ->handleRequset();
            }
        }
};

class TireCarHandle: public CarHandle {
    public:
        virtual void handleRequset(){
            cout << "tire" << endl;
            if (m_handle != NULL) {
                m_handle ->handleRequset();
            }
        }
};

int main() {
    CarHandle* engine = new EngineCarHandle;
    CarHandle* body = new BodyCarHandle;
    CarHandle* tire = new TireCarHandle;

    // 调用顺序写死
    engine->handleRequset();
    body->handleRequset();
    tire->handleRequset();

    cout << endl;

    // 可以设置执行顺序
    engine->setNextHandle(body);
    body->setNextHandle(tire);
    tire->setNextHandle(NULL);

    engine->handleRequset();

    delete tire;
    delete body;
    delete engine;
    
    return 0;
}
