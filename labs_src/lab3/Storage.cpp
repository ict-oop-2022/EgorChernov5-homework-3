#include "Storage.h"

Storage::Storage(std::string path) {
    this->path = path;
    this->name = path.substr(path.find_last_of("/") + 1);
}
