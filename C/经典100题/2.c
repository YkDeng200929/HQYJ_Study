/*题目：企业发放的奖金
根据利润提成。
利润(I)低于或等于10万元时，奖金可提10%；
从键盘输入当月利润I，求应发放奖金总数？*/

#include <stdio.h>

/*
函数功能：根据利润计算应发放奖金总数和
函数名: bouns()
函数参数: double profile
*/
double bouns(double profile)
{
    double ret;
    /*
利润高于10万元，低于20万元时，低于10万元的部分按10%提成，高于10万元的部分，可提成7.5%；
20万到40万之间时，高于20万元的部分，可提成5%；40万到60万之间时高于40万元的部分，可提成3%；
60万到100万之间时，高于60万元的部分，可提成1.5%，高于100万元时，超过100万元的部分按1%提成
    */
   if (profile > 100000.00 && profile < 200000.00)
   {
        if (profile < 100000.00)
        {
            ret = profile*(double)(0.1);
        }
        else
        {
            ret = profile*(double)(0.075);
        }
        return ret;
   }
   else if (profile >= 200000.00 && profile < 600000.00)
   {
        if (profile >= 200000.00 && profile < 400000.00)
        {
            ret = profile*(double)(0.05);
        }
        else
        {
            ret = profile*(double)(0.03);
        }
        return ret;
   }
   else if (profile >= 600000.00 && profile < 1000000.00)
   {
        if (profile < 1000000.00)
        {
            ret = profile*(double)(0.15);
        }
        else
        {
            ret = profile*(double)(0.1);
        }
        return ret;
   }

   return 0;
}

int main()
{
    double profile;
    printf("Enter the profile:\n");
    scanf("%lf", &profile);// double 必须 用 %lf 格式化输入, float 用 %f
    printf("The bouns: %.2f\n", bouns(400000));

    return 0;
}

/*
答案：

long int i;
int bonus1, bonus2, bonus3, bonus4, bonus6, bonus10, bonus;

scanf("%ld", &i);
bonus1 = 100000*0.1;
bonus2 = bonus1 + 100000*0.75;
bonus4 = bonus2 + 200000*0.5;
bonus6 = bonus4 + 200000*0.3;
bonus10 = bonus6 + 400000*0.15;

if (i <= 100000)
    bonus = i*0.1;
else if (i <= 200000)
    bonus = bonus1 + (i - 100000)*0.075;
else if (i <= 400000)
    bonus = bonus2 + (i - 200000)*0.05;
else if (i <= 600000)
    bonus = bonus4 + (i - 400000)*0.03;
else if (i <= 1000000)
    bonus = bonus6 + (i - 600000)*0.015;
else
    bonus = bonus10 + (i - 1000000)*0.01;

printf("%d\n", bonus);

*/