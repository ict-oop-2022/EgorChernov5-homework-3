#pragma once

#include "RestorePoint.h"

class Backup {
private:
    std::vector<RestorePoint *> listOfRestorePoint;
public:
    RestorePoint* FactoryMethod();
    void addRestorePoint(RestorePoint *restorePoint);
    virtual ~Backup();
};

//class ConcreteBackupRP: public Backup {
//
//public:
//    RestorePoint* FactoryMethod() const override;
//    void addRestorePoint(RestorePoint *restorePoint) const override;
//};
