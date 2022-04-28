#pragma once

#include "RestorePoint.h"
#include "JobObject.h"

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
