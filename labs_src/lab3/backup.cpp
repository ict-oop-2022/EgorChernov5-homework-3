#include "backup.h"

BackupJob::BackupJob(std::string name, std::string type, std::string path) {
    this->name = name;

    if (type == "Split storages")
        this->type = type;
    else if (type == "Single storage")
        this->type = type;
    else
        throw std::invalid_argument("Type didn't found.");

    this->path = path;

    count = 0;
}

void BackupJob::addObject(std::vector <std::string> files) {
    if (this->files.empty())
        this->files.assign(files.begin(), files.end());
    else {
        for (int i = 0; i < files.size(); i++) {
            int check = 1;
            for (int j = 0; j < this->files.size(); j++) {
                if (files[i] == this->files[j]) {
                    check = 0;
                    break;
                }
            }
            // проверка на новый файл
            if (check)
                this->files.push_back(files[i]);
        }
    }
}

void BackupJob::removeObject(std::vector <std::string> files) {
    for (int i = 0; i < files.size(); i++) {
        auto n = find(this->files.begin(), this->files.end(), files[i]);
        this->files.erase(n);
    }
}

void BackupJob::createRestorePoint() {
    count += 1;

}

JobObject::JobObject(std::string name, std::string path) {
    this->path = path;
    this->name = path.substr(path.find_last_of('/') + 1);

    /*for (int i = 0; i < files.size(); i++) {
        std::string name = files[i].substr(files[i].find_last_of('/') + 1);
        std::string path = files[i];
    }*/
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