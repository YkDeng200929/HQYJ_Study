#include <stdio.h>

int *Func_my_add(int a,int b)
{
    static int ret = 0;
    ret = a + b;

    return &ret;
}

int main()
{
    int a = 10, b = 20;
    int ret_m = 0;
    int *p = NULL;// 初始化指针变量 p

    p = Func_my_add(a,b);//  
    printf("%d\n", &ret_m); // ret_m 不是一个左值
    printf("*p: %d\n", *p);

    ret_m = *(Func_my_add(a,b));
    printf("ret: %d\n", ret_m);

    return 0;
}