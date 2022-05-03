#pragma once

#include <iostream>
#include <string>

class JobObject {
private:
    std::string path;
    std::string name;
public:
    JobObject(std::string path);
    std::string getPath();
    std::string getName();
    ~JobObject();
};
