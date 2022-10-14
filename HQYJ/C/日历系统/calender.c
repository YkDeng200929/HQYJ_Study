#include <stdio.h>
#include "func.h"

int main()
{
    int year=2020, month=10, day=10;
    printf("输入年月日\n");
    //scanf("%d %d %d", &year, &month, &day);
    if (Isleap(year,month,day))
        printf("%d年%d月%d日是闰年\n", year,month,day);
    else
        printf("%d年%d月%d日不是闰年\n", year,month,day);
    Total_day(year,month,day);
    printf("当前是第%d周\n", display_week(year,month,day));
    display_month(year,month,day);
    return 0;
}