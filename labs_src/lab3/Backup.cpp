#include "Backup.h"

RestorePoint* Backup::FactoryMethod() {
    return new RestorePoint();
}

void Backup::addRestorePoint(RestorePoint *restorePoint) {
    listOfRestorePoint.push_back(restorePoint);
}

Backup::~Backup() {
    for (int i = 0; i < listOfRestorePoint.size(); i++) {
        delete listOfRestorePoint[i];
    }
}