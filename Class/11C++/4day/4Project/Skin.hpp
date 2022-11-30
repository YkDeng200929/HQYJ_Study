#ifndef SKIN_HPP
#define SKIN_HPP

#include <iostream>

using namespace std;

class Skin
{
    public:
        Skin(const string& skinName) : skinName(skinName)
        {
            cout << "Create Skin" << endl;
        }
        ~Skin()
        {
            cout << "Release Destroy Skin" << endl;
        }
        string getSkin() const
        {
            return skinName;
        }

    private:
        string skinName;
};

#endif