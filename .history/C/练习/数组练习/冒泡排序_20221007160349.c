// 冒泡排序就是对相邻的两个数进行排序

#include <stdio.h>

void bubble_range(int range[]);
void print_range(int range[]);

int main(void)
{
    int num_range[10];
    
    for (int i=0; i<=sizeof(num_range); i++)
    {
        printf("please enter a number:\n");
        int temp=0;
        scanf("%d", &temp);
        num_range[i] = temp;
    }
    print_range(num_range);

    bubble_range(num_range);
    print_range(num_range);

    return 0;

    return 0;
}

void bubble_range(int range[])
{
    for (int i=0; i<=sizeof(range); i++)
    {
        
        if (range[i] > range[i+1])
        {
            int temp;
            temp = range[i+1];
            range[i+1] = range[i];
            range[i] = temp;
        }
    }
}

void print_range(int range[])
{
    for (int i = 0; i<=sizeof(range); i++)
    {
        printf("%d ", range[i]);
    }
    printf("\n");
}