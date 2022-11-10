#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <string.h>
#include <sys/msg.h>

typedef struct 
{
	long type;
	char buf[1024];
}msg_t;

#define MSG_LEN (sizeof(msg_t) - sizeof(long))

int main()
{
	int ret, msg_id;
	key_t key;
	msg_t msg;
	key = ftok("/home/linux",'d');
	if(key == -1)
	{
		perror("ftok");
		return -1;
	}
	printf("key = %#x\n", key);
	
	msg_id = msgget(key, IPC_CREAT | 0666);
	if(msg_id == -1)
	{
		perror("msgget");
		return -1;
	}
	while(1)
	{
		memset(msg.buf, 0 ,sizeof(msg.buf));
		ret = msgrcv(msg_id, &msg, MSG_LEN, 100, 0);//接收指定类型的消息
		if(ret == -1)
		{
			perror("msgsnd");
			return -1;
		}

		if(strncmp(msg.buf, "quit", 4) == 0)
		break;
		printf("msg.buf : %s\n", msg.buf);
	}

	return 0;
}
