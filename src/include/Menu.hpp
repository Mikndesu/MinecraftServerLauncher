#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <map>
#include <ncurses.h>
#include "include/OptionsEnum.hpp"

template <typename E> 
class Menu {
private:
    std::string const message;
    std::vector<std::string> options;
    inline std::vector<std::tuple<int, std::string>> enumrate(std::vector<std::string> vec) {
        int i = 0;
        std::vector<std::tuple<int, std::string>> enumrate = {};
        for(const auto& element:vec) {
            enumrate.push_back(std::make_tuple(i, element));
            i++;
        }
        return enumrate;
    }
public:
    Menu(std::string& message, std::vector<std::string>& options) : message(message), options(options) {
        initscr();
        noecho();
        curs_set(0);
        start_color();
    }
    Menu& prompt() {
        mvprintw(0,0,message.c_str());
        for(auto&& [i,value]:enumrate(options)) {
            mvprintw(i+1,2,value.c_str());
        }
        return *this;
    }
    template <typename Func>
    E start(Func func) {
        return func();
    }

};