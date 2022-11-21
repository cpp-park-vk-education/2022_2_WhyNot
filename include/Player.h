#ifndef PLAYER_H
#define PLAYER_H

#include "Undestroyable.h"
#include "Graph.h"

class Player : public Undestroyable {
private:
    std::string name;
    Graph function;
public:
    Player(std::string);
    void MakeMove();
};


#endif //PLAYER_H
