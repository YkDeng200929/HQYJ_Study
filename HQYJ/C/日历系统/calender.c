#include <stdio.h>
#include "func.h"

int main()
{
    
    int year, month, day;
    printf("输入年月日\n");
    scanf("%d %d %d", &year, &month, &day);
    if (Isleap(year,month,day))
        printf("%d年%d月%d日是闰年\n", year,month,day);
    else
        printf("%d年%d月%d日不是闰年\n", year,month,day);
    Total_day(year,month,day);
    //printf("当前日期是星期%d\n", display_week(year,month,day));
    switch (display_week(year,month,day))
    {
        case 1:
            printf("当前日期是星期一\n");break;
        case 2:
            printf("当前日期是星期二\n");break;
        case 3:
            printf("当前日期是星期三\n");break;
        case 4:
            printf("当前日期是星期四\n");break;
        case 5:
            printf("当前日期是星期五\n");break;
        case 6:
            printf("当前日期是星期六\n");break;
        case 7:
            printf("当前日期是星期天\n");break;
    }
    
    display_month(year, month, day);
    return 0;
}