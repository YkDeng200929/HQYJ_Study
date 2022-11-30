#ifndef DEFINDER_H
#define DEFINDER_H

#include <iostream>

using namespace std;

class Definder
{
    public:
        Definder(int range) : range(range)
        {
            cout << "Create Definder" << endl;
        }
        ~Definder()
        {
            cout << "Release Definder" << endl;
        }
        int getRange() const
        {
            return range;
        }

    private:
        int range;
};

#endif