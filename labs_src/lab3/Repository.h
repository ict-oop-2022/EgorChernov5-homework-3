#pragma once

#include "JobObject.h"

class FileSys {
public:
    virtual ~FileSys();
    virtual void save(std::vector<JobObject *> listOfFiles, std::string name, std::string type, std::string path) const = 0;
};

class RealFileSys : public FileSys {
    void save(std::vector<JobObject *> listOfFiles, std::string name, std::string type, std::string path) const override;
};

class MockFileSys : public FileSys {
    void save(std::vector<JobObject *> listOfFiles, std::string name, std::string type, std::string path) const override;
};

class Repository {
protected:
    FileSys *fileSys;
public:
    Repository(FileSys *fileSys);
    void save(std::vector<JobObject *> listOfFiles, std::string name, std::string type, std::string path);
    virtual ~Repository();
};
