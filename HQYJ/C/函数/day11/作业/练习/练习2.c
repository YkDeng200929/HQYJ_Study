#include <stdio.h>

void count_data(int *a, int *b)
{
    int buf[10], i;
    for (i=0; i<10; i++)
    {
        printf("输入:\n");
        scanf("%d", &buf[i]);
    }
    for (i=0; i<10; i++)
    {
        if (buf[i]%2 != 0)
            (*a)+=1;
        else
            (*b)+=1;
    }
}

int main()
{
    printf("这是练习2\n");
    int odd_number=0,even_number=0;
    count_data(&odd_number,&even_number);
    printf("奇数：%d 偶数：%d\n",odd_number,even_number);

    return 0;
}
