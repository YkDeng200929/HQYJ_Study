#include <stdio.h>

int main()
{
    /*
    题目：利用条件运算符的嵌套来完成此题：
    学习成绩>=90分的同学用a表示，60-89分之间的用b表示，
　　60分以下的用c表示。
    */
    int goal;
    char score;
    scanf("%d", &goal);
    // 方案 1
    // goal >= 90 ? printf("A\n") : goal >= 60? printf("B\n"): printf("C\n");
    // 方案 2
    score = goal >= 90 ? 'A' : goal >= 60 ? 'B' : 'C';
    // 条件运算符的返回值为 'A' or ... 可以将其赋值给变量
    printf("%c\n", score);

    return 0;
}