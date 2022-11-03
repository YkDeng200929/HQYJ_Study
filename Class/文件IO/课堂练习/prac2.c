#include <stdio.h>

int main(void)
{
    /*
    char buf[1024];
    sprintf(buf, "good good study\n");
    fprintf(stdout, "%s", buf);
    */
   int a = 123;
   char buf[100] = {0};
   sprintf(buf, "%d", a);
   fprintf(stdout, "%s", buf);

    return 0;
}