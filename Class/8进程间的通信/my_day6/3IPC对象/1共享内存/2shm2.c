#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main(void)
{
    key_t key;
    int shm_id;

    key = ftok("/", 'a');
    printf("key: %#x\n", key);

    // 创建共享内存
    shm_id = shmget(key, 4096, IPC_CREAT|0666);
    if (shm_id == -1)
    {
        perror("shmget");
        return -1;
    }

    // 映射共享内存
    char *buf = NULL;
    buf = shmat(shm_id, NULL, 0);
    if (buf == (void *)-1)
    {
        perror("shmat");
        return -1;
    }

    // 因为是共享内存, 所以会得到共享内存中的值
    printf("%d %c", *buf, buf[1]);
    getchar();

    // 撤销共享内存
    if (shmdt(buf) < 0)
    {
        perror("shmdt");
        return -1;
    }

    // 删除共享内存
    if (shmctl(shm_id, IPC_RMID, NULL) < 0)
    {
        perror("shmdt");
        return -1;
    }

    return 0;
}