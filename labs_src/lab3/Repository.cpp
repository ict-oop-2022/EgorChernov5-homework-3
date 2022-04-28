#include "Repository.h"

FileSys::~FileSys() {}

void RealFileSys::save(std::vector<JobObject *> listOfFiles, std::string name, std::string type, std::string path) const {

}

void MockFileSys::save(std::vector<JobObject *> listOfFiles, std::string name, std::string type, std::string path) const {

}

Repository::Repository(FileSys *fileSys) : fileSys(fileSys) {}

void Repository::save(std::vector<JobObject *> listOfFiles, std::string name, std::string type, std::string path) {
    this->fileSys->save(listOfFiles, name, type, path);
}

Repository::~Repository() {}


