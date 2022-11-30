#include <iostream>
#include <list>

using namespace std;

int main(void)
{
	list<int> arr;
	arr.push_back(10);
	arr.push_back(20);
	arr.push_back(30);
	arr.push_back(40);
	arr.push_front(50);
	arr.push_front(60);
	arr.push_front(70);

	cout << "Orgin: " << endl;
	for (list<int>::iterator it = arr.begin(); it != arr.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
	
	cout << "After .remove(50): " << endl;
	arr.remove(50);
	for (list<int>::iterator it = arr.begin(); it != arr.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;

	cout << "After sort: " << endl;
	arr.sort();
	for (list<int>::iterator it = arr.begin(); it != arr.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;

	for (auto &i : arr)
	{
		cout << i << " ";
	}
	cout << endl;

	int arr2[] = {9,1,2,4,5};
	for (auto i : arr2)
	{
		cout << i << endl;
	}


	return 0;
}
