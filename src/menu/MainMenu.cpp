#include "include/menu/MainMenu.hpp"

MainMenu::MainMenu(std::string& message, std::vector<std::string>& options)
    : super(message, options) {}

MainMenu& MainMenu::start() {
    int cursor = 1;
    const auto options = this->getOptions();
    const int LAST_CURSOR = options.size();
    constexpr auto FIRST_CURSOR = 1;
    init_pair(1, COLOR_CYAN, COLOR_BLACK);
    while (true) {
        this->initScreen();
        attron(COLOR_PAIR(1));
        mvprintw(cursor, 1, ">");
        attroff(COLOR_PAIR(1));
        mvprintw(10, 1, options.at(cursor - 1).c_str());
        int ch = getch();
        if(ch == 's') {
            if(cursor < LAST_CURSOR) {
                cursor += 1;
            } else if(cursor == LAST_CURSOR) {
                cursor = FIRST_CURSOR;
            }
        }
        if (ch == 'w') {
            if (cursor > FIRST_CURSOR) {
                cursor -= 1;
            } else if (cursor == FIRST_CURSOR) {
                cursor = LAST_CURSOR;
            }
        }
        if (ch == 10 || ch == 13) {
            if (cursor == LAST_CURSOR) {
                endwin();
                std::exit(0);
            }
        }
        if (ch == 'q') {
            endwin();
            std::exit(0);
        }
        refresh();
    }
    return *this;
}