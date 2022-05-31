#pragma once

#include <iostream>

class Storage {
private:
    std::string name;
    std::string path;
public:
    Storage(std::string path);
};
