#include <iostream>
#include <vector>
#include "include/menu/Menu.hpp"
#include "include/menu/MainMenu.hpp"

int main() {
    std::vector<std::string> options = {
        "Launch a server from profiles", "Create a new profile",
        "Edit a profile", "Show Profiles List", "Quit"};
    std::string message = "What would you like to do?";
    auto mainmenu = std::make_unique<MainMenu>(message, options);
    mainmenu->start();
}