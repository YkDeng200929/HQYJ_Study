// c程序中访问字符串有两种方式:
//
// 1、定义一个字符数组，对他初始化，然后输出
// char string[] = "I love you";
// printf("%s", string);
//
// 2、定义一个字符指针，用字符指针指向字符串中的字符
// char *string = "I love you"
// printf("%s", string);
// 注意！！！这样是不对的：
// char *string;
// string = "I love you";
//
// 其实2中是把字符串首元素的地址赋给了string

#include <stdio.h>

int main(void)
{
	// 两者首元素都为Ａ，地址也相同

	char *str1 = "Apple";
	char *str2 = 'A';
	
	printf("%d\n", (str1 = str2)?1:0);

	printf("str1: %p; str2: %p\n", str1, str2);

	return 0;
}

// 将此例与　指针　文件夹中的函数指针作对比`
