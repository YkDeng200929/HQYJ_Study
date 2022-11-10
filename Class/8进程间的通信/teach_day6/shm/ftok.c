#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>

int main()
{
	key_t key;

	key = ftok("/home/linux",'d');
	if(key == -1)
	{
		perror("ftok");
		return -1;
	}
	printf("key = %d\n", key);
	printf("key = %#x\n", key);
	return 0;
}
