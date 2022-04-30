#include "Repository.h"

FileSys::~FileSys() {}

std::vector<Storage *> RealFileSys::save(std::vector<JobObject *> listOfFiles, std::string name, std::string type, std::string path) const {
    std::string str;
    std::fstream fs;
    std::fstream fsNew;
    std::vector<Storage *> storage;
    fs.exceptions(std::fstream::badbit | std::fstream::failbit);
    fsNew.exceptions(std::fstream::badbit | std::fstream::failbit);

    for (int i = 0; i < listOfFiles.size(); i++) {
        try {
            fs.open(listOfFiles[i]->getPath(), std::fstream::in);
            if (type == "Single storage") {
                try {
                    std::string path1 = path + listOfFiles[i]->getName() + name;
                    fsNew.open((path1), std::fstream::out | std::fstream::app);
                    while (!fs.eof()) {
                        str = "";
                        std::getline(fs, str);
                        fsNew << str + "\n";
                    }
                    storage.push_back(new Storage(path1));
                }
                catch (const std::exception &ex) {
                    std::cout << ex.what() << std::endl;
                    throw std::invalid_argument("Copy file wasn't opened.");
                }
            } else if (type == "Split storage") {
                try {
                    std::string path1 = path + std::to_string(i) + "/" + listOfFiles[i]->getName() + name;
                    fsNew.open((path1), std::fstream::out | std::fstream::app);
                    while (!fs.eof()) {
                        str = "";
                        std::getline(fs, str);
                        fsNew << str + "\n";
                    }
                    storage.push_back(new Storage(path1));
                }
                catch (const std::exception &ex) {
                    std::cout << ex.what() << std::endl;
                    throw std::invalid_argument("Copy file wasn't opened.");
                }
            }
        }
        catch (const std::exception &ex) {
            std::cout << ex.what() << std::endl;
            throw std::invalid_argument("File wasn't opened.");
        }
    }

    return storage;
}

std::vector<Storage *> MockFileSys::save(std::vector<JobObject *> listOfFiles, std::string name, std::string type, std::string path) const {
}

Repository::Repository(FileSys *fileSys) : fileSys(fileSys) {}

void Repository::save(std::vector<JobObject *> listOfFiles, std::string name, std::string type, std::string path) {
    this->fileSys->save(listOfFiles, name, type, path);
}

Repository::~Repository() {}


