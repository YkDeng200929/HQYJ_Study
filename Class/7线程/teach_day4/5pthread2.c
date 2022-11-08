#include <stdio.h>
#include <pthread.h>

struct student
{
	char name[16];
	int id;
	int score;
};//定义一个结构体类型
void *func(void *arg)//线程执行函数
{
	struct student stu = *(struct student *)arg;//获得传过来的value的值
	printf("name : %s  id: %d  score: %d\n",stu.name, stu.id, stu.score);
	printf("thread 1\n");

}
int main()
{
	int ret;
	int value = 20;
	pthread_t tid;//线程id
	struct student stu1 = {"henry", 1, 80};	
	ret = pthread_create(&tid, NULL, func, &stu1);//创建线程函数
	if(ret != 0)
	{
		fprintf(stderr, "thread 1 create fail");
		return -1;
	}
	while(1);
	return 0;
}
