#include "JobObject.h"

JobObject::JobObject(std::string path) {
    if (path == path.substr(path.find_last_of("/") + 1))
        this->path = "./" + path;
    else
        this->path = path;

    this->name = path.substr(path.find_last_of('/') + 1);
}

std::string JobObject::getPath() {
    return this->path;
}

std::string JobObject::getName() {
    return this->name;
}

JobObject::~JobObject() {}