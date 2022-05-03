#pragma once

#include "RestorePoint.h"

class Backup {
private:
    std::vector<RestorePoint *> listOfRestorePoint;
public:
    virtual RestorePoint* FactoryMethod() const = 0;
    void addRestorePoint(RestorePoint *restorePoint);
    virtual ~Backup();
};

class ConcreteBackupRP: public Backup {
public:
    RestorePoint* FactoryMethod() const override;
};
