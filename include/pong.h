#ifndef PONG_H
#define PONG_H

#include"easylogging++.h"
#include"scenegraph.h"
#include"ball.h"
#include<unistd.h>

class Pong
{
private:
    SceneGraph sg;
    Ball ball;
    Border border;
    Paddle p1, p2;
    Score s1, s2;

public:
    Pong();
};

#endif // PONG_H
