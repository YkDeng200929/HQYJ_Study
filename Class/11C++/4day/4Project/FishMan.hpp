#ifndef FISHMAN_HPP
#define FISHMAN_HPP

#include "Hero.hpp"
#include "Definder.hpp"
#include "Skin.hpp"

class FishMan : public Hero, public Definder
{
    public:
        FishMan(const string& name) : Hero(name), 
            Definder(10), 
            hero_skin("Blue Summer"), 
            level(6)
        {
            cout << "Create Fish Man" << endl;
        }

        ~FishMan()
        {
            cout << "Release Fish Man" << endl;
        }

        void skill()
        {
            Hero::skill(); // 调用父类的隐藏函数
            cout << "skill: Heavy hummer" << endl;
        }

        void show()
        {
            cout << "name: " << getName() << endl;
            cout << "level: " << level << endl;
            cout << "range: " << getRange() << endl;
            cout << "skin: " << hero_skin.getSkin() << endl;
        }
    private:
        Skin hero_skin;
        int level;
};

#endif