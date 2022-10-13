#include <stdio.h>
/*
// 练习1
int calc_data(int a, int b, int *c)
{
    int res;
    if (a < b)
        res = b;
    else
        res = a;
    (*c) = a + b;
    return res;
}

// 练习2
void count_data(int *a, int *b)
{
    int buf[10], i;
    for (i=0; i<10; i++)
    {
        printf("输入:\n");
        scanf("%d", &buf[i]);
    }
    for (i=0; i<10; i++)
    {
        if (buf[i]%2 != 0)
            (*a)+=1;
        else
            (*b)+=1;
    }

}
*/
// 练习3
void count_data2(int *nu, int *ch, int *sm)
{
    int i;
    char buf[1024]={0};
    printf("输入：\n");
    scanf("%s", buf);
    for (i=0; i<sizeof(buf)/sizeof(buf[0]); i++)
    {        
        for (int j=0; j<10; j++)
        {
            if ((int)buf[i] == j)
                (*nu)++;
        }
        for (int a=0; a<10; a++)
        {
            if (buf[a] == 'a'+a)
                (*ch)++;
        }
        if ((buf[i]) != 0 && (buf[i+1] != 0))
            (*sm)++;
    }
}

int main()
{
    /*
    // 练习1
    printf("这是练习1\n");
    int a,b,max_value,sum;
    printf("Enter:\n");
    scanf("%d %d", &a, &b);
    max_value=calc_data(a,b,&sum);
    printf("a = %d b = %d max = %d sum = %d\n", a, b, max_value,sum);

    //练习2
    printf("这是练习2\n");
    int odd_number=0,even_number=0;
    count_data(&odd_number,&even_number);
    printf("奇数：%d 偶数：%d\n",odd_number,even_number);
    */

    //练习3
    int char_num=0, data_num=0, total_num=0;
    count_data2(&char_num, &data_num, &total_num);
    printf("字符数量：%d 数字数量：%d 总数量：%d\n", char_num, data_num, total_num);


    return 0;
}