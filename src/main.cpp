#include <iostream>
#include <memory>
#include "include/Menu.hpp"
#include "include/MainMenu.hpp"

int main () {
    std::vector<std::string> options = {"Launch a server from profiles", "Create a new profile", "Edit a profile", "Show Profiles List", "Quit"};
    std::string message = "What are you going to do?";
    auto menu = std::make_unique<Menu<Options::OptionsEnum>>(message, options);
    auto select = menu->prompt().start(MainMenu::mainPrompt);
}