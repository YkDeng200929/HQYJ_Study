#include <iostream>
// ����ʽ����

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
        cout << "����һ������" << endl;
    }
    ~Hungry(void)
    {
        cout << "�ͷ�һ������" << endl;
    }
    static Hungry* s_hungry;
};

Hungry* Hungry::s_hungry = new Hungry;

int main(void)
{
    /* ����һ��ʼ�ʹ�����, ���Խж���ʽ
    Hungry* singleMan = Hungry::GetInstance();
    singleMan->show();
    singleMan->ReleaseInstance();
    */

    return 0;
}