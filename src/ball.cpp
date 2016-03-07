#include "ball.h"

Ball::Ball(double x_in, double y_in, double dx_in, double dy_in)
{
    x=x_in;
    y=y_in;
    dx=dx_in;
    dy=dy_in;
}

void Ball::reflect(double theta){
    LOG(INFO) << "Reflect in dx,dy= " << dx << "," << dy;
    dx = dx-2*(dx*sin(theta)+dy*cos(theta))*sin(theta)*1.05;
    dy = dy-2*(dx*sin(theta)+dy*cos(theta))*cos(theta)*1.05;
    LOG(INFO) << "Reflect out dx,dy= " << dx << "," << dy;
}

void Ball::tick(){
//    LOG(INFO) << "Tick dy:" << dy << " y" << y;
//    LOG(INFO) << "Tock dx:" << dx << " x" << x;
    x += dx;
    y += dy;
}

Point Ball::getXY(){
    Point p = {x,y};
    return p;
}

void Ball::render(){
    mvprintw(y,x,"O");
}

Rect Border::getBoundingBox(){
    Rect out = {0.0,0.0,(double)x,(double)y};
    return out;
}

void Border::collide(Ball& ball){
    Point p = ball.getXY();
    if(p.y < 1){
        LOG(INFO) << "Top Collision";
        ball.reflect(0);
    }else if(p.y > LINES-1){
        LOG(INFO) << "Bottom Collision";
        ball.reflect(0);
    }
    if(p.x < 1){
        LOG(INFO) << "Lef Collision";
        this->last_score = P_SCORE::P2;
    }else if(p.x > COLS -1){
        LOG(INFO) << "Right Collision";
        this->last_score = P_SCORE::P1;
    }
}

void Border::render(){
    box(stdscr,0,0);
}

void Border::tick(){

}

P_SCORE Border::getScore(){
    if(last_score == P_SCORE::none){
        return P_SCORE::none;
    }else{
        LOG(INFO) << "Cleared last_score";
        P_SCORE temp = last_score;
        last_score = P_SCORE::none;
        return temp;
    }
}

Paddle::Paddle(double x_in, double y_in): dy(1){
    x=x_in;
    y=y_in;
}

void Paddle::up(){
    LOG(INFO) << "Paddle UP: " << y;
    y-=(y>2 ? dy : 0);
}

void Paddle::down(){
    LOG(INFO) << "Paddle Down: " << y;
    y+=(y<LINES-3 ? dy : 0);
}

Rect Paddle::getBoundingBox(){
    Rect out = {x-.25,y,x+.25,y+3};
    return out;
}

void Paddle::collide(Ball& ball){
    Point p = ball.getXY();
    if(p.x > this->x-.25 && p.x < this->x+.25){
        if(p.y > this->y && p.y < this->y+3){
            LOG(INFO)<<"Collision";
                ball.reflect(M_PI_2);
                ball.x += (x < COLS/2 ? .3 : -.3); //Internal Lock Prevention
        }
    }
}

void Paddle::render(){
    for(int i = -1; i < 2; i++){
        mvprintw(y+i,x,"|");
    }
}

void Paddle::tick(){

}

Score::Score(int x, int y){
    this->x = x;
    this->y = y;
    this->count =0;
}

void Score::render(){
    std::stringstream ss;
    ss << count;
    mvprintw(x,y,ss.str().c_str());
}

