#define ELPP_NO_DEFAULT_LOG_FILE
#define ELPP_STL_LOGGING

#include<iostream>
#include <easylogging++.h>
#include <ncurses.h>
#include <unistd.h>
#include <memory>

#include "ball.h"
#include "object.h"
#include "pong.h"

INITIALIZE_EASYLOGGINGPP

namespace pongpp{
    //Global Vars within pongpp
    short int maxx, maxy;
    WINDOW * master_win;

    WINDOW *create_newwin(int height, int width, int starty, int startx){
        WINDOW *local_win;
        local_win = newwin(height, width, starty, startx);
        box(local_win, 0 , 0);
        wrefresh(local_win);
        return local_win;
    }

    void splash(){
        if(master_win != nullptr){
            mvwprintw(master_win,4,5,"          oooooooooo                                  ");
            mvwprintw(master_win,5,5,"          888    888  ooooooo    ooooooo    oooooooo8");
            mvwprintw(master_win,6,5,"          888oooo88 888     888 888   888  888    88o ");
            mvwprintw(master_win,7,5,"          888       888     888 888   888   888oo888o ");
            mvwprintw(master_win,8,5,"         o888o        88ooo88  o888o o888o 888     888");
            mvwprintw(master_win,9,5,"                                            888ooo888");
            mvwprintw(master_win,11,5,"Contact author at CarterJSchultz@gmail.com");
            mvwprintw(master_win,14,maxx/4,"Player 1 your controls are 'a' and 'q'");
            mvwprintw(master_win,15,maxx/4,"Player 2 your controls are the arrows of the keyboard");
            mvwprintw(master_win,17,maxx/4,"Push ANY key to start, 'p' for pause and ESC to quit");
            wrefresh(master_win);
        }else{
            LOG(ERROR) << "master_win uninitialized for splash";
            return;
        }
    }

}

using namespace pongpp;
int main(){
    el::Configurations conf("../logging.conf");
    el::Loggers::reconfigureAllLoggers(conf);
    el::Loggers::addFlag(el::LoggingFlag::ColoredTerminalOutput);
    LOG(INFO) << "Starting NCURSES";
    initscr();
    noecho();
    keypad(stdscr,true);
    nodelay(stdscr,1);
    curs_set(FALSE);
    start_color();
    init_pair(1,COLOR_WHITE,COLOR_BLACK);
    init_pair(2,COLOR_RED,COLOR_BLACK);
    init_pair(3,COLOR_YELLOW,COLOR_BLACK);
    init_pair(4,COLOR_BLUE,COLOR_BLACK);
    init_pair(5,COLOR_MAGENTA,COLOR_BLACK);
    init_pair(6,COLOR_GREEN,COLOR_BLACK);
    getmaxyx(stdscr,maxy,maxx);
    master_win = pongpp::create_newwin(maxy,maxx,0,0);
    keypad(master_win,true);
    LOG(INFO) << "Created Window";
    splash();
    LOG(INFO) << "Splash Reached";
    wgetch(master_win);
    LOG(INFO) << "Hit Main Loop";
    bool run = true;
    short int y1=maxy/2;
    short int y2=y1;
    float bx=maxx/2, by=maxy/2;
    float bvx=0.1f, bvy=0.025f;
    Pong p;


//    nodelay(master_win,1); //Disalbe blocking on wgetch();
//    while(run){
//        int chr = wgetch(master_win);
//        //LOG(INFO) << "Got Chr: " << chr;
//        switch(chr){
//        case KEY_UP: y2--; break;
//        case KEY_DOWN: y2++; break;
//        case 'a': y1++; break;
//        case 'q': y1--; break;
//        case 'p': wgetch(master_win); break;
//        case 27: endwin(); run = false; break; // Esc

//        }

//        //Collisions for Ball
//        if(by > maxy -1 || by < 1){
//            bvy = -bvy;
//        }
//        if(bx > maxx -1){
//            if(by > y2 && by < y2+2){
//                bvx = -bvx;
//            }
//        }
//        if(bx < 1){
//            if(by>y1&&by<y1+2){
//                bvx = -bvx;
//            }
//        }
//        bx = bx + bvx;
//        by = by + bvy;



//        werase(master_win);

//        box(master_win,0,0);
//        LOG_IF(mvwprintw(master_win,by,bx,"O"),ERROR) << "Bad Ball Position Cast";

//        for(short int i=-1;i<2;i++){
//                        mvwprintw(master_win,y1+i,2,"|");
//                        mvwprintw(master_win,y2+i,maxx-3,"|");}

//        wrefresh(master_win);
//        usleep(10000);//100 Hz?
//    }
//    LOG(INFO) << "Exiting";

}

