#pragma once
#include "include/menu/Menu.hpp"

class MainMenu : public Menu {
    public:
    typedef Menu super;
    MainMenu(std::string& message, std::vector<std::string>& options);
    MainMenu& start();
};