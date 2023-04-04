#include "include/menu/Menu.hpp"

Menu::Menu(std::string& message, std::vector<std::string>& options)
    : message(message), options(options) {
    initscr();
    noecho();
    curs_set(0);
    start_color();
}

const std::vector<std::string>& Menu::getOptions() {
    return this->options;
}

void Menu::initScreen() {
    clear();
    mvprintw(0, 0, message.c_str());
    for (auto&& [i, value] : enumrate(options)) {
        mvprintw(i + 1, 2, value.c_str());
    }
}