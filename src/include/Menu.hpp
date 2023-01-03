#pragma once

#include <iostream>
#include <string>
#include <vector>

class Menu {
public:
    Menu(std::string&, std::vector<std::string>&);
private:
    std::string const message;
    std::vector<std::string> const options;
};