#include <stdio.h>
#include <pthread.h>

// 需要链接线程库
// gcc <文件> -lpthread && ./a.out

struct student
{
	char name[20];
	int age;
	int score;
};

// 让线程执行的工作
void *func(void *arg)
{
	struct student stu = *(struct student *)arg;// 获得传过来的val的值
	printf("hello world, name: %s, age: %d, score: %d\n", stu.name, stu.age, stu.score);
}


int main(void)
{

	int ret;
	int val = 20;
	// 创建线程号
	pthread_t tid;
	struct student stu = {"ykdeng", 18, 100};
	
	// 创建一个线程并创建线程函数
	ret = pthread_create(&tid, NULL, func, &stu);

	if (ret != 0)
	{
		fprintf(stderr, "thread creat fail");
		return -1;
	}

	while (1);

	return 0;
}
