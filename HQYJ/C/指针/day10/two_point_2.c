#include <stdio.h>

int main()
{
	int a[5] = {10, 20, 30, 40, 50};
	int *p = a;
	int **q = &p;
	int i = 0;

	//获取a数组首元素的值
	//a[0] *(a + 0) p[0] *(p + 0)
	//*q --> p
	//p[0] --> (*q)[0]
	//*(p + 0) --> *(*q + 0)
	
	for(i = 0; i < sizeof(a) / sizeof(a[0]); i++)
	{
		//a[i] p[i]
		//*(a + i) *(p + i)
		//*(*q + i) (*q)[i]
	}


	return 0;
}
