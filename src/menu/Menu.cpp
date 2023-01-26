#include <memory>
#include <algorithm>
#include <iterator>
#include <ncurses.h>
#include "include/Menu.hpp"

Menu::Menu(std::string& message, std::vector<std::string>& options) : message(message), options(options) {
    initscr();
    noecho();
    curs_set(0);
    start_color();
}

void Menu::prompt() {
    mvprintw(0,0,message.c_str());
    for(auto&& [i,value]:enumrate(options)) {
        mvprintw(i+1,2,value.c_str());
    }
    int cursor = 1;
    init_pair(1, COLOR_CYAN, COLOR_BLACK);
    while(true) {
        attron(COLOR_PAIR(1));
        mvprintw(cursor,1,">");
        attroff(COLOR_PAIR(1));
        int ch = getch();
        if(ch=='s' && cursor < 5) {
            mvprintw(cursor,1," ");
            cursor+=1;
        }
        if(ch=='w' && cursor > 1) {
            mvprintw(cursor,1," ");
            cursor-=1;
        }
        if(ch=='q' || (cursor==5&&ch==10)) {
            goto QUIT;
        }
    }
    QUIT:
    endwin();
}