冒泡排序：
int a[5] = {5, 7, 8, 9, 1};
//非字符串类型
int len = sizeof(a) / sizeof(a[0]);
//字符串
//int len = strlen(a);
int i = 0, j = 0;
int temp;

for(i = 0; i < len - 1; i++)
{
	for(j = 0; j < len - 1 - i; j++)
	{
		// 比较a[j]和a[j + 1]
		//升序
		if(a[j] > a[j + 1])
		{
			temp = a[j];
			a[j] = a[j + 1];
			a[j + 1] = temp;
		}
		//降序
		if(a[j] < a[j + 1])
		{
			temp = a[j];
			a[j] = a[j + 1];
			a[j + 1] = temp;
		}
	}
}

简单选择排序
int a[5] = {5, 7, 8, 9, 1};
//非字符串类型
int len = sizeof(a) / sizeof(a[0]);
//字符串
//int len = strlen(a);
int i = 0, j = 0;
int temp;
int min/max;
int n;
for(i = 0; i < len - 1; i++)
{
	min/max = a[i];
	n = i;
	//寻找最小(大)值
	for(j = i + 1; j < len; j++)
	{
		//升序
		if(min > a[j])
		{
			//更新最小值和最小值下标
			min = a[j];
			n = j;
		}
		//降序
		if(max < a[j])
		{
			//更新最大值和最大值下标
			max = a[j];
			n = j;
		}
	}
	//交换a[i]和未排序中的最小(大)值
	if(n != i)
	{
		temp = a[i];
		a[i] = a[n];
		a[n] = temp;
	}
}

二维数组
本质：多个一维数组的组合
定义：数据类型 数组名[行数][列数]；
	eg:
		int a[2][3];//定义了元素类型为int型的2行3列的数组
	该数组里面每一个元素的类型为数据类型
	该数组名变量的类型：数据类型 [行数][列数]
	eg:
		int a[2][3];
		里面元素：int
		变量        类型
		a变量：     int [2][3]
		a[0] :      int [3]
		a[0][0]:    int
初始化：赋初始值
	1、全部初始化
		eg:
			int a[2][3] = {{1, 2, 3}, {4, 5, 6}};//结构初始化
			int a[2][3] = {1, 2, 3, 4, 5, 6};//顺序初始化
	2、部分初始化：未初始化的数据，默认为0
		eg:
			int a[2][3] = {{1}, {4}};//结构初始化
			int a[2][3] = {1, 2};//顺序初始化
	必须要有初始化的前提下，可以省略行数
使用二维数组：
	获取其中某一个元素：
		数组名[行下标][列下标]
				-------------
				行/列：从0开始
常量结论：int a[3][4]
	整个数组的大小：sizeof(a)
	元素的个数：sizeof(a) / sizeof(a[0][0])
	行数：sizeof(a) / sizeof(a[0])
	列数：sizeof(a[0]) / sizeof(a[0][0])
二维数组的输入输出
int a[3][4] = {0};
int i = 0, j = 0;

for(i = 0; i < sizeof(a) / sizeof(a[0]); i++)
{
	for(j = 0; j < sizeof(a[0]) / sizeof(a[0][0]); j++)
	{
		//输入
		scanf("%d", &a[i][j]);
	}
}
for(i = 0; i < sizeof(a) / sizeof(a[0]); i++)
{
	for(j = 0; j < sizeof(a[0]) / sizeof(a[0][0]); j++)
	{
		//逻辑处理
		//a[i][j]
	}
	putchar('\n');
}
for(i = 0; i < sizeof(a) / sizeof(a[0]); i++)
{
	for(j = 0; j < sizeof(a[0]) / sizeof(a[0][0]); j++)
	{
		//输出
		printf("%d ", a[i][j]);
	}
	putchar('\n');
}
	



























