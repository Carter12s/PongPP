#ifndef SCENEGRAPH_H
#define SCENEGRAPH_H

#include<vector>
#include<algorithm>
#include "object.h"
#include "collisionobject.h"


class SceneGraph
{
private:
    std::vector<Object *> objs;

public:
    SceneGraph();
    std::vector<Object *> getAllObjects();
    void addObject(Object * obj_in);
    void removeObject(Object * obj_in);
    std::vector<CollisionObject *> getCollisionObjects();
    void tick();
    void render();
};

#endif // SCENEGRAPH_H
