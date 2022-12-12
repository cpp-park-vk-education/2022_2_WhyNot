#ifndef SERVER_ROOM_H
#define SERVER_ROOM_H

#include <string>
#include <cstdlib>

class Room {
    std::string name;
    std::string ip;
    int port;
    int code;
    bool priv;
    int numPlayers;
public:
    Room(std::string new_name, std::string new_ip, int new_port) : name(new_name), ip(new_ip), port(new_port) {
        code = rand() % 20;
        priv = false;
        numPlayers = 8;
    }
    void updateNum(int num);
    void updatePriv(bool pr);
    std::string getName();
    std::string getIp();
    int getCode();
    bool getPriv();
    int getNum();
};

#endif //SERVER_ROOM_H
