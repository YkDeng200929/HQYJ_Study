#include "Hero.hpp"
#include "FishMan.hpp"
#include "CatWoman.hpp"

void playGame(Hero &h)
{
    h.skill();
}

int main(void)
{
    FishMan hero("ykdeng");
    playGame(hero);

    cout << "-----------------------" << endl;
    CatWoman hero2("ykdeng2");
    playGame(hero2);
    

    return 0;
}