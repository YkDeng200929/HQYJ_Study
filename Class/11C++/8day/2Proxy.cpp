#include <iostream>

using namespace std;

class House
{
public:
    virtual void GetHouse() = 0;
}; // end of class House

class HouseOwner : public House
{
public:
    virtual void GetHouse(void)
    {
        cout << "Rent House" << endl;
    }
}; // end of class HouseOwner

class Proxy : public House
{
public:
    Proxy(HouseOwner *houseOwner) : m_houseOwner(houseOwner) {;}

    ~Proxy()
    {
        if (m_houseOwner != NULL)
        {
            delete m_houseOwner;
        }
    }

    virtual void GetHouse(void)
    {
        cout << "Get Owner house" << endl;
    }
private:
    HouseOwner *m_houseOwner;
}; // end of class Proxy

int main(void)
{
    Proxy *proxy = new Proxy(new HouseOwner);
    proxy->GetHouse();

    return 0;
}