#include "backup.h"

RestorePoint::RestorePoint(std::string name, std::string type, std::string path, std::vector <std::string> files) {
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
}

///////////////////
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
        throw std::invalid_argument("Type didn't found.");
    return *this;
}

BackupJob BackupJob::setPath(std::string path) {
    if (path == path.substr(path.find_last_of("/") + 1))
        this->pathOfNewStorage = "./" + path;
    else
        this->pathOfNewStorage = path;
    return *this;
}

void BackupJob::addJobObject(std::vector <std::string> listOfFiles) {
    if (this->listOfFiles.empty()) {
        for (int i = 0; i < listOfFiles.size(); ++i)
            this->listOfFiles.push_back(new JobObject(listOfFiles[i]));
    } else {
        for (int i = 0; i < listOfFiles.size(); ++i) {
            int check = 1;

            for (int j = 0; j < this->listOfFiles.size(); ++j) {
                // приводим к одному виду
                if (listOfFiles[i] == listOfFiles[i].substr(listOfFiles[i].find_last_of("/") + 1))
                    listOfFiles[i] = "./" + listOfFiles[i];

                if (listOfFiles[i] == this->listOfFiles[j]->getPath()) {
                    check = 0;
                    break;
                }
            }
            // проверка на новый файл
            if (check)
                this->listOfFiles.push_back(new JobObject(listOfFiles[i]));
            else
                std::cout << listOfFiles[i] + " - this file already exists in the Backup Job." << std::endl;
        }
    }
}

void BackupJob::removeJobObject(std::vector <std::string> listOfFiles) {
    for (int i = 0; i < listOfFiles.size(); ++i) {
        /*auto n = find(this->listOfFiles.begin(), this->listOfFiles.end(), listOfFiles[i]);
        this->listOfFiles.erase(n);*/
        int check = 1;
        // приводим к одному виду
        if (listOfFiles[i] == listOfFiles[i].substr(listOfFiles[i].find_last_of("/") + 1))
            listOfFiles[i] = "./" + listOfFiles[i];
        // удаление файлов
        for (int j = 0; j < this->listOfFiles.size(); ++j) {
            // проверка на совпадение
            if (listOfFiles[i] == this->listOfFiles[j]->getPath()) {
                auto n = find(this->listOfFiles.begin(), this->listOfFiles.end(), this->listOfFiles[j]);
                delete this->listOfFiles[j];
                this->listOfFiles.erase(n);
                check = 0;
                break;
            }
        }

        if (check) {
            std::cout << listOfFiles[i] + " - this file is not in the Backup Job." << std::endl;
        }
    }
}

RestorePoint* BackupJob::createRestorePoint() {
    /*count += 1;
    if (name.empty()) {
        throw std::invalid_argument("You should set a name of Restore Point.");
    }

    if (typeOfStorage.empty()) {
        throw std::invalid_argument("You should set the type of Storage.");
    }

    if (pathOfNewStorage.empty()) {
        throw std::invalid_argument("You should set the new path.");
    }

    name = name + '_' + std::to_string(count);

    return new RestorePoint(name, typeOfStorage, pathOfNewStorage, listOfFiles);*/
    Backup *backup = new ConcreteBackup(listOfFiles);
    backup->FactoryMethod();


    delete backupJob;
}

BackupJob::~BackupJob() {
    for (int i = 0; i < listOfFiles.size(); ++i) {
        delete listOfFiles[i];
    }
}

///////////////////
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

JobObject::~JobObject() {}

///////////////////
Backup::Backup(std::vector<JobObject *> listOfFiles) {
    this->listOfFiles.assign(listOfFiles.begin(), listOfFiles.end());
}

///////////////////
RestorePoint* ConcreteBackup::FactoryMethod() const {
    return nullptr;
}
