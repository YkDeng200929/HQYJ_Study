#ifndef ASSASIN_H
#define ASSASIN_H

#include <iostream>

using namespace std;

class Assasin
{
    public:
        Assasin(int range) : range(range)
        {
            cout << "Create Assasin" << endl;
        }
        ~Assasin()
        {
            cout << "Release Assasin" << endl;
        }
        int getRange() const
        {
            return range;
        }


    private:
        int range;
};

#endif