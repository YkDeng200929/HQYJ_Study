#include <stdio.h>

/*
函数功能：输入年月日，判断输入的日期是否是闰年
函数名： Isleap
参数：years month day
*/
int Isleap(int years, int month, int day)
{
    if ((years%100 != 0) && (years%4 == 0) || (years %400 == 0))
    {
        return 29;
    }
    else
        return 28;
}

/*
函数功能：判断月份
函数名称：judge_month
函数参数：year, month, day
*/


// 优化：判断月份
int month_day[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

/*
函数功能：判断该日期距离该年的一月一日过去多少天了
函数名： Total_day()
参数： years, month, day
*/
//static int month_more_day[5] = {1,3,5,7,8,10,12};
//static int month_de_day[5] = {4,6,9,11};

int Total_day(int year, int month, int day)
{
    int count_day=0, count_year=year;
    month_day[1]=Isleap(year, month, day);

    int i;
    for (i=0; i < month; i++)
    {
        count_day += month_day[i];
    }
    count_day += day;
    printf("%d年1月1日距离%d年%d月%d日一共过了%d天\n", year, year, month, day, count_day);

    return count_day;
    
}

/*
函数功能：判断输入日期是星期几
函数名称：display_week
函数参数：year, month, day
*/

int display_week(int year, int month, int day)
{
    int week=0;
    if (month == 1)
    {
        week = ((day + 2*13) + (3*(13+1)/5) + (year + year/4) - (year/100) + (year/400) + 1)%7;        
    }
    else if (month == 2)
    {
        week = ((day + 2*14) + (3*(14+1)/5) + (year + year/4) - (year/100) + (year/400) + 1)%7;
    }
    else
        week = ((day + 2*month) + (3*(month+1)/5) + (year + year/4) - (year/100) + (year/400) + 1)%7;

    return  week;
}

/*
函数功能：显示当前月历
函数名：display_month()
函数参数：year, month, day
*/

void display_month(int year, int month, int day)
{
    // 以下实现打印头两行
    const char *week[7] = {"SUN", "MON", "THS", "WEN", "THU", "FRI", "SAT"};
    printf("%23d年%d月\n", year, month);
    for (int i=0; i <7; i++)// 4 x 7 = 28
    {
        printf("%4s", week[i]);
    }
    putchar('\n');

    // 以下实现打印日历内容
    int num_day = month_day[month-1];
    int week_day = display_week(year, month, 1);

    // 理解：
    int i, j, k = 1;
    // 打印第一行的空白，因为周数决定空白数
    for (i = 0; i < week_day; i++)
        printf("%4c", ' ');
    for (j = 1; j <= month_day[month-1]; j++) // 因为数组元素下标比实际月数小1
    {
        printf("%4d", j);
        // 每逢7个数打印换行符
        if (i%7 == 6)
            printf("\n");
        i++;
    }
    printf("\n");
}