#include "ball.h"

Ball::Ball()
{

}


void Ball::tick(){
    x += dx;
    y += dy;

}

void Ball::render(){

}

Rect Ball::getBoundingBox(){
    Rect out = {x-.5,y-.5,x+.5,y+.5};
    return out;
}

void Border::getBoundingBox(){
    Rect out = {0,0,x,y};
    return out;
}

void Border::render(){
    box(stdscr,0,0);
}

void Border::tick(){

}
