#ifndef SERVER_LOBBY_PLAYERS_H
#define SERVER_LOBBY_PLAYERS_H

#include <string.h>

class LobbyPlayer {
    int id;
    std::string name;
    Room room;
public:
    LobbyPlayer(std::string new_name, int new_id, Room new_room) : name(new_name), id(new_id), room(new_room) {}
    int getId();
    std::string getName();
    Room getRoom();
};

#endif //SERVER_LOBBY_PLAYERS_H
