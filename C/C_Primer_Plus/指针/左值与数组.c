#include <stdio.h>
int main(void)
{
	char arr[] = "I love you forever";
	int count = 0;

/*	while (*arr++ != '\0') // 注意，arr是数组地址，不是变量，不是左值，所以需要将其赋给其他变量*/
	char *arr_copy = arr;
	while (*arr_copy++ != '\0')
	{
		count++;
	}

	printf("arr have %d's character\n", count);

	return 0;
	// 总结：数组名是地址，而指针是左值
}
