#ifndef _POINTER_HPP
#define _POINTER_HPP

#include <iostream>

using namespace std;

class Pointer
{
public:
    Pointer(const string& m_data = "default") : m_data(m_data)
    {
        cout << "构造函数" << endl;
    }
    ~Pointer(void)
    {
        cout << "析构函数" << endl;
    }
    void show(void)
    {
        cout << m_data << endl;
    }

private:
    string m_data;
};

#endif