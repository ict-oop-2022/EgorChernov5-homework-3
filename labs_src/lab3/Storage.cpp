#include "Storage.h"

Storage::Storage(std::string path) {
    this->name = path.substr(path.find_last_of("/") + 1);
    this->path = path;
}
