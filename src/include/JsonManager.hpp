#pragma once 
#include <iostream>
#include <filesystem>
#include <fstream>
#include "include/picojson/picojson.h"

class JsonManager {
public:
    JsonManager(std::filesystem::path);
    void write(picojson::value v);
    void read();
private:
    std::filesystem::path path;
    std::string contents;
    picojson::value value;
    void readStrFromFile();
};