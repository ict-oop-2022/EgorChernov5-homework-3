#include "Backup.h"

RestorePoint* Backup::FactoryMethod() {
    return new RestorePoint();
}

void Backup::addRestorePoint(RestorePoint *restorePoint) {
    listOfRestorePoint.push_back(restorePoint);
}

int Backup::countOfRestorePoint() {
    return listOfRestorePoint.size();
}

std::vector<RestorePoint *> Backup::getlistOfRestorePoint() {
    return listOfRestorePoint;
}

Backup::~Backup() {
    for (int i = 0; i < listOfRestorePoint.size(); i++) {
        delete listOfRestorePoint[i];
    }
}