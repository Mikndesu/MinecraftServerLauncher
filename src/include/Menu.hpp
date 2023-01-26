#pragma once

#include <iostream>
#include <string>
#include <vector>

class Menu {
public:
    Menu(std::string&, std::vector<std::string>&);
    Menu &init();
    void prompt();
private:
    std::string const message;
    std::vector<std::string> options;
    inline void putVecToConsole(std::vector<std::string>&, int order);
};