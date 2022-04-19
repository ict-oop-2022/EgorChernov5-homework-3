#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "elzip.hpp"
#include <algorithm>

class JobObject;

class Backup {

};

class RestorePoint {

};

class BackupJob {
private:
    std::string name;
    std::string type;
    std::string path;
    std::vector<std::string> files;
public:
    void setName(std::string name);
    void setZipType(std::string type);
    void setPath(std::string path);
    void addObject(JobObject *file);
    void removeObject(JobObject *file);
    void createRestorePoint();
};

class JobObject {
private:
    std::string path;
    std::string name;
public:
    JobObject(std::string path);
    std::string getName();
};

class Storage {
public:
    void copy(std::vector<std::string> files, std::string type, std::string path);
};

class Repository {
    void zipDir();
    void unzipDir();
    void unzipFile();
};