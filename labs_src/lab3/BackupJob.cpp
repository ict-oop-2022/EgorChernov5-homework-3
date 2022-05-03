#include "BackupJob.h"

BackupJob BackupJob::setName(std::string name) {
    this->name = name;
    count = 0;
    return *this;
}

BackupJob BackupJob::setType(std::string type) {
    if (type == "Split storages")
        this->typeOfStorage = type;
    else if (type == "Single storage")
        this->typeOfStorage = type;
    else
        throw std::invalid_argument("Type wasn't found.");
    return *this;
}

BackupJob BackupJob::setPath(std::string path) {
    if (path.empty())
        throw std::invalid_argument("You should write path.");
    else if (path.substr(path.find_last_of("/") + 1).empty())
        this->pathOfNewStorage = path;
    else if (path == ".")
        this->pathOfNewStorage = path + "/";
    else if (path == path.substr(path.find_last_of("/") + 1))
        this->pathOfNewStorage = "./" + path + "/";
    else
        this->pathOfNewStorage = path + "/";
    return *this;
}

void BackupJob::addJobObject(std::vector<JobObject *> listOfFiles) {
    this->listOfFiles.insert(this->listOfFiles.end(), listOfFiles.begin(), listOfFiles.end());
}

void BackupJob::removeJobObject(std::vector<JobObject *> listOfFiles) {
    if (!this->listOfFiles.empty()) {
        for (int i = 0; i < listOfFiles.size(); ++i) {
            int check = 1;
            // удаление файлов
            for (int j = 0; j < this->listOfFiles.size(); ++j) {
                // проверка на совпадение
                if (listOfFiles[i] == this->listOfFiles[j]) {
                    auto n = find(this->listOfFiles.begin(), this->listOfFiles.end(), this->listOfFiles[j]);
                    delete this->listOfFiles[j];
                    this->listOfFiles.erase(n);
                    check = 0;
                    break;
                }
            }

            if (check) {
                std::cout << listOfFiles[i]->getPath() + " - this file is not in the Backup Job." << std::endl;
            }
        }
    } else
        std::cout << "You didn't add any files." << std::endl;
}

void BackupJob::createRestorePoint(std::string fileSystem) {
    if (fileSystem != "Mock" or fileSystem != "Real")
        throw std::invalid_argument("Type of file system wasn't found.");

    count += 1;
    RestorePoint *restorePoint = backup->FactoryMethod();
    restorePoint->setParams(("_" + std::to_string(count)), typeOfStorage, pathOfNewStorage);
    restorePoint->createStorage(listOfFiles, fileSystem);

    backup->addRestorePoint(restorePoint);
}

BackupJob::~BackupJob() {
    delete backup;
}