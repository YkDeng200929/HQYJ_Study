#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>

using namespace std;

class myString;

ostream& operator<<(ostream& out, const myString& str);

class myString
{
    public:
        myString(const char *value = NULL);// 构造函数
        myString(const myString& other);// 拷贝构造函数(深拷贝)
        ~myString();// 析构函数
        void show();
        static myString fromNum(int i);// 静态函数
        bool operator==(const myString& str);
        myString operator+(const myString& str);
        myString& operator=(const myString& str);
        myString& operator++();     // 前置++
        myString operator++(int);   // 后置++
        friend ostream& operator<<(ostream& out, const myString& str);

    private:
        char *data; // 记录字符串内容
        int len;    // 记录字符串长度
};

myString::myString(const char *value)
{
    if (value == NULL)
    {
        data = new char[1];
        data[0] = '\0';
        len = 0;
        return ;
    }
    len = strlen(value);
    data = new char[len + 1]; // +1是为了补'\0'
    strcpy(data, value);
}

myString::myString(const myString& other) : len(other.len)
{
    data = new char[len + 1]; // +1是为了补'\0'
    strcpy(data, other.data); // 复制一个空间, 深拷贝
}

myString::~myString()// 析构函数
{
    delete []data;
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

bool myString::operator==(const myString& str)
{
    if (strcmp(str.data, data) == 0)
    {
        return true;
    }
    else
        return false;
}

myString myString::operator+(const myString& str)
{
    char *new_str = new char[str.len + len + 1];
    sprintf(new_str, "%s%s", data, str.data);
    myString re_str(new_str);

    delete []new_str;
    return re_str;
}

myString& myString::operator=(const myString& str)
{
    if (this == &str)
    {
        return *this;
    }

    delete []data;
    data = new char[str.len + 1];
    strcpy(data, str.data);
    len = str.len;
    return *this;
}

myString& myString::operator++()
{
    if (this->len == 0)
    {
        return *this;
    }
    else
    {
        for (int i = 0; i < this->len; i++)
        {
            data[i] += 3;
        }
        return *this;
    }
}
myString myString::operator++(int)
{
    myString tmp(*this);
    for (int i = 0; i < tmp.len; i++)
    {
        ++data[i];
    }
    return tmp;
}

ostream& operator<<(ostream& out, const myString& str)
{
    out << str.data;
    return out;
}

int main(void)
{
    myString str("hello");
    myString str2("world");
    if (str == str2)
    {
        cout << "equal" << endl;
    }
    else
        cout << "enequal" << endl;
    myString str3 = str + str2;
    cout << str << endl;
    cout << str2 << endl;
    cout << "str3 org: " << str3 << endl;
    cout << "++str3: " << ++str3 << endl;
    cout << "str3++: " << str3++ << endl;
    cout << "str3 after ++: " << str3 << endl;

    return 0;
}