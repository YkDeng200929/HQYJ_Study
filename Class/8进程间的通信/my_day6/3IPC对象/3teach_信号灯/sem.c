#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/sem.h>

union semun {
	int		val;	/* Value for SETVAL */
	struct semid_ds *buf;	/* Buffer for IPC_STAT, IPC_SET */
	unsigned short  *array;	/* Array for GETALL, SETALL */
	struct seminfo  *__buf;	/* Buffer for IPC_INFO
							   (Linux-specific) */
};

//初始化信号灯的值函数的声明
int init_sem_vale(int sem_id,int sum_num,int val);

//初始化信号灯函数的声明
int init_semaphore(char *filenmae,int nsem);

//P操作申请资源操作的声明
void P(int sem_id,int sem_num);
//V操作申请资源操作的声明
void V(int sem_id,int sem_num);

//1.初始化信号灯函数的定义
//参数：
// @filenmae  fotk()函数创建key之对应的路径
// @nsem      创建信号灯集的个数,我们这里有两个资源一个表示读资源，一个表示
// 			  写资源
int init_semaphore(char *filename,int nsem)
{
	key_t key;
	int sem_id;

	key = ftok(filename,'k');
	if(key < 0){
		perror("Fail to ftok");
		exit(EXIT_FAILURE);
	}
	//第一个创建信号灯集的人，初始化信号灯的值
	sem_id = semget(key,nsem,IPC_CREAT | IPC_EXCL | 0666);

	//sem_id < 0 
	if(sem_id < 0){
		
		//信号灯集已经存在而出错
		if(errno == EEXIST){
			sem_id = semget(key,nsem,IPC_CREAT | 0666);
		
		}else{
			perror("Fail semget");
			exit(EXIT_FAILURE);
		}
	
	}else{//说明信号灯集不存在，自己创建了一个新的信号灯集
		
		//初始化信号灯的值
		init_sem_val(sem_id,0,0);//0表示读资源
		init_sem_val(sem_id,1,1);//1表示写资源
	}
	return sem_id;
}

//2.初始化信号灯集的值，创建0表示读资源，1表示写资源
//参数：@sem_id  信号灯的ID号
//      @sem_num 信号灯读写资源的编号
//      @val     初始化的信号灯的值
int init_sem_val(int sem_id,int sem_num,int val)
{
	union semun  sem; 

	sem.val = val;
	
	if(semctl(sem_id,sem_num,SETVAL,sem) < 0)
	{
		perror("Fail semctl");
		exit(EXIT_FAILURE);
	}

	return 0;
}

//3.P操作，申请资源 信号灯资源为-1
//参数：@semid  信号灯的ID号
//      @sem_num 要操作信号灯的编号。 读为0，写为1
void P(int sem_id,int sem_num)
{
	struct sembuf sem;
	sem.sem_num = sem_num; //填充操作的信号灯
	sem.sem_op = -1; //P操作，释放资源
	sem.sem_flg = 0;  //阻塞操作

	if(semop(sem_id,&sem,1) < 0)
	{
		perror("Fail to semop");
		exit(EXIT_FAILURE);
	}

	return ;
}

//4.V操作，释放资源 信号灯资源为1
//参数：@semid  信号灯的ID号
//      @sem_num 要操作信号灯的编号。 读为0，写为1
void V(int sem_id,int sem_num)
{
	struct sembuf sem;
	sem.sem_num = sem_num; //填充操作的信号灯
	sem.sem_op = 1; //P操作，释放资源
	sem.sem_flg = 0;  //阻塞操作

	if(semop(sem_id,&sem,1) < 0)
	{
		perror("Fail to semop");
		exit(EXIT_FAILURE);
	}

	return ;
}
