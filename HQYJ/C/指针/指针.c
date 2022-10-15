一级指针：保存普通变量的地址
指针：保存地址
定义和初始化指针变量：
	1、对应指针类型
		1>目标数据类型 --> 指向的数据类型
		2>加上 * --> *是说明符，说明是一个指针类型
	2、指针类型 + 变量名 = 定义
	eg:
	int a;
	short b;
	char c;
	int buf[5];
	int *p_a = &a;
	short *p_b = &b;
	char *p_c = &c;
	//p_buf_0该指针指向的是数组首元素的地址
	//数组首元素：buf[0] --> int
	//数组名 通常情况下 表示 该数组首元素的地址
	//p_buf_0 的偏移量 --> 目标数据类型(int) --> 每一个元素的大小 
	int *p_buf_0 = &buf[0];
	int *p_buf_0 = buf;
	//p_buf该指针指向的是整个数组的地址
	//buf是一个变量 -类型-> int [5]
	//p_buf 的偏移量 --> 目标数据类型(int [5]) --> 整个数组的大小
	int (*p_buf)[5];
	p_buf = &buf;
	
指针中常用运算符：
	1、&：取地址运算符
		作用：获取该变量的地址
		结果类型：类型 + *
	2、*：间接引用符
		作用：获取该地址的值[目标数据类型]
		结果类型：类型 - *
	结论：指针获取的字节数是根据指针类型[目标数据类型]决定的
	eg:
	int a;
	short b;
	char c;
	int *p_int = NULL;//int
	short *p_short = NULL;//short
	char *p_char = NULL;//char
	//&a --> 获取a这个变量的地址
	int *p_a = &a;
	//&b --> 获取b这个变量的地址
	short *p_b = &b;
	//&c --> 获取c这个变量的地址
	char *p_c = &c;
	//*p_a --> int --> 获取4个字节的数据
	*p_a <==> a;
	//*p_b --> short --> 获取2个字节的数据
	*p_b <==> b;
	//*p_c --> char --> 获取1个字节的数据
	*p_c <==> c;
	
	//从b这个变量的地址开始，获取4个字节
	p_int = (int *)&b;
	*p_int;//error，后面两个字节是非法地址
	
	//从a这个变量的地址开始，获取1字节
	p_char = (char *)&a;
	*p_char;

一级指针和一维数组：
	//数组名 通常情况下 表示该数组首元素的地址
	//buf <==> &buf[0]
	int buf[5] = {10, 20, 30, 40, 50};
	int *p = &buf[0];
	int i = 0;
	//int *p = buf;
	//p -类型-> int *
	//p -目标类型-> int
	//获取到n个元素的值
	//[] <==> *()
	buf[n] <==> *(p + n)  
	buf[n] <==> *(buf + n) 
	*(p + n) <==> p[n]
	
	for(i = 0; i < sizeof(buf) / sizeof(buf[0]); i++)
	{
		printf("%d ", buf[i]);
		printf("%d ", *(buf + i));
		printf("%d ", p[i]);
		printf("%d ", *(p + i));
	}
		
一级指针和字符串：

|            |
|  栈区      |可读可写权限
|            |存放程序中定义变量
--------------
|            |
|  堆区      |可读可写权限
|            |
--------------
|            |
|  常量区    |只读权限
|            |存放常量：10, 'a', "abcdef"

//字符串变量依赖于字符数组来存储
char buf[10] = "hello";//"hello"是初始化buf这个字符数组
char *p = "hello";//"hello"是字符串常量，会在常量区开辟6个字节
				  //p 指向 "hello"字符串常量的地址























	
	
	
	
	
	
	
	
	
	
	