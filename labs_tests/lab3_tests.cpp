#include <gtest/gtest.h>

#include "lab3/BackupJob.h"

TEST(CreateBackups, SplitStorage) {
    JobObject *jobObject1 = new JobObject("/home/purpleduck/File1");
    JobObject *jobObject2 = new JobObject("/home/purpleduck/File2");

    BackupJob backupJob;

    backupJob.setName("bj1");
    backupJob.setType("Split storage");
    backupJob.setPath("/home/purpleduck/testDir/");
    backupJob.addJobObject({jobObject1, jobObject2});

    ASSERT_EQ(backupJob.countOfJobObject(), 2);

    backupJob.createRestorePoint("Mock");

    backupJob.removeJobObject({jobObject1});

    backupJob.createRestorePoint("Mock");

    ASSERT_EQ(backupJob.countOfRestorePoint(), 2);
    ASSERT_EQ(backupJob.countOfStorage(), 3);

    delete jobObject1;
    delete jobObject2;
}