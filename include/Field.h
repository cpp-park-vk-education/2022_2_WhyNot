#ifndef FIELD_H
#define FIELD_H

#include "Player.h"
#include "Object.h"

class Field {
private:
    Player* players;
    Object* objects;
    unsigned width;
    unsigned height;
public:
    void Field(unsigned, unsigned);
    void Move(int);
};


#endif //FIELD_H
