#ifndef PLAYER_H
#define PLAYER_H

#include "Undestroyable.h"
#include "Graph.h"

class Player : public Undestroyable {
private:
    string name;
    Graph function;
public:
    Player(string);
    void MakeMove();
};


#endif //PLAYER_H
