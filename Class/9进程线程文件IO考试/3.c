#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(int argc, const char *argv[])
{
    char buf[20] = {0};
    int fd;
    fd = open(argv[1], O_RDONLY|O_WRONLY|O_RDWR|O_CREAT|O_TRUNC|O_APPEND, 0666);
    fgets(buf, sizeof(buf), stdin);
    write(fd, buf, sizeof(buf));
    lseek(fd, 0, SEEK_SET);
    read(fd, buf, strlen(buf));
    printf("%s\n", buf);

    return 0;
}