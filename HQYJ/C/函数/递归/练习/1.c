#include <stdio.h>
/*�ݹ�:
��֪���������˳��ݹ�
δ֪���� ( ���� ) ���ڵݹ�
*/
// ʵ�ֽ׳�
int n(int num)
{
    if (num == 0)
        return 1;
    else
    // �ҵ���֪����, num = 1 ʱ
        return num * n(num - 1);
    // ��֪:  num = 1 : �����˳�ѭ��
    // δ֪: num > 1; num * (num - 1) : ���ڵݹ�
}

int main()
{
    printf("%d\n", n(5));

    return 0;
}