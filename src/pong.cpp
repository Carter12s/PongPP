#include "pong.h"

Pong::Pong() : ball(4,5,0.04,0.03), p1(1,LINES/2), p2(COLS-2,LINES/2), s1(2,COLS/4),s2(2,3*COLS/4)
{

    sg.addObject(&ball);
    sg.addObject(&border);
    sg.addObject(&p1);
    sg.addObject(&p2);
    sg.addObject(&s1);
    sg.addObject(&s2);
    sg.render();
    refresh();

    bool run = true;
    while(run){
        int chr = getch();
        LOG_IF(chr != -1,INFO) << "Got Chr: " << chr;
        switch(chr){
        case KEY_UP: p2.up(); break;
        case KEY_DOWN: p2.down(); break;
        case 'a': p1.down(); break;
        case 'q': p1.up(); break;
        case 'p': getchar(); break;            // Blocking call for pause
        case 27: endwin(); run = false; break; // Esc
        }

        sg.tick();
        for(auto i: sg.getCollisionObjects()){
            i->collide(ball);
        }
        P_SCORE scr = border.getScore();
        if(scr!=P_SCORE::none){
            if(P_SCORE::P1 == scr){
                LOG(INFO) << "P1 Scored";
                s1.score();
                ball.x = COLS/2;
                ball.y = LINES/2;
                LOG(INFO) << "Set Ball: " << ball.x << ", " << ball.y;
                ball.dx = -1*fabs(ball.dx);
            }else{
                LOG(INFO) << "P2 Scored";
                s2.score();
                ball.x = COLS/2;
                ball.y = LINES/2;
                ball.dx = fabs(ball.dx);
            }
        }
        erase();
        sg.render();
        refresh();
        usleep(4000);
    }
}
