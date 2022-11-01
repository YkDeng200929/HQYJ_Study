#include <stdio.h>

int main()
{
    char a[] = "language", b[] = "programe";
    char *p1, *p2;
    int k;
    p1 = a; p2 = b;
    for (k = 0; k < 8; k++)
    {
        if (*(p1 +  k) == *(p2 + k))
            printf("%c", *(p1 + k));
            // 若两个字符相同则打印
    }
    // 输出： gae

    return 0;
}