#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <string.h>

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
    printf("读取所有文件名字\n");
    errno = 0;
    int count = 0;
    for (testdir; testdir != NULL; testdir = readdir(dp))
    {
        // 判断是错误还是文件结尾
        if (errno != 0)
        {
            perror("readdir");
            return -1;
        }
        if (testdir->d_type == DT_REG)
        {
            printf("d_name: %s\n", testdir->d_name);
            count++;
        }
        if (testdir->d_type == DT_DIR && testdir->d_name[0] != '.')
        {
            printf("d_name: %s\n", testdir->d_name);
            count++;
        }
    }
    printf("EOF\n");
    printf("count: %d\n", count);
    
    closedir(dp);

    return 0;
}
