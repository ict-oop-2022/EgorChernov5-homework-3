#include "RestorePoint.h"

/*RestorePoint::RestorePoint(std::string name, std::string type, std::string path, std::vector <std::string> files) {
    this->name = name;

    this->path = path;

    if (type == "Split storages") {
        this->type = type;
        for (int i = 0; i < files.size(); i++) {
            // create jobObject and his storage, after that create dir which have dir with copy file
        }
    } else if (type == "Single storage") {
        this->type = type;
        for (int i = 0; i < files.size(); i++) {
            // create jobObject and his storage, after that create dir with files
        }
    } else
        throw std::invalid_argument("Type didn't found.");
}*/
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
}
