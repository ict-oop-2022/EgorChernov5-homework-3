#pragma once

#include <vector>
#include <algorithm>

#include "JobObject.h"
#include "Backup.h"

// #include "elzip.hpp"

class BackupJob {
private:
    std::string name;
    std::string typeOfStorage;
    std::string pathOfNewStorage;
    std::vector<JobObject *> listOfFiles;
    Backup *backup = new Backup();

    int count = 0;
public:
    void setName(std::string name);
    void setType(std::string type);
    void setPath(std::string path);

    void addJobObject(std::vector<JobObject *> listOfFiles);
    void removeJobObject(std::vector<JobObject *> listOfFiles);
    void createRestorePoint(std::string fileSystem);

    int countOfJobObject();
    int countOfRestorePoint();
    int countOfStorage();

    ~BackupJob();
};
