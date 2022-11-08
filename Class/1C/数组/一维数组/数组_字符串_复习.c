一维数组：
	概念：相同类型的集合，编译器会分配连续的内存空间
	定义： 
		定义 = 类型 + 名字
		类型 = 定义 - 名字
		数据类型 数组名[元素个数]
			数据类型：任何类型
			数组名：标识符的命名规则
			元素个数：常量
		eg：
			int a[10];
			每一个元素的类型：int
			变量a的类型：int [10]
	初始化：在定义的时候赋值，才是初始化
		全部初始化：每一个元素都要赋初值
			eg：
				int a[5] = {10， 20， 30， 40， 50};
		部分初始化：只给其中几个元素赋初值，未赋初值的默认为0
			eg:
				int a[5] = {10, 20};//a[0] = 10, a[1] = 20, a[2] = 0, a[3] = 0, a[4] = 0
		全部初始化的时候，定义的时候可以省略元素个数
										————————————编译器能知道分配多少内存空间
	使用数组：
		数组名[数组下标]
			下标：从0开始
			最大下标：元素个数 - 1
	重点：
	数组名：int a[5];
		1、通常情况下，数组名表示该数组首元素的地址
			a <==> &a[0] --> 地址常量
			eg:
				a --> 数组首元素的地址
				a + 1 --> 偏移量(步长)是单个元素的字节大小 --> 4个字节
		2、两种特殊情况下，数组名表示整个数组
			1> sizeof(数组名)
				eg:
					sizeof(a) --> sizeof(int) * 5 --> 20个字节
			2> &数组名
				eg:
					&a --> 指向的该数组的首地址
					&a + 1 --> 偏移量(步长)是整个数组 --> 20个字节
	数组的输入输出：
		int i;
		int a[5];
		//输入
		for(i = 0; i < (sizeof(a) / sizeof(a[0])); i++)
		{
			scanf("%d", &a[i]);
		}
		//输出
		for(i = 0; i < (sizeof(a) / sizeof(a[0])); i++)
		{
			//做逻辑运算
			printf("%d", a[i]);
		}
		
	数组中常用的小结：
		1、数组的大小：sizeof(数组名)
		2、数组内每个元素的大小：sizeof(数组名[下标])
		3、数组的长度：sizeof(数组名) / sizeof(数组名[下标])

字符数组和字符串：
字符数组：
	char buf[10];
字符串：
	字符串一定是字符数组
	字符数组不一定是字符串
	区分点：最后是不是'\0'
	定义：
		char 数组名[元素个数] = {"hello"};
		char 数组名[元素个数] = "hello";
		char 数组名[] = "hello";
	字符串的相关函数
	char buf_1[100] = {0};
	char buf_2[100] = {0};
	1、输入输出
		scanf("%s", buf_1);
		printf("%s", buf_1);
		1>单个字符的输入输出
			int getchar(void);
			eg:
				char a;
				a = getchar();
			int putchar(int c);
			eg:
				char a = 'A';
				putchar(a);
		2>字符串的输入输出
			char *gets(char *s);//报警告
			eg:
				gets(buf_1);
			char *fgets(char *s, int size, FILE *stream);
			eg:
				fgets(buf_1, 100, stdin);
			int puts(const char *s);
			eg:
				puts(buf_1);
	2、获取字符串的长度
		#include <string.h>
		size_t strlen(const char *s);
		eg:
			strlen(buf_1);//获取第一个'\0'之前的有效元素个数
	3、字符串的拷贝
		#include <string.h>
		char *strcpy(char *dest, const char *src);
		//dest:目标字符数组
		//src:源字符串
		eg:
			strcpy(buf_1, buf_2);
	4、字符串的追加
		#include <string.h>
		char *strcat(char *dest, const char *src);
		//dest:目标字符数组
		//src:需要追加的字符串
		eg:
			strcat(buf_1, buf_2);
	5、字符串的逐个比较
		#include <string.h>
		int strcmp(const char *s1, const char *s2);
		//返回值：
		//	s1 > s2 返回值 大于0
		//	s1 < s2 返回值 小于0
		//	s1 == s2 返回值 等于0
		eg:
			ret = strcmp(buf_1, buf_2);
			if(ret > 0)
			{
				//s1 > s2
			}
			else if(ret < 0)
			{
				//s1 < s2
			}
			else
			{
				//s1 = s2
			}

















































