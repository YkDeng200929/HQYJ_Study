#ifndef CATWOMAN_H
#define CATWOMAN_H

#include "Hero.hpp"
#include "Assasin.hpp"
#include "Skin.hpp"

class CatWoman : public Hero, public Assasin
{
    public:
        CatWoman(const string &name) : Hero(name),
            Assasin(5),
            hero_skin("Pink Carnival"),
            level(10)
        {
            cout << "Create Cat Woman" << endl;
        }

        ~CatWoman()
        {
            cout << "Release Cat Woman" << endl;
        }

        void skill()
        {
            Hero::skill();
            cout << "skill: Savage Craw" << endl;
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