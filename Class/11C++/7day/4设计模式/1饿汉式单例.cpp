#include <iostream>
// 饿汉式单例

using namespace std;

class Hungry
{
public:
    static Hungry* GetInstance(void)
    {
        return s_hungry;
    }
    static void ReleaseInstance(void)
    {
        if (s_hungry != NULL)
        {
            delete s_hungry;
        }
    }
    static void show(void)
    {
        cout << "Hello World" << endl;
    }

private:
    Hungry(void)
    {
        cout << "创建一个单例" << endl;
    }
    ~Hungry(void)
    {
        cout << "释放一个单例" << endl;
    }
    static Hungry* s_hungry;
};

Hungry* Hungry::s_hungry = new Hungry;

int main(void)
{
    /* 程序一开始就创建了, 所以叫饿汉式
    Hungry* singleMan = Hungry::GetInstance();
    singleMan->show();
    singleMan->ReleaseInstance();
    */

    return 0;
}