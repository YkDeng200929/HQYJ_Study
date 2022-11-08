#include <stdio.h>

int main()
{
    int data[] = {10, 20, 31, 40, 50, 62, 73};
    int *p_array[] = {&data[0], &data[1], &data[2], &data[3], &data[4], &data[5], &data[6], NULL};
    int **q = p_array;
    int new_array[10] = {0};
    // 要求通过 q 寻找 data 中的偶数元素, 要求把数据选择出来后
    // 存放到 new_array 中, 并输出 new_array 中 存储的有效数据
    // 的个数和值
    int i; // 用于计算有效有效个数
    int j=0; // 用于遍历 p_array
    while (*(q+j) != NULL) // q <==> &p_array, 当 *q == NULL 时终止
    {
        // 判断元素是否为偶数
        if (*(*q+j) % 2 == 0)
        {
            new_array[i++] = *(*q+j);
        }
        j++;
    }

    new_array[j] = '\0';

    for (int a = 0; new_array[a] != '\0'; a++)
    {
        printf("%d ", new_array[a]);
    }

    return 0;
}