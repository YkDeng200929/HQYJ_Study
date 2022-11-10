#include <stdio.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <errno.h>
#include <stdlib.h>
#include <signal.h>

#define PROJ_ID 'k'
#define SHM_SZ  4096

//./read /home/ubuntu
int main(int argc, const char *argv[])
{
	int shmid = 0;
	char *paddr;
	key_t key;
	pid_t pid = 0;
	int semid = 0;

	if(argc < 2)
	{
		fprintf(stderr,"Usage : %s argv[1].\n",argv[0]);	
		exit(EXIT_FAILURE);
	}

	key = ftok(argv[1],PROJ_ID);
	if(key < 0)
	{
		perror("Fail to shmget");			
		exit(EXIT_FAILURE);
	}

	//创建共享内存
	shmid = shmget(key,SHM_SZ,IPC_CREAT | 0666);
	if(shmid < 0)
	{
		perror("Fail to shmget");	
		exit(EXIT_FAILURE);
	}
	//将共享内存映射进进程的虚拟地址空间
	paddr = (char *)shmat(shmid,NULL,0);
	if(paddr == (char *)-1)
	{
		perror("Fail to shmat");	
		exit(EXIT_FAILURE);
	}

	//初始化信号灯集，创建0和1两个读写资源
	semid = init_semaphore(argv[1],2);
	semid = init_semaphore(argv[1],2);

	//获得共享内存映射到当前进程的地址
	//向共享内存中写入数据
	while(1)
	{
		//申请写资源
		P(semid,1);

		putchar('>');
		fgets(paddr,SHM_SZ,stdin);
		paddr[strlen(paddr) - 1] = '\0';

		//释放写资源
		V(semid,0);
		if(strncmp(paddr,"quit",4) == 0)
			break;

	}
	//解除映射
	if(shmdt(paddr) < 0)	
	{
		perror("Fail to shmdt");		
		exit(EXIT_FAILURE);
	}

	//由于输入了quit，read进程会删除共享内存，写进程不需要删除了
	return 0;
}

