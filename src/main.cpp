#define ELPP_NO_DEFAULT_LOG_FILE
#define ELPP_STL_LOGGING

#include<iostream>
#include <easylogging++.h>
#include <ncurses.h>
#include <unistd.h>

INITIALIZE_EASYLOGGINGPP

WINDOW *create_newwin(int height, int width, int starty, int startx)
{	WINDOW *local_win;

    local_win = newwin(height, width, starty, startx);
    box(local_win, 0 , 0);
    wrefresh(local_win);
    return local_win;
}

int main(){
    el::Configurations conf("../logging.conf");
    el::Loggers::reconfigureAllLoggers(conf);
    el::Loggers::addFlag(el::LoggingFlag::ColoredTerminalOutput);
    LOG(INFO) << "Starting NCURSES";
    initscr();
    noecho();
    cbreak();
    curs_set(FALSE);
    start_color();
    init_pair(1,COLOR_WHITE,COLOR_BLACK);
    init_pair(2,COLOR_RED,COLOR_BLACK);
    init_pair(3,COLOR_YELLOW,COLOR_BLACK);
    init_pair(4,COLOR_BLUE,COLOR_BLACK);
    init_pair(5,COLOR_MAGENTA,COLOR_BLACK);
    init_pair(6,COLOR_GREEN,COLOR_BLACK);

    WINDOW * master_border = create_newwin(LINES,COLS,0,0);
    LOG(INFO) << "Created Window";
    sleep(3);
    LOG(INFO) << "Exiting";

}
