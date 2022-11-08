#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

struct datas
{
	int int_data;
	short short_data;
	char char_data;
};//定义一个结构体类型

int global = 10;
void *func1(void *arg)//线程执行函数1
{
	struct datas *pdat1 = (struct datas *)arg;
	pdat1->int_data = 20;
	pdat1->short_data = 40;
	pdat1->char_data = 60;

	while(1)
	{
		sleep(1);
		printf("int_data = %d short_data = %d char_data =%d\n",pdat1->int_data,pdat1->short_data, pdat1->char_data);//打印结构体变量的值
		global++;//全局变量值++
	}

}

void *func2(void *arg)//线程执行函数2
{
	while(1)
	{
		sleep(1);
		printf("global = %d data = %d\n",global, (*(int *)arg)++);//打印全局变量和data的值，并将data的值++
	}

}


int main()
{
	int ret;
	int data = 10;
	struct datas dat1;
	pthread_t tid1,tid2;//线程id
	ret = pthread_create(&tid1, NULL, func1, &dat1);//创建线程函数
	if(ret != 0)
	{
		fprintf(stderr, "thread 1 create fail");
		return -1;
	}
	ret = pthread_create(&tid2, NULL, func2, &data);//创建线程函数
	if(ret != 0)
	{
		fprintf(stderr, "thread 2 create fail");
		return -1;
	}
	while(1)
	{
		printf("main running: data = %d\n", data);
		sleep(1);
	}
	exit(EXIT_SUCCESS);
	return 0;
}
