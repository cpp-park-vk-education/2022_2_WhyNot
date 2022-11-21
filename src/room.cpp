#include "include/room.h"

void Room::updateNum(int num) {
    numPlayers = num;
}

void Room::updatePriv(bool pr) {
    priv = pr;
}

std::string Room::getName() {
    return name;
}

std::string Room::getIp() {
    return ip;
}

int Room::getCode() {
    return code;
}

bool Room::getPriv() {
    return priv;
}

int Room::getNum() {
    return numPlayers;
}
