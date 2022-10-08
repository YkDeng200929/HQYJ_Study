#include <stdio.h>

int Get_ws(int num)
{
  char want;
  printf("输入想返回的位数(个位：g, 十位：s, 百位：b):\n");
  scanf("%c", want);
  do{
    if (want == 'g')
        return num%10;
    else if (want == 's')
        return (num%100)/10;
    else
        return num/100;    
  }while(wa)
}

int main(void)
{
    int num=321;
    printf("%d\n", Get_ws(num));
    return 0;
    
}