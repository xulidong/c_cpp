#include <iostream>
#include <list>

using namespace std;

/*
 * 观察者模式
 * 一对多的关系
 * */
class Secretary;

class PlayerObserver {
    public:
        PlayerObserver(Secretary* secretary) {
            this->secretary = secretary;
        }
        void update(string action) {
            cout << "action: " << action  << endl; 
        }
    private:
        Secretary* secretary;
};

class Secretary {
    public:
        void notify(string info) {
            for (list<PlayerObserver*>::iterator it = playerList.begin(); it != playerList.end(); ++it) {
                (*it)->update(info); 
            } 
        } 
        void setPlayerObserver(PlayerObserver *player) {
            playerList.push_back(player); 
        }
    private:
        list<PlayerObserver*>playerList;
};

int main() {
    Secretary* sec = new Secretary;
    PlayerObserver* player1 = new PlayerObserver(sec);
    PlayerObserver* player2 = new PlayerObserver(sec);

    sec->setPlayerObserver(player1);
    sec->setPlayerObserver(player2);

    sec->notify("老板来了");
    sec->notify("老板走了");

    delete player2;
    delete player1;
    delete sec;

    return 0;
}
