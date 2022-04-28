#include "Backup.h"

void Backup::addRestorePoint(RestorePoint *restorePoint) {
    listOfRestorePoint.push_back(restorePoint);
}

Backup::~Backup() {
    for (int i = 0; i < listOfRestorePoint.size(); i++) {
        delete listOfRestorePoint[i];
    }
}

RestorePoint* ConcreteBackupRP::FactoryMethod() const {
    return new RestorePoint();
}
