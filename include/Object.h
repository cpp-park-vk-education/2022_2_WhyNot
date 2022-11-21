#ifndef OBJECT_H
#define OBJECT_H

#include "Graph.h"
#include "Drawable.h"
#include "Object_type_id.h"

class Object {
private:
    enum class Object_type_id type;
    Graph function;
    Drawable* draw;
public:
    Object(enum class object_type_id);
};

#endif //OBJECT_H
