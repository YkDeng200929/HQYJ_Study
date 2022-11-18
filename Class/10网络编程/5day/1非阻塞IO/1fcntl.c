#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>

int main(void)
{
    int fd = open("/dev/input/mice", O_RDONLY);
    if (fd < 0)
    {
        perror("open");
        return -1;
    }

    int flag = fcntl(fd, F_GETFL, 0);
    if (flag < 1)
    {
        perror("fcntl");
        return -1;
    }
    fcntl(fd, F_SETFL, O_NONBLOCK);
    
    flag = fcntl(0, F_GETFL, 0);
    if (flag < 1)
    {
        perror("fcntl");
        return -1;
    }
    fcntl(0, F_SETFL, O_NONBLOCK);

    char buf[30] = {0};
    while (1)
    {
        int len;
        memset(buf, 0, sizeof(buf));
        len = read(fd, buf, sizeof(buf));
        if (len > 0)
        {
            printf("%d\n", buf[0]);
        }
        memset(buf, 0, sizeof(buf));
        fgets(buf, sizeof(buf), stdin);
        if (strlen(buf) > 0)
        {
            printf("%s", buf);
        }
    }

    return 0;
}