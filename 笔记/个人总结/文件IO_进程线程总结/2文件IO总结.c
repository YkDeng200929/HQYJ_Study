#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

// 文件IO: 涉及系统底层, 所以头文件大多都包含 sys
// 文件IO 通过文件描述符 file description 来打开读写关闭文件

int main(void)
{
    int fd; // 文件描述符
    //1. open 打开一个文件
    fd = open("filesys.txt", O_RDONLY, 0666);

    //2. read 读取文件内容, 读取到自定义缓存数组中
    char buf[30] = {0};
    read(fd, buf, sizeof(buf)); // 不能用 strlen: strlen表示的是已有数组中的元素个数, 而sizeof表示的是整体的字节数量(此时buf中没数据, 所以strlen(buf) == 0)
    printf("I got context from fd(file discription): %s\n", buf);

    //3. write 写入数据到文件中, 将自定义缓存数组中的内容写入buf中
    int fd2;
    fd2 = open("filesys2.txt", O_RDWR|O_CREAT|O_TRUNC, 0666);
    memset(buf, 0, sizeof(buf));
    fgets(buf, sizeof(buf), stdin);
    write(fd2, buf, sizeof(buf));

    //4. 关闭文件描述符
    close(fd);
    close(fd2);

    return 0;
}