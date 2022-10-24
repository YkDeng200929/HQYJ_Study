#include <stdio.h>

int main()
{
    /*
    要求通过 q 来输出所有字符串
    打印格式如下: w u h a n ...
    存放 buf 的内容为:
    wuhan shanghai beijing
    */
    char a[] = "wuhan";
    char b[] = "shanghai";
    char c[] = "beijing";
    char *p[] = {&a[0], &b[0], &c[0], NULL};
    char buf[100] = {0};
    char **q = p;
    int i, j, k = 0;
    for (i = 0; *(q+i) != NULL; i++)
    {
        for (j = 0; *(q[i]+j) != '\0'; j++) // q[i] 相当于 p[i]
        {
            printf("%c ", *((*(q+i))+j)); // *(q+i) 与 *q+i 优先级不同
            // *q+i <==> &a[0]+1       *(q+i) <==> *(p+i)
        }
    }

    // 将数据存到 buf
    
    for (i = 0; *(q+i) != NULL; i++)
    {
        for (j = 0; *(q[i]+j) != '\0'; j++)
        {
            buf[k++] = *((*(q+i))+j); // *(q+i) 与 *q+i 优先级不同
        }
        // 当 j == '\0' 时说明已经存完了每个字符串
        buf[k++] = ' ';
    }
    buf[k] = '\0';
    k = 0;
    printf("%s\n", buf);

    return 0;
}