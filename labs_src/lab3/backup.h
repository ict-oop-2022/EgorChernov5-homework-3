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
    int count;
public:
    BackupJob(std::string name, std::string type, std::string path);
    void addObject(std::vector <std::string> files);
    void removeObject(std::vector <std::string> files);
    void createRestorePoint();
    ~BackupJob();
};

class JobObject {
private:
    std::string name;
    std::string path;
public:
    JobObject(std::string name, std::string path);
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