#ifndef HERO_HPP
#define HERO_HPP

#include <iostream>

using namespace std;

class Hero
{
    public:
        Hero(const string& name) : name(name)
        {
            cout << "Create Hero" << endl;
        }

        ~Hero()
        {
            cout << "Release hero" << endl;
        }

        virtual void skill()
        {
            cout << name << ": Use skill~" << endl;
        }

        string getName() const
        {
            return name;
        }
    private:
        string name;
};

#endif
