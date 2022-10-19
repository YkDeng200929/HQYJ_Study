#include <stdio.h>

int leap_year(int year)
{
    if (((year % 100 != 0) && (year % 4 == 0)) || (year % 400 == 0))
        return 29;// 闰年2月有29天
    else
        return 28;
}

int main()
{
    int month_day[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int year = 2022, month = 10, day = 1;
    printf("输入年月日: \n");
    //scanf("%d %d %d", &year, &month, &day);
    month_day[1] = leap_year(year);
    /*
    输入年月日, 判断这一天是该年的第几天
    */

    int i, day_of_year = 0;
    if (month == 1)
    {
        return day;
    }
    for (i = 0; i < month; i++)
    {
        day_of_year += month_day[i-1];
    }
    printf("Day of the year: %d\n", day_of_year += day);

    return 0;
}