#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/types.h>
#include <unistd.h>
#include <semaphore.h>

// 线程间共享全局变量
sem_t sem_id1, sem_id2;

// 线程的标识符为 tid (thread identifer)
// 编译文件时必须添加 -lpthread 参数

//3. 当线程间都需要访问同一个资源时会出现冲突, 此时需要给全局资源上锁
// 定义并初始化锁
pthread_mutex_t mutex =  PTHREAD_MUTEX_INITIALIZER;

//4. 当两个线程有供需关系时可用条件变量
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
// pthread_cond_wait() 条件满足时执行否则阻塞
// pthread_cond_signal() 唤醒至少一个阻塞的线程 
// pthread_cond_broadcast() 唤醒所有阻塞的线程
// pthread_cond_destroy() 用完后销毁条件变量

// 第一个线程要做的工作
void * work1(void *arg)
{
    // 循环是为了压榨线程, 让他不断的工作, 否则他只工作一次
    while(1)
    {
        // 2.2 tid1 先干活
        sem_wait(&sem_id1);
        // 3.3 当他干活时把要用的资源上锁, 不然两个家伙会打架(抢资源)
        // pthread_mutex_lock(&mutex)
        printf("tid1 working\n");
        // 别让他累死了
        sleep(1);
        // 3.3 用完后解锁, 让另一个线程用
        // pthread_mutex_unlock(&mutex)
        // 子线程死了没释放资源, 下面的join等着你死了给你收尸
        // 2.2 tid1 干完活了告诉 tid2 干活
        sem_post(&sem_id2);
    }
    pthread_exit(NULL);
}

// 第二个线程要干的活
void * work2(void *arg)
{
    while (1)
    {
        //2.3 让他先等着tid1把活干完
        sem_wait(&sem_id2);
        // 3.3 当他干活时把要用的资源上锁, 不然两个家伙会打架(抢资源)
        // pthread_mutex_lock(&mutex)
        printf("tid2 working\n");
        sleep(1);
        // 3.3 用完后解锁, 让另一个线程用
        // pthread_mutex_unlock(&mutex)
        //2.4 干完了再让tid1继续干, 不断压榨
        sem_post(&sem_id1);
    }
    pthread_exit(NULL);
}

int main(void)
{
    // 首先整个线程名吧 (得有个名字)
    pthread_t tid1, tid2;

    //1. pthread_create 创建一个线程 (告诉你想启用哪个线程, NULL(默认), 告诉线程要干啥事, 把工具(参数)给线程使用)
    pthread_create(&tid1, NULL, work1, NULL);

    // 阻塞的方式等待子线程退出
    //pthread_join(tid1, NULL);

    // 创建分离式线程( 这样就不用一直等线程死了(非阻塞)) 线程死了系统会自动回收资源
    // 标记成分离式线程
    pthread_detach(tid1);

    //2. sem_t 让两个线程同步的且有顺序的工作
    // 给两个线程不同的工号, 1表示先执行, 0表示等待工作直到收到信号(阻塞)
    // 应定义为全局变量
    sem_init(&sem_id1, 0, 1);
    sem_init(&sem_id2, 0, 0);
    pthread_create(&tid2, NULL, work2, NULL);

    // 看来得加上循环, 他会把 main 扫描完再执行线程, 先有进程再有线程(你进程都结束了哪来的线程?)
    while (1);
    //3. 用完锁记得毁掉
    pthread_mutex_destroy(&mutex);

    return 0;
}