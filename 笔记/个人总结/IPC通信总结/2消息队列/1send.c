#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <errno.h>
#include <string.h>

// 创建需传递的消息正文
typedef struct
{
    long type; // 你得让另一个人知道哪个是你发的消息对吧, 相当于手机号
    char msgbuf[1024];
} msg_t;

// 定义消息正文的长度
#define MSG_LEN (sizeof(msg_t) - sizeof(long))

int main(void)
{
    int msgid, ret;
    msg_t msg;
    // 1. 拿到钥匙
    key_t key;
    key = ftok("/", 'a');
    if (key == -1)
    {
        perror("ftok");
        return -1;
    }
    // 2. 把钥匙给驿站你要传送的信是啥
    msgid = msgget(key, IPC_CREAT|0666);
    // 标记好你的手机号码, 让接收者知道是不是你
    msg.type = 100;
    if (msgid == -1)
    {
        perror("msgget");
        return -1;
    }

    // 3. 把信发送出去
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