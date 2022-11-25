#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

class myString
{
    public:
        myString(const char *value = NULL);// 构造函数
        myString(const myString& other);// 拷贝构造函数(深拷贝)
        ~myString();// 析构函数
        void show();
        static myString fromNum(int i);// 静态函数

    private:
        char *data; // 记录字符串内容
        int len;    // 记录字符串长度
};

myString::myString(const char *value)
{
    if (value == NULL)
    {
        data = NULL;
        len = 0;
        return ;
    }
    len = strlen(value);
    data = new char[len + 1]; // +1是为了补'\0'
    strcpy(data, value);
}

myString::myString(const myString& other) : len(other.len)
{
    if (len == 0)
    {
        data = NULL;
        return ;
    }
    data = new char[len + 1]; // +1是为了补'\0'
    strcpy(data, other.data); // 复制一个空间, 深拷贝
}

myString::~myString()// 析构函数
{
    if (data != NULL)
    {
        delete []data;
    }
}

void myString::show()
{
    cout << data << endl;
}

myString myString::fromNum(int i)
{
    char buf[20] = {0};
    sprintf(buf, "%d", i);

    return myString(buf);// <===>myString str(buf); return str;
}

int main(void)
{
    myString str("hello");
    myString str2 = str;
    str2.show();
    myString str3 = myString::fromNum(8765);
    str3.show();

    return 0;
}