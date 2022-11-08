#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>

int main(void)
{
    struct dirent *testdir = NULL;
    DIR *dp;

    dp= opendir("dir");
    if (dp == NULL)
    {
        perror("dir");
        return -1;
    }
    testdir = readdir(dp);
    printf("d->ino: %ld\n", testdir->d_ino);
    printf("d_off: %ld\n", testdir->d_off);
    printf("d_reclen: %d\n", testdir->d_reclen);
    printf("d_type: %c\n", testdir->d_type);
    printf("d_name: %s\n", testdir->d_name);
    printf("name: %s\n", dp->fd);
    closedir(dp);

    return 0;
}
