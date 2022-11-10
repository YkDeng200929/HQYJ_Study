#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <string.h>
#include <sys/msg.h>

typedef struct 
{
	long type;//消息类型
	char buf[1024];//消息正文
}msg_t;//根据模板设计的结构体

#define MSG_LEN (sizeof(msg_t) - sizeof(long))//消息正文大小

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
	
	msg_id = msgget(key, IPC_CREAT | 0666);//得到消息队列id
	if(msg_id == -1)
	{
		perror("msgget");
		return -1;
	}
	msg.type = 100;//消息类型
	while(1)
	{
		memset(msg.buf, 0 ,sizeof(msg.buf));
		fgets(msg.buf, sizeof(msg.buf), stdin);
		ret = msgsnd(msg_id, &msg, MSG_LEN, 0);//发送消息
		if(ret == -1)
		{
			perror("msgsnd");
			return -1;
		}
		if(strncmp(msg.buf, "quit", 4) == 0)
		break;
	}
	if(msgctl(msg_id, IPC_RMID, NULL) < 0)//删除消息队列
	{
		perror("msgctl");
		return -1;
	}

	return 0;
}
