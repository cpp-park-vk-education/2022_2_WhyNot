#ifndef OBJECT_H
#define OBJECT_H

#include "Graph.h"
#include "Drawable.h"
#include "Object_type_id.h"

class Object {
private:
    Object_type_id type;
    Graph function;
    Drawable* draw;
public:
    Object(const object_type_id&);
};

#endif //OBJECT_H
