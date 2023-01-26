#include <memory>
#include <algorithm>
#include <iterator>
#include <ncurses.h>
#include "include/Menu.hpp"

Menu::Menu(std::string& message, std::vector<std::string>& options) : message(message), options(options) {
}

Menu &Menu::init() {
    std::cout << this->message << std::endl;
    for(auto& option:this->options) {
        option = "  " + option;
    }
    return *this;
}

void Menu::prompt() {
    std::string keyInput;
    int order = 0;
    // this->putVecToConsole(this->options, 0);
    for(auto& elm:this->options) {
        std::cout << elm << std::endl;
    }
    while(1) {
        std::cin >> keyInput;
        auto vec = std::make_unique<std::vector<std::string>>();
        std::copy(this->options.begin(), this->options.end(), std::back_inserter(*vec.get()));
        if(keyInput == "s" && order != static_cast<int>((options.size()-1))) {
            order+=1;
            this->putVecToConsole(*vec.get(), order);
        }
    }
}

inline void Menu::putVecToConsole(std::vector<std::string> &vec, int order) {
    for(int i = 1; i < 6; i++) {
        std::cout << "\r" << "\x1b[K" << std::endl;
    }
    int i = 0;
    for(auto& elm:vec) {
        if(i==order) {
            elm.replace(0,1,">");
            std::cout << "\u001b[35m" << elm << "\u001b[0m" << std::endl;
        } else {
            std::cout << elm << std::endl;
        }
        i++;
    }
}
