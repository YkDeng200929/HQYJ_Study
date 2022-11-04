#include <stdio.h>

int main(void)
{
    fclose(stderr);
    fclose(stdout);
    fprint(stdout, "Welcome to wuhan\n");
    fprintf(stderr, "No such file or directory\n");
    fclose(stderr);

    return 0;
}