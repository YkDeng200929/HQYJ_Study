#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>

void write_fd(int fd)
{
    char buf[32] = {0};
    while (1)
    {
        memset(buf, 0, sizeof(buf));
        fgets(buf, sizeof(buf), stdin);
        write(fd, buf, strlen(buf));
    }
}

int main(void)
{
    int ret;
    int fd;
    ret = mkfifo("fifo_file", 0777);
    if (ret == -1 && errno != EEXIST)
    {
        perror("mkfifo");
        return -1;
    }
    
    fd = open("fifo_file", O_WRONLY);

    if (fd == -1)
    {
        perror("open");
        return -1;
    }

    write_fd(fd);

    return 0;
}