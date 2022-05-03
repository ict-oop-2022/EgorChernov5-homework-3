#include "RestorePoint.h"

RestorePoint::RestorePoint() {}

void RestorePoint::setParams(std::string name, std::string type, std::string path) {
    this->name = name;
    this->type = type;
    this->path = path;
}

void RestorePoint::createStorage(std::vector<JobObject *> listOfFiles, std::string fileSystem) {
    if (type.empty())
        throw std::invalid_argument("Parameters wasn't set.");

    FileSys *fileSys = nullptr;

    if (fileSystem == "Mock")
        fileSys = new MockFileSys;
    else if (fileSystem == "Real")
        fileSys = new RealFileSys;

    Repository *repository = new Repository(fileSys);
    std::vector<Storage *> storage = repository->save(listOfFiles, name, type, path);
    this->storage.assign(storage.begin(), storage.end());

    delete fileSys;
    delete repository;
}

RestorePoint::~RestorePoint() {
    for (int i = 0; i < storage.size(); i++) {
        delete storage[i];
    }
}
