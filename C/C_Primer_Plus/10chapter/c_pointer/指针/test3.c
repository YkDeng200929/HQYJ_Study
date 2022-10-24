#include <stdio.h>

char *test(const char *arr)
{
    // 结论： arr 在函数 形参 中只是作为一个 变量， 这个变量值等于 main 中 对应实参的值
    printf("arr = %d\n", arr);
    printf("arr + 1 = %d\n", arr+1);

    return arr;
}

int main()
{
    char arr[] = "hello";
    printf("arr in main: %d\n", arr);
    test(arr);
    printf("arr in main new: %d\n", arr);

    return 0;
}