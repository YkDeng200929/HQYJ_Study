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
        Isleap(years,month,day);
        return 29;
    }
    else
        return 0;
}

/*
函数功能：判断月份
函数名称：judge_month
函数参数：year, month, day
*/

int judge_month(int year, int month, int day)
{
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
        {
            return 31;
        }
        else if (month == 2)
        {
            return Isleap(year,month,day);
        }
        else
            return 30;
}

/*
函数功能：判断该日期距离该年的一月一日过去多少天了
函数名： Total_day()
参数： years, month, day
*/
//static int month_more_day[5] = {1,3,5,7,8,10,12};
//static int month_de_day[5] = {4,6,9,11};

int Total_day(int year, int month, int day)
{
    int count_day=0, count_year=year, two_month_day=28;

    int i;
    for (i=1; i != month; i++)
    {
        count_day += judge_month(year,i,day);
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
        week = (day + 2*13 + 3*(13+1)/5 + year + year/4 - year/100 + year/400 + 1)%7;        
    }
    else if (month == 2)
    {
        week = (day + 2*14 + 3*(14+1)/5 + year + year/4 - year/100 + year/400 + 1)%7;
    }
    else
        week = (day + 2*month + 3*(month+1)/5 + year + year/4 - year/100 + year/400 + 1)%7;

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
    char *week[7] = {"SUN", "MON", "THS", "WEN", "THU", "FRI", "SAT"};
    printf("%24d年%d月\n", year, month);
    for (int i=0; i <7; i++)// 4 x 7 = 28
    {
        printf("%4s", week[i]);
    }
    putchar('\n');

    // 以下实现打印日历内容
    char day_display[40];
    int blank = 0; // 因为空白就是周数
    if (display_week(year,1,1) == 7)
        blank = display_week(year,month,day);
    int a = 0, b=1, c;
    for (a = 0; a < blank; a++)
        day_display[a] = ' ';
    for (a; a < judge_month(year,month,day); a++)
    {
        day_display[a] = b++;
    }
    day_display[a] = '\0';
    b = 0;

    for (a = 0; a < 6; a++)
    {
        for (c = 0; c < 7; c++)
            printf("%4c", day_display[b++]);
    }



}
    /* 以下代码有问题
    int j, i=1;
    for (j=0; j < blank; j++)
    {
        day_display[j] = 0;
    }
    for (; j < (blank + judge_month(year,month,day)); j++)
    {
        day_display[j] = i;
        i++;
    }
    day_display[++j] = '\0';
    // 打印日历内容
    int a, b, c=0;
    for (a = 0; day_display[a] != '\0'; a++)
    {
        for (b = 0; b < 7; b++)
            printf("%4d", day_display[c++]);
        putchar('\n');
    }

}
*/