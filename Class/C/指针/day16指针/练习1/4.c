#include <stdio.h>

int main()
{
    int a[8] = {0};
    int number = 0, data = 0;
    int insert;
    int size_arr = sizeof(a)/sizeof(a[0])-1;
    printf("Enter where you wanna insert: \n");
    scanf("%d", &insert);
    printf("Enter the number you wanna insert: \n");
    scanf("%d", &number);
    for (int b = 0; b < (sizeof(a)/sizeof(a[0])-1); b++)
    {
        printf("Enter: ");
        scanf("%d", &a[b]);
    }
    // 倒序插入
    while (size_arr >= insert)
    {
        a[size_arr] = a[size_arr-1];
        size_arr--;
    }
    a[insert-1] = number;

    for (int c = 0; c < sizeof(a)/sizeof(a[0]); c++)
    {
        printf("%d ", a[c]);
    }


    return 0;
}