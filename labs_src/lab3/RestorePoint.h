#pragma once

#include "BackupJob.h"
#include "Storage.h"

class RestorePoint {
private:
    std::string name;
    std::string type;
    std::string path;
    std::vector<Storage *> Storage;
public:
    RestorePoint(std::vector<JobObject *> listOfFiles, std::string typeOfStorage);
};
