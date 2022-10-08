#include <stdio.h>

int switch_test(int num)
{
    switch (num)
    {
        case 1: 
            printf("this is num 1\n");
            //测试能否用return代替break语句
            return 1;
        case 2:
            printf("This is number 2\n");
            //break;
        default: 
            printf("This is other\n");
        // 以下测试能否在default后添加case
        case 3: 
            printf("This is 3\n");
        /*
        结论：
            default == case;
            之所以default中不用break是因为一般情况下default后没有其他语句，所以不会产生干扰
            default 后可以添加其他case
            所以最好在每个case中加上break
        */
    }    
}

int main(void)
{
    int num;
    printf("Enter:\n");
    scanf("%d", &num);

    switch (num){
        case 1:
            printf("This is number num1\n");//语句是可选的
            break;
        case 2:
            printf("This is number 2\n");
            //如果没有break语句，则会自动把后面所有没有break语句的case中 的所有语句
            break;
        default:
            printf("This is other number\n");
            //break;
            //在default中不需要break语句，因为没必要
    }
    printf("%d\n", switch_test(num));

    return 0;
}