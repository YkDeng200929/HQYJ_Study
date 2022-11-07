#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>

int main(void)
{
    DIR *dp;

    dp= opendir("dir");
    closedir(dp);

    return 0;
}
