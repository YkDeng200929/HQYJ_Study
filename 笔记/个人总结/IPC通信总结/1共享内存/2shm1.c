#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main(void)
{
    // 1. 得有钥匙 key(ftok获取), 才能去前台(shmget)拿到钥匙
    key_t key;
    int shm_id;

    key = ftok("/", 'a');
    printf("key: %#x\n", key);

    // 创建共享内存 (把钥匙给前台, 然后前台给你的 ID 身份, 辨识你是谁, 
    // 不然另一个进程不知道你要传递的东西在哪)
    shm_id = shmget(key, 4096, IPC_CREAT|0666);
    if (shm_id == -1)
    {
        perror("shmget");
        return -1;
    }

    // 映射共享内存 (把 ID 身份给 @ 并申请使用的空间大小, 申请成功后他把地址给你,
    // 你就能用这块地址传递信息了)
    char *buf = NULL;
    buf = shmat(shm_id, NULL, 0);
    if (buf == (void *)-1)
    {
        perror("shmat");
        return -1;
    }

    *buf = 10;
    buf[1] = 'a';

    printf("%d %c", *buf, buf[1]);
    getchar();

    // 撤销共享内存 (用完后把地址给 dt 申请注销土地)
    if (shmdt(buf) < 0)
    {
        perror("shmdt");
        return -1;
    }

    // 删除共享内存 (注销成功后管理员 ctl 彻底销毁你的身份 ID 完成消息共享)
    if (shmctl(shm_id, IPC_RMID, NULL) < 0)
    {
        perror("shmdt");
        return -1;
    }

    return 0;
}