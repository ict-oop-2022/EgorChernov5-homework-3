#pragma once

#include "BackupJob.h"

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
