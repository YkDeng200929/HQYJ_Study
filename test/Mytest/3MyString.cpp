#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

class  MyString;

ostream& operator<<(ostream& outPut, const MyString& str);

class MyString
{
public:
    MyString(char *str);
    MyString(const MyString &str);
    ~MyString();

    bool operator==(const MyString& str);
    MyString operator+(const MyString& str);
    MyString operator++();
    MyString operator++(int);
    MyString operator=(const MyString& str);
    friend ostream& operator<<(ostream& outPut, const MyString& str);
private:
    char *m_data;
    int m_len;
};
MyString::MyString(char *str)
{
    if (NULL == str)
    {
        m_data = new char[1];
        m_data[0] = '\0';
        m_len = 0;
    }
    else
    {
        m_data = new char[strlen(str) + 1];
        strcpy(m_data, str);
        m_len = strlen(str);
    }
}
MyString::MyString(const MyString &str)
{
    m_data = new char[str.m_len + 1];
    strcpy(m_data, str.m_data);
    m_len = str.m_len;
}
MyString::~MyString()
{
    delete []m_data;
}

bool MyString::operator==(const MyString& str)
{
    return strcmp(m_data, str.m_data) == 0 ? true : false;
}
MyString MyString::operator+(const MyString& str)
{
    char *newStr = new char[m_len + str.m_len + 1];
    sprintf(newStr, "%s%s", m_data, str.m_data);
    MyString reStr(newStr);
    delete []newStr;
    
    return reStr;
}
MyString MyString::operator++()
{
    if (m_len == 0)
    {
        return *this;
    }
    else
    {
        for (int i = 0; i < m_len ; i++)
        {
            m_data[i]++;
        }
        return *this;
    }
}
MyString MyString::operator++(int)
{
    MyString tmp(*this);
    for (int i = 0; i < m_len ; i++)
    {
        m_data[i]++;
    }
    return tmp;
}
MyString MyString::operator=(const MyString& str)
{
    delete []m_data;
    m_data = new char[str.m_len + 1];
    strcpy(m_data, str.m_data);
    return *this;
}
ostream& operator<<(ostream& outPut, const MyString& str)
{
    outPut << str.m_data;
    return outPut;
}

int main(void)
{
    MyString str1("hello");
    MyString str2 = str1;
    str2++;

    cout << "str2: " << str2 << endl;
    cout << "str1: " << str1++ << endl;

    if (str1 == str2)
    {
        cout << "Equal" << endl;
    }
    else
    {
        cout << "EnEqual" << endl;
    }


    return 0;
}