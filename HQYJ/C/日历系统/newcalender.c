#include <stdio.h>

/*
函数功能：输入年月日， 判断该年是否为闰年
函数名： Isleap
函数参数： year, month, day
*/
int Isleap(int year, int month, int day)
{
    if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0))
        //printf("%d年%月%d日是闰年\n");
        return 29;
    else
        //printf("%d年%月%d日是不是闰年\n");
        return 28;
}

int month_day[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

/*
函数功能：输入年月日，返回该日期距离当年1月1日已过去多久
函数名： Total_day
函数参数： year, month, day
*/
int Total_day(int year, int month, int day)
{
    int total_day = 0;
    int i;
    for (i = 0; i < month; i++)
    {
        total_day += month_day[i];
    }
    total_day += day;

    return total_day;
}

/*
函数功能：判断输入的日期是星期几
函数名：display_week()
函数参数：year, month, day
*/
int display_week(int year, int month, int day)
{
    int week = 0;
    if (month == 1 || month == 2)
    {
        if (month == 1)
            week = (day + 2*13 + 3*(13+1)/5 + year + year/4 - year/100 + year/400 + 1)%7;
        else
            week = (day + 2*14 + 3*(14+1)/5 + year + year/4 - year/100 + year/400 + 1)%7;
    }
    else
        week = (day + 2*month + 3*(month+1)/5 + year + year/4 - year/100 + year/400 + 1)%7;

    return week;
}

/*
函数功能：显示当前日期当年当月的日历
函数名： display_month
函数参数: year, month, day
*/
void display_month(int year, int month, int day)
{
    printf("%20d年%d月%d日\n", year, month, day);
    char *month_name[7] = {"SUN", "Mon", "TUE", "WED", "THU", "FRI", "SAT"};
    int i, j;
    for (i = 0; i < 7; i++)
        printf("%4s", month_name[i]);
    putchar('\n');
    
    // 通过 week_day 判断需要输出多少个空格
    int week_day = display_week(year, month, 1);
    for (i = 0; i < week_day; i++)
        printf("%4c", ' ');
    // 输出日历内容
    for (j = 1; j <= month_day[month-1]; j++)// 因为实际月数比数组下标多1，所以这里减1
    {
        printf("%4d", j);
        if (i%7 == 6)
            putchar('\n');// 每行满时打印换行符
        i++;
    }
}


int main()
{
    printf("%d\n", display_week(2022, 10, 15));
    display_month(2022, 10, 15);

    return 0;
}