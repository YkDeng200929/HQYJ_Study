#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>

int main(void)
{
    key_t key;
    key = ftok("/", 'a');

    printf("key: %d\n", key);
    printf("key: %#x\n", key);

    return 0;
}