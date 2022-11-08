#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
//#include <unistd.h>
   
int main()
{
    long int val;
    char buf[1024] = {0};
    while (1)
    {   
        val = read(0, buf, sizeof(buf));
        if (val == -1)
        {
            perror("val");
            return -1;
        }
        printf("%s", buf);
    }
     
     return 0;
}