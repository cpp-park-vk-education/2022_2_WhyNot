#ifndef SERVER_SERVER_H
#define SERVER_SERVER_H

#include <list>
#include "lobby_players.h"
#include "room.h"
/*#include "stdafx.h"*/
#pragma comment(lib, "ws2_32.lib")
#include "winsock2.h"
#include <iostream>
#pragma warning(disable: 4996)

void serverStart();


#endif //SERVER_SERVER_H
