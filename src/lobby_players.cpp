#include "../include/lobby_players.h"

int LobbyPlayer::getId() {
    return id;
}

std::string LobbyPlayer::getName() {
    return name;
}

Room LobbyPlayer::getRoom() {
    return room;
}
