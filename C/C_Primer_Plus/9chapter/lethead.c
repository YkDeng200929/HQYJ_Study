#include <stdio.h>
#include <string.h>
#define NAME "ykdeng"
#define ADRESS "hubei"
#define NUMBER 13337482620
#define SIZE 40
#define SPACE ' '
void star(char a,int b);
int jump(char a);//the function caculate the spaces you want
int main(void)
{
	star('*',SIZE);
	putchar('\n');
	star(SPACE,jump("ykdeng"));
	printf("%s\n", NAME);


	return 0;
}

void star(char a,int b)
{
	int count;
	for (count = 1;count < b; count++)
		putchar(a);
}

int jump(char a)
{
	int spaces;
	spaces = (SIZE - sizeof(a))/2;
	return spaces;
}
