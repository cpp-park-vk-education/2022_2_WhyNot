#ifndef SERVER_SERVER_H
#define SERVER_SERVER_H

#include <list>
#include "lobby_players.h"
#include "room.h"

class Server {
    std::list<LobbyPlayer> players;
    std::list<Room> rooms;
public:
    Server() {}
};

#endif //SERVER_SERVER_H
