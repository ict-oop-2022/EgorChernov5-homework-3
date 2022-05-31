#pragma once

#include <vector>
#include <filesystem>
#include <fstream>


#include "JobObject.h"
#include "Storage.h"

class FileSys {
public:
    virtual ~FileSys();
    virtual std::vector<Storage *> save(std::vector<JobObject *> listOfFiles, std::string name, std::string type, std::string path) const = 0;
};

class RealFileSys : public FileSys {
    std::vector<Storage *> save(std::vector<JobObject *> listOfFiles, std::string name, std::string type, std::string path) const override;
};

class MockFileSys : public FileSys {
    std::vector<Storage *> save(std::vector<JobObject *> listOfFiles, std::string name, std::string type, std::string path) const override;
};

class Repository {
protected:
    FileSys *fileSys;
public:
    Repository(FileSys *fileSys);
    std::vector<Storage *> save(std::vector<JobObject *> listOfFiles, std::string name, std::string type, std::string path);
    virtual ~Repository();
};
