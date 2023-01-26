#include <iostream>
#include <memory>
#include "include/Menu.hpp"

int main () {
    std::vector<std::string> options = {"Launch a server from profiles", "Create a new profile", "Edit a profile", "Show Profiles List", "Quit"};
    std::string message = "What are you going to do?";
    auto menu = std::make_unique<Menu>(message, options);
    menu->prompt();
}