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

Menu::Option Menu::prompt() {
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
        if(ch=='s' && cursor < static_cast<int>(Menu::Option::QUIT)) {
            mvprintw(cursor,1," ");
            cursor+=1;
        }
        if(ch=='w' && cursor >static_cast<int>(Menu::Option::LAUNCH)) {
            mvprintw(cursor,1," ");
            cursor-=1;
        }
        if(ch == 10 || ch == 13) {
            if(cursor==static_cast<int>(Menu::Option::QUIT)) {
                endwin();
                std::exit(0);
            }
            mvprintw(10,1,std::to_string(cursor).c_str());
        }
        if(ch=='q') {
            endwin();
            std::exit(0);
        }
    }
    return Options::getEnumByValue(cursor);
}