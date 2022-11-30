#include <iostream>

using namespace std;

template <typename T>
class SeqList
{
public:
	SeqList(T size);
	~SeqList();

	bool addData(T value);  // 尾插法
	bool delData(); 		// 尾删法
	void show(); 			// 打印顺序表内所有数据
	void clear(); 			// 清空顺序表内所有顺序

private:
	T *data; 	// 数据
	int size; 	// 数组大小
	int index; 	// 记录当前有多少数据
};
template <typename T>
SeqList<T>::~SeqList()
{
	if (data == NULL){;}
	else
	{
		delete []data;
	}
}

template <typename T>
SeqList<T>::SeqList(T size) : size(size)
{
	data = new int [size];
}

template <typename T>
bool SeqList<T>::addData(T value)
{
	if (index == size && index != 0)
		return false;
	data[index] = value;
	index++;
	return true;
}

template <typename T>
bool SeqList<T>::delData()
{
	if (index == 0)
	{
		return false;
	}
	data[index] = 0;
	index--;
	return true;
}

template <typename T>
void SeqList<T>::show()
{
	for (int i = 0; i < index; i++)
	{
		cout << data[i] << " ";
	}
	cout << endl;
}

template <typename T>
void SeqList<T>::clear()
{
	for (int i = 0; i < index; i++)
	{
		data[i] = 0;
	}
	index = 0;
}

int main(void)
{
	SeqList<int> sqlist(5);
	cout << "Add: ";
	for (int i = 0; i < 5; i++)
	{
		sqlist.addData(i);
	}
	sqlist.show();
	cout << "del one data: ";
	sqlist.delData();
	sqlist.show();
	cout << "del one data again: ";
	sqlist.delData();
	sqlist.show();
	cout << "clearing all data..." << endl;
	sqlist.clear();
	cout << "after clear: ";
	sqlist.show();


	return 0;
}
