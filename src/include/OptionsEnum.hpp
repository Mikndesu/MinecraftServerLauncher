#pragma once
#include <iostream>
#include <map>

namespace Options {
    enum class OptionsEnum {
        LAUNCH = 1,
        CREATE,
        EDIT,
        SHOW,
        QUIT
    };
    inline OptionsEnum begin(OptionsEnum) {
        return OptionsEnum::LAUNCH;
    }
    inline OptionsEnum end(OptionsEnum) {
        return OptionsEnum::QUIT;
    }
    inline OptionsEnum operator*(OptionsEnum option) {
        return option;
    }
    inline OptionsEnum &operator++(OptionsEnum &option) {
        return option = OptionsEnum(static_cast<std::underlying_type<OptionsEnum>::type>(option) + 1);
    }
    inline OptionsEnum getEnumByValue(int i) {
        auto map = []() -> std::map<int, OptionsEnum> {
            std::map<int, OptionsEnum> m;
            for (auto option:OptionsEnum()) {
                m.emplace(static_cast<int>(option), option);
            }
            return m;
        }();
        for (auto &&[key, value] : map) {
            if (key == i)
                return value;
        }
        return OptionsEnum::QUIT;
    }
};