#ifndef OBJECT_H
#define OBJECT_H

#include <ncurses.h>
#include <memory>

//Define fundamental scene graph object properties
class Object {
public:
    virtual void render()=0;
    virtual void tick()=0;
};

#endif // OBJECT_H
