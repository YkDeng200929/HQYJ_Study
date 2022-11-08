#include <stdio.h>
#include <pthread.h>
#include <errno.h>
#include <string.h>

void *func(void *arg)
{
	static int val = 20;
	int i = 0;
	while (i != 3)
	{
		printf("hello world\n");
		i++;
	}
	printf("val: %p\n", &val);

	pthread_exit(&val);
}

int main(void)
{

	int ret, ret2;
	int *pval = NULL;
	pthread_t tid;
	ret = pthread_create(&tid, NULL, func, NULL);
	
	if (ret != 0)
	{
		fprintf(stderr, "thread creat fail");
		return -1;
	}
	printf("main\n");

	// 修改 pval 的值, 所以传地址而非传值
	ret2 = pthread_join(tid, (void **)&pval);
	if (ret != 0)
	{
		fprintf(stderr, "join %s\n", strerror(errno));
		return -1;
	}

	printf("pval %p pval %d\n",pval, *pval);
	pthread_exit(NULL);

	return 0;
}
