#include <stdio.h>
// ��׼�����޻���
int main(void)
{
    fprintf(stderr, "Hello");

    /*
    for (int i = 0;  i <= 1025; i++)
    {// ��������ʱˢ��
        printf("b");
    }
    */
    fflush(stdout);// ǿ��ˢ�»���

    //while (1); // 
    return 0;
}