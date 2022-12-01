#include <iostream>
#include <map>

using namespace std;

int main(void)
{
    map<int, string> info;
    info[1] = "xiaohong";
    info[2] = "xiaogang";
    info[3] = "Liming";

    map<int, string>::iterator it = info.begin();

    for (; it != info.end(); it++)
    {
        cout << "Id: " << it->first << " " <<
                "name: " << it->second << endl;
    }

    it = info.find(2);
    cout << "Find 2: " << it->second << endl;
    info.erase(2);

    cout << "After erase key 2: ---------------------" << endl;

    it = info.begin();
    for (; it != info.end(); it++)
    {
        cout << "Id: " << it->first << " " <<
                "name: " << it->second << endl;
    }


    return 0;
}