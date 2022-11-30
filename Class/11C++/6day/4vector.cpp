#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    vector<int> vArr;
    vArr.push_back(10);
    vArr.push_back(20);
    vArr.push_back(30);
    vArr.push_back(40);
    vArr.push_back(50); // 尾插
    vArr.pop_back(); // 尾删
    vArr.push_back(30);
    vArr.push_back(30);

    for (int i = 0; i < vArr.size(); ++i) // 获取vector大小
    {
        //cout << vArr.at(i) << " ";
        cout << vArr[i] << " "; // 访问元素
    }

    cout << endl;
    cout << "----------------" << endl;
    // 迭代器
    // !!! 迭代器的遍历与删除

    vector<int>::iterator it = vArr.begin(); // 迭代器的遍历与删除
    for (; it != vArr.end();)
    {
        if (*it == 30)
        {
            vArr.erase(it);
			continue;
        }
		++it;
    }

    for (int i = 0; i < vArr.size(); ++i)
    {
        cout << vArr[i] << " "; // 访问数组元素
    }
    cout << endl;
	// vArr.empty(); 容器判空
	// it == vArr.end(); 迭代器判空

    return 0;
}
