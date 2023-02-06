#include "include/MainMenu.hpp"
#include "include/Menu.hpp"
#include <iostream>
#include <memory>

int main() {
    std::vector<std::string> options = {
        "Launch a server from profiles", "Create a new profile",
        "Edit a profile", "Show Profiles List", "Quit"};
    std::string message = "What would you like to do?";
    auto menu = std::make_unique<Menu>(message, options);
    menu->prompt().start(MainMenu::mainPrompt, MainMenu::select);
    menu.reset();
}