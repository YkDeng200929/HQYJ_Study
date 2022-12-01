#include <iostream>
#include <pthread.h>
// 懒汉式单例

using namespace std;

class Lazy
{
public:
    static Lazy* GetInstance(void)
    {
        if (s_lazt != NULL)
        {
            return s_lazy;
        }

        // pthread_mutex_lock(&lock);
        if (s_lazy == NULL)
        {
            s_lazy = new Lazy;
        }

        // pthread_mutex_ulock(&lock);
        return s_lazy;
    }
    static void ReleaseInstance(void)
    {
        if (s_lazy != NULL)
        {
            delete s_lazy;
        }
    }
    static void show(void)
    {
        cout << "Hello World" << endl;
    }

private:
    Lazy(void)
    {
        cout << "创建一个单例" << endl;
    }
    ~Lazy(void)
    {
        cout << "释放一个单例" << endl;
    }
    static Lazy* s_lazy;
    // static pthread_mutex_t lock; // 线程安全解决方案
} // end of class Lazy;

Lazy* Lazy::s_lazy = NULL;
// pthread_mutex_t Lazy::lock = PTHREAD_MUTEX_INITIALIZER;

int main(void)
{

    Lazy* singleMan = Lazy::GetInstance();
    singleMan->show();
    singleMan->ReleaseInstance();

    return 0;
}