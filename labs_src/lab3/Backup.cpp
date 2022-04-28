#include "Backup.h"

RestorePoint* ConcreteBackup::FactoryMethod(std::vector<JobObject *> listOfFiles, std::string typeOfStorage) const {
    return new RestorePoint(listOfFiles, typeOfStorage);
}
