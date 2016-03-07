#ifndef COLLISIONOBJECT_H
#define COLLISIONOBJECT_H
#include "object.h"

struct Rect {
    double x1,y1,x2,y2;
};

class CollisionObject : public Object
{
public:
    virtual Rect getBoundingBox()=0;
};

#endif // COLLISIONOBJECT_H
