int Errupt;
double Up[100];       // 以上为外部定义的变量和数组
extern char Coal;     // 表明在同一文件夹的另一文件中声明了变量 Coal，则可使用extern表明使用该变量

void next(void)
int main(void)
{
  extern int Errupt;  // extern：用于访问外部定义的变量
  
  extern double Up[];
  ...
}
void next(void)
{
  ...
}
