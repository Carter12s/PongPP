#ifndef BALL_H
#define BALL_H

#include "easylogging++.h"
#include "collisionobject.h"
#include "math.h"
#include "cmath"

struct Point{
    double x, y;
};

class Ball : public Object
{
public:
    double x,y;     //Theoretical position of ball within scene
    double dx,dy;   //Ball velocity ratios
    Ball(double x_in, double y_in, double dx_in, double dy_in);
    Point getXY();
    void reflect(double theta);
    //Overloads of base virtual functions
    void render();
    void tick();
};

class Paddle : public CollisionObject
{
private:
    double x,y;     //Theoretical paddle position
    double dy;      //Distance moved per key press

public:
    Paddle(double x_in, double y_in);
    void up();
    void down();
    //Overloads of base virtual functions
    Rect getBoundingBox();
    void collide(Ball& ball);
    void render();
    void tick();
};

enum class P_SCORE{none,P1,P2};

class Border : public CollisionObject
{
private:
    int x,y; //Dimensions of interrior space
    P_SCORE last_score = P_SCORE::none;
public:
    P_SCORE getScore();
    Rect getBoundingBox();
    void collide(Ball& ball);
    void render();
    void tick();
};

class Score : public Object
{
private:
    int x,y; //Draw Location
    unsigned int count;
public:
    Score(int x, int y);
    void score(){count++;}
    void render();
    void tick(){}
};

#endif // BALL_H
