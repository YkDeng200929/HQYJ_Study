#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
//#include <unistd.h>

int main()
{
    int fd;
    fd = open("HH", O_RDWR|O_CREAT|O_TRUNC, 0666);
    if (fd == -1)
    {
        perror("HH");
        return -1;
    }
    close(fd);

    return 0;
}