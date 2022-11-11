#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

void write_fd(int fd1, int fd2)
{
    char buf[20] = {0};
    while (1)
    {
        memset(buf, 0, sizeof(buf));
        read(fd2, buf, sizeof(buf));
        write(fd1, buf, strlen(buf));
        sleep(5);
    }
}

int main(int argc, const char *argv[])
{
    int fd1, fd2;
    mkfifo("/home/linux/myfifo", 0777);
    fd1 = open(argv[1], O_RDWR);
    fd2 = open("/home/linux/myfifo", O_RDONLY,0777);
    write_fd(fd1, fd2);

    return 0;
}