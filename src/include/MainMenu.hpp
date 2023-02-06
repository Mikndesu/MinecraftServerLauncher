#pragma once
#include <ncurses.h>
#include <functional>
#include "include/OptionsEnum.hpp"

namespace MainMenu {
    auto mainPrompt = [](std::map<std::string, std::function<void>> map) {
        int cursor = 1;
        const auto LAST_CURSOR = map.size();
        constexpr auto FIRST_CURSOR = 1;
        init_pair(1, COLOR_CYAN, COLOR_BLACK);
        while (true) {
            attron(COLOR_PAIR(1));
            mvprintw(cursor, 1, ">");
            attroff(COLOR_PAIR(1));
            int ch = getch();
            if (ch == 's' && cursor < LAST_CURSOR) {
                mvprintw(cursor, 1, " ");
                cursor += 1;
            }
            if (ch == 'w' && cursor > FIRST_CURSOR) {
                mvprintw(cursor, 1, " ");
                cursor -= 1;
            }
            if (ch == 10 || ch == 13) {
                if (cursor == LAST_CURSOR) {
                    endwin();
                    std::exit(0);
                }
                mvprintw(10, 1, std::to_string(cursor).c_str());
            }
            if (ch == 'q') {
                endwin();
                std::exit(0);
            }
        }
        opt = Options::getEnumByValue(cursor);
    };
    auto select = [](std::vector<std::string>vec) {

    };
};