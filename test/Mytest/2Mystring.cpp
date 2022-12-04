#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

class MyString;

ostream& operator<<(ostream &outPut, const MyString &str);

class MyString
{
public:
    MyString(char *data);
    MyString(const MyString &other);
    ~MyString();

    void Show();
    bool operator==(const MyString &str);
    MyString operator+(const MyString &str);
    MyString operator=(const MyString &str);
    MyString operator++();
    MyString operator++(int);
    friend ostream& operator<<(ostream &outPut, const MyString &str);
private:
    char *m_data;
    int m_len;
};

MyString::MyString(char *data)
{
    if (NULL == data)
    {
        m_data = new char[1];
        m_data[0] = '\0';
        m_len = 0;
    }
    else
    {
        m_data = new char[strlen(data) + 1];
        strcpy(m_data, data);
        m_len = strlen(data);
    }
}
MyString::MyString(const MyString &other)
{
    m_data = new char[other.m_len + 1];
    strcpy(m_data, other.m_data);
    m_len = other.m_len;
}
MyString::~MyString()
{
    delete []m_data;
}

void MyString::Show()
{
    cout << m_data << endl;
}

bool MyString::operator==(const MyString &str)
{
    return strcmp(m_data, str.m_data) == 0 ? true : false;
}

MyString MyString::operator+(const MyString &str)
{
    char *newStr = new char[m_len + str.m_len + 1];
    sprintf(newStr, "%s%s", m_data, str.m_data);
    MyString reStr(newStr);

    delete newStr;
    return reStr;
}
MyString MyString::operator=(const MyString &str)
{
    delete m_data;
    m_data = new char[str.m_len + 1];
    strcpy(m_data, str.m_data);
    return *this;
}
MyString MyString::operator++()
{
    if (m_len == 0)
    {
        return *this;
    }
    else
    {
        for (int i = 0; i < m_len; i++)
        {
            m_data[i]++;
        }
        return *this;
    }
}
MyString MyString::operator++(int)
{
    MyString tmp(*this);
    for (int i = 0; i < m_len; i++)
    {
        m_data[i]++;// 这里前置++与后置++无关紧要，因为cout出来的字符串还是tmp，而tmp是++之前的对象本身
    }
    return tmp;
}

ostream& operator<<(ostream &outPut, const MyString &str)
{
    outPut << str.m_data;
    return outPut;
}

int main(void)
{
    MyString str1("hello");
    MyString str2("world");

    str1.Show();
    if (str1 == str2)
    {
        cout << "Equal" << endl;
    }
    else
    {
        cout << "Enequal" << endl;
    }

    MyString str3 = str1 + str2;
    str3.Show();
    cout << str3++ << endl;

    return 0;
}