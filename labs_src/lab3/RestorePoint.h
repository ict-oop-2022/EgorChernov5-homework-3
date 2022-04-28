#pragma once

#include "BackupJob.h"
#include "Storage.h"
#include "Repository.h"

class RestorePoint {
private:
    std::string name;
    std::string type;
    std::string path;
    std::vector<Storage *> Storage;
public:
    RestorePoint();
    void setParams(std::string name, std::string type, std::string path);
    void createStorage(std::vector<JobObject *> listOfFiles);
};
