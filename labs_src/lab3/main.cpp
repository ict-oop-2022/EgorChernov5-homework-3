#include "BackupJob.h"

#include <filesystem>
#include <stdlib.h>

int main() {
    JobObject *jobObject1 = new JobObject("/home/purpleduck/File1");
    JobObject *jobObject2 = new JobObject("/home/purpleduck/File2");
    JobObject *jobObject3 = new JobObject("/home/purpleduck/File3");

    BackupJob backupJob;

    backupJob.setName("bj1");
    backupJob.setType("Split storage");
    backupJob.setPath("/home/purpleduck/testDir/");
    backupJob.addJobObject({jobObject1, jobObject2, jobObject3});
    backupJob.createRestorePoint("Real");

    delete jobObject1;
    delete jobObject2;
    delete jobObject3;
    return 0;
}