#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <map>
#include "include/OptionsEnum.hpp"

class Menu {
private:
    using Option = Options::OptionsEnum;
    std::string const message;
    std::vector<std::string> options;
    inline std::vector<std::tuple<int, std::string>> enumrate(std::vector<std::string> vec) {
        int i = 0;
        std::vector<std::tuple<int, std::string>> enumrate = {};
        for(const auto& element:vec) {
            enumrate.push_back(std::make_tuple(i, element));
            i++;
        }
        return enumrate;
    }
public:
    Menu(std::string&, std::vector<std::string>&);
    Option prompt();
};