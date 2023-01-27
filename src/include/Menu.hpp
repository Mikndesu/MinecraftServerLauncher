#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <tuple>

class Menu {
public:
    Menu(std::string&, std::vector<std::string>&);
    void prompt();
private:
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
    enum class OPTIONS {
        LAUNCH=1,
        CREATE,
        EDIT,
        SHOW,
        QUIT
    };
};