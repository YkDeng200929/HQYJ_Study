#include <stdio.h>

int Get_ws(int num)
{
  char want;
  printf("输入想返回的位数(个位：g, 十位：s, 百位：b):\n");
  scanf("%c", want);
  switch (want)
  {
    case 'g':
    {
      num %=10;
      return num;
    }
    case 's':
    {
      num /= (num%100);
      return num;
    }
    case 'b':
    {
      num /100;
      return num;
    }
    default:
    }
      printf("error");
  }
}

int main(void)
{
    int num=321;
    printf("%d\n", Get_ws(num));
    return 0;
    
}