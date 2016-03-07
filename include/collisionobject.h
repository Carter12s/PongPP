#ifndef COLLISIONOBJECT_H
#define COLLISIONOBJECT_H
#include "object.h"

class Ball;

struct Rect {
    double x1,y1,x2,y2;
};

class CollisionObject : public Object
{
public:
    virtual Rect getBoundingBox()=0;
    virtual void collide(Ball& ball)=0;
};

#endif // COLLISIONOBJECT_H
