#include "backup.h"

void BackupJob::setName(std::string name) {
    this->name = name;
}

void BackupJob::setZipType(std::string type) {
    this->type = type;
    if (type == "Split storages") {
        this->type = type;
    } else if (type == "Single storage") {
        this->type = type;
    } else {
        throw std::invalid_argument("Type didn't found.");
    }
}

void BackupJob::setPath(std::string path) {
    this->path = path;
}

void BackupJob::addObject(JobObject *file) {
    this->files.push_back(file->getName());
}

void BackupJob::removeObject(JobObject *file) {
    auto n = find(this->files.begin(), this->files.end(), file->getName());
    this->files.erase(n);
}

void BackupJob::createRestorePoint() {

}

JobObject::JobObject(std::string path) {
    this->path = path;
    this->name = path.substr(path.find_last_of('/') + 1);
}

std::string JobObject::getName() {
    return name;
}

void Storage::copy(std::vector<std::string> files, std::string type, std::string path) {
    std::ofstream fout;
    std::ifstream fin;
    if (type == "Split storages") {
        for (int i = 0; i < files.size(); i++) {
            try {
                std::string str;
                fin.open(files[i]);
                fout.open(path);
                while (!fin.eof()) {
                    str = "";
                    getline(fin, str);
                    fout << str;
                }
            }
            catch (const std::exception &ex) {
                std::cout << ex.what() << std::endl;
                throw std::invalid_argument("Path isn't correct.");
            }


        }
    } else if (type == "Single storage") {

    } else {

    }
}