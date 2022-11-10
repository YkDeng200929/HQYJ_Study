#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <errno.h>
#include <string.h>

// 1. 创建需传递的消息正文
typedef struct
{
    long type;
    char msgbuf[1024];
} msg_t;

// 2. 定义消息正文的长度
#define MSG_LEN (sizeof(msg_t) - sizeof(long))

int main(void)
{
    int msgid, ret;
    msg_t msg;
    key_t key;
    key = ftok("/", 'a');
    if (key == -1)
    {
        perror("ftok");
        return -1;
    }
    // 3. 创建消息队列
    msgid = msgget(key, IPC_CREAT|0666);
    // 记得设置 消息类型
    msg.type = 100;
    if (msgid == -1)
    {
        perror("msgget");
        return -1;
    }

    // 4. 发送消息
    while (1)
    {
        memset(msg.msgbuf, 0, sizeof(msg.msgbuf));
        fgets(msg.msgbuf, sizeof(msg.msgbuf), stdin);       
        ret = msgsnd(msgid, &msg, MSG_LEN, 0);
        if (ret == -1)
        {
            perror("msgsnd");
            return -1;
        }
        if (strncmp(msg.msgbuf, "quit", 4) == 0)
        {
            msgctl(msgid, IPC_RMID, NULL);
        }
    }

    return 0;
}