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
    Backup *backup = new ConcreteBackupRP();

    int count = 0;
public:
    BackupJob setName(std::string name);
    BackupJob setType(std::string type);
    BackupJob setPath(std::string path);

    void addJobObject(std::vector<JobObject *> listOfFiles);
    void removeJobObject(std::vector<JobObject *> listOfFiles);
    void createRestorePoint(std::string fileSystem);
    ~BackupJob();
};
