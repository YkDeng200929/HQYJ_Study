#include <iostream>

using namespace std;

class Animal
{
    public:
    void eat(string food)
    {
        cout << name << " is eating " << food << endl;
    }

    string get_name()
    {
        return name;
    }

    bool set_animal(const string& animal_name, const string& animal_type)
    {
        name = animal_name;
        type = animal_type;

        return true;
    }

    private:
    string name;
    string type;
};

int main(void)
{
    Animal my_cat;
    my_cat.set_animal("ykdeng", "cat");
    cout << my_cat.get_name() << endl;
    my_cat.eat("hum");

    return 0;
}