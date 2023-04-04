#pragma once
#include <ncurses.h>

#include <concepts>
#include <iostream>
#include <string>
#include <vector>

class Menu {
   private:
    std::string const message;
    std::vector<std::string> options;
    inline std::vector<std::tuple<int, std::string>> enumrate(
        std::vector<std::string> vec) {
        int i = 0;
        std::vector<std::tuple<int, std::string>> enumrate = {};
        for (const auto& element : vec) {
            enumrate.push_back(std::make_tuple(i, element));
            i++;
        }
        return enumrate;
    }

   public:
    Menu(std::string& message, std::vector<std::string>& options);
    const std::vector<std::string>& getOptions();
    void start();
    void initScreen();
};