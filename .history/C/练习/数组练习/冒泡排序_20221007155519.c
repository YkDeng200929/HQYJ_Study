// 冒泡排序就是对相邻的两个数进行排序

#include <stdio.h>

void bubble_range(int range[]);

int main(void)
{
    int num_range[10];
    
    for (int i=0; i<=9; i++)
    {
        printf("please enter a number:\n");
        int temp=0;
        scanf("%d", &temp);
        num_range[i] = temp;
    }

    bubble_range(num_range);

    return 0;

    return 0;
}

void bubble_range(int range[])
{
    
}