#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "elzip.hpp"
#include <algorithm>

#include "Backup.h"
#include "JobObject.h"

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

    /*void addJobObject(std::vector <std::string> files);
    void removeJobObject(std::vector <std::string> files);*/
    void addJobObject(std::vector<JobObject *> listOfFiles);
    void removeJobObject(std::vector<JobObject *> listOfFiles);
    void createRestorePoint();
    void showRestorePoint();
    ~BackupJob();
};
