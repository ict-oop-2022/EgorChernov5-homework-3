#pragma once

#include <vector>

#include "Storage.h"
#include "Repository.h"
#include "JobObject.h"

class RestorePoint {
private:
    std::string name;
    std::string type;
    std::string path;
    std::vector<Storage *> storage;
public:
    RestorePoint();
    void setParams(std::string name, std::string type, std::string path);
    void createStorage(std::vector<JobObject *> listOfFiles, std::string fileSystem);
    int countOfStorage();
    ~RestorePoint();
};
