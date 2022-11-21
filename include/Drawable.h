#ifndef DRAWABLE_H
#define DRAWABLE_H

#include <string>

class Drawable {
private:
    unsigned pos_x;
    unsigned pos_y;
    std::string color;
public:
    Drawable();
    Drawable(unsigned, unsigned);
};


#endif //DRAWABLE_H
