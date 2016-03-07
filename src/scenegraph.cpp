#include "scenegraph.h"

SceneGraph::SceneGraph(){

}

std::vector<Object *> SceneGraph::getAllObjects(){
    return objs;
}

void SceneGraph::addObject(Object * obj_in){
    objs.push_back(obj_in);
}

void SceneGraph::removeObject(Object * obj_in){
    objs.erase(std::remove(objs.begin(),objs.end(),obj_in),objs.end());
}

std::vector<CollisionObject *> SceneGraph::getCollisionObjects(){
    std::vector<CollisionObject *> objs_out;
    for(auto i : objs){
        if(CollisionObject * co = dynamic_cast<CollisionObject *>(i))
            objs_out.push_back(co);
    }
    return objs_out;
}

void SceneGraph::tick(){
    for(auto i : objs){
        i->tick();
    }
}

void SceneGraph::render(){
    for(auto i: objs){
        i->render();
    }
}
