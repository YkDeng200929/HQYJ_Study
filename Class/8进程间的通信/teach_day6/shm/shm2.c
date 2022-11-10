#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main()
{
	key_t key;
	int shm_id;
	char *paddr;
	key = ftok("/home/linux",'d');
	if(key == -1)
	{
		perror("ftok");
		return -1;
	}
	printf("key = %#x\n", key);
	
	shm_id = shmget(key, 4096, IPC_CREAT|0666);
	if(shm_id == -1)
	{
		perror("shmget");
		return -1;
	}
	
	paddr = shmat(shm_id, NULL, 0);
	if(paddr == (void *) -1)
	{
		perror("shmat");
		return -1;
	}
	
	printf("*paddr = %d paddr[1] = %c\n",*paddr,paddr[1]);
	getchar();
	if(shmdt(paddr) < 0)
	{
		perror("shmdt");
		return -1;
	}

	if(shmctl(shm_id, IPC_RMID, NULL) < 0)
	{
		perror("shmctl");
		return -1;
	}
	return 0;
}
