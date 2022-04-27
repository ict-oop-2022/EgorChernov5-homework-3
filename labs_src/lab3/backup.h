#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "elzip.hpp"
#include <algorithm>

class JobObject {
private:
    std::string path;
    std::string name;
public:
    JobObject(std::string path);
    std::string getPath();
    ~JobObject();
};

class Storage {
public:
    void copyFile(JobObject *jobObject);
};

class RestorePoint {
private:
    std::string name;
    std::string type;
    std::string path;
    std::vector<Storage *> Storage;
public:
    RestorePoint(std::vector<JobObject *> listOfFiles, std::string typeOfStorage);
};

class Backup {
private:
    std::vector<RestorePoint *> listOfRestorePoint;
public:
    virtual RestorePoint* FactoryMethod(std::vector<JobObject *> listOfFiles, std::string typeOfStorage) const = 0;
};

class ConcreteBackup: public Backup {
public:
    RestorePoint* FactoryMethod(std::vector<JobObject *> listOfFiles, std::string typeOfStorage) const override;
};

class BackupJob {
private:
    std::string name;
    std::string typeOfStorage;
    std::string pathOfNewStorage;
    std::vector<JobObject *> listOfFiles;

    int count;
public:
    BackupJob setName(std::string name);
    BackupJob setType(std::string type);
    BackupJob setPath(std::string path);

    void addJobObject(std::vector <std::string> files);
    void removeJobObject(std::vector <std::string> files);
    RestorePoint* createRestorePoint();
    ~BackupJob();
};

class Repository {
    void zipDir();
    void unzipDir();
    void unzipFile();
};