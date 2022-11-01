#include <stdio.h>
int main()
{
	int a[3][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
	int row_len = 0;
	int col_len = 0;
	int num = 0;

	//类型 = 定义 - 名字
	//a       --> int [3][4]
	//a[0]    --> int [4]
	//a[0][0] --> int 

	//行数 = 整个数组的大小 / 每一行的大小
	row_len = sizeof(a) / sizeof(a[0]);
	//row_len = sizeof(int [3][4]) / sizeof(int [4]);
	printf("row_len:%d\n", row_len);

	//列数 = 每一行的大小 / 每一个元素的大小
	col_len = sizeof(a[0]) / sizeof(a[0][0]);
	//col_len = sizeof(int [4]) / sizeof(int);
	printf("col_len:%d\n", col_len);

	//元素个数 = 整个数组的大小 / 单个元素的大小
	num = sizeof(a) / sizeof(a[0][0]);
	//num = sizeof(int [3][4]) / sizeof(int);
	printf("num:%d\n", num);

	

	return 0;
}
