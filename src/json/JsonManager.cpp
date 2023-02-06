#include "include/JsonManager.hpp"

JsonManager::JsonManager(std::filesystem::path path) : path(path) {
}

void JsonManager::read() {
    this->readStrFromFile();
    picojson::parse(this->value, this->contents);
}

void JsonManager::write(picojson::value v) {
    std::ofstream ofs(this->path, std::ios::app);
    ofs << v;
    this->value = v;
}

void JsonManager::readStrFromFile() {
    std::ifstream ifs(this->path, std::ios::in);
    std::getline(ifs, this->contents);
}