#include <stdio.h>

void input_data(int *arr)
{
    int i,num;
    for (int i = 0; i < 10; i++)
    {
        printf("Input number: ");
        scanf("%d", &num);
        arr[i] = num;
    }
    arr[10] = '\0';
}
void count_data(int *arr, int *count, int *sum)
{
    int i;
    for (i=0; i<10; i++)
    {
        if (*(arr+i) > 0)
        {
            (*count)++;// ++ 优先级高于 *
            *sum+=arr[i];
        }
    }
}

void printarr(int *arr)
{
    int i=0;
    while (*(arr+i) != '\0')
    {
        printf("%d ", *(arr+i));
        i++;
    }
}

int main()
{    
    int arr[10], count=0, sum=0;
    input_data(arr);
    printarr(arr);
    count_data(arr, &count, &sum);
    printarr(arr);
    printf("count: %d, sum: %d\n", count, sum);

    return 0;    
}