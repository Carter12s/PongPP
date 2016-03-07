#ifndef BALL_H
#define BALL_H

#include "collisionobject.h"

class Ball : public CollisionObject
{
private:
    double x,y;     //Theoretical position of ball within scene
    double dx,dy;   //Ball velocity ratios
    double speed;   //Fundamental velocity

public:
    Ball();
    //Overloads of base virtual functions
    Rect getBoundingBox();
    void render();
    void tick();
};

class Paddle : public CollisionObject
{
private:
    double x,y;     //Theoretical paddle position
    double dy;      //Distance moved per key press

public:
    Paddle();
    //Overloads of base virtual functions
    Rect getBoundingBox();
    void render();
    void tick();
};

class Border : public CollisionObject
{
private:
    int x,y; //Dimensions of interrior space

public:
    Rect getBoundingBox();
    void render();
    void tick();
};

#endif // BALL_H
