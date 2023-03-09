#include <iostream>
#include <cstdlib>
#include <ctime>

/*
namespace num 
{
    int result;
    int enter_num;
    int max = 100;
    int min = 0;
}
*/

using namespace std;
// using namespace num;

int main(void)
{
    int result;
    int enter_num;
    int max = 100;
    int min = 0;
    srand(time(NULL));
    result = rand() % 100;
    cout << "Enter: " << endl;

    do
    {
        cin >> enter_num;
        if (cin.fail())
        {
            cout << "error enter";
            return -1;
        }
        else if (enter_num > result)
        {
            // num::max = enter_num; // 命名空间一般不会这么用 
            max = enter_num; // 命名空间一般不会这么用 
            // cout << "lower than your enter " << num::min << " - " << num::max <<endl;
            cout << "lower than your enter " << min << " - " << max <<endl;
        }
        else  if (enter_num < result)
        {
            // num::min = enter_num;
            min = enter_num;
            // cout << "greater than your enter " << num::min << " - " << num::max << endl;
            cout << "greater than your enter " << min << " - " << max << endl;
        }
    } while (enter_num != result);
    
    cout << "graduate you are right num is " << enter_num << endl;

    return 0;
    
}