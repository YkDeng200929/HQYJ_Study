#include <iostream>
/*
顺序表表内元素是通过index参数访问的,
表中的数据是不用重置的，可以但没必要
写成0意味着格式化
*/
using namespace std;

// 非类型参数
template <typename T, int size>
class SeqList
{
public:
	SeqList();
	~SeqList();

	bool addData(T value);  // 尾插法
	bool delData(); 		// 尾删法
	void show(); 			// 打印顺序表内所有数据
	void clear(); 			// 清空顺序表内所有顺序

private:
	T *data; 	// 数据
	int index; 	// 记录当前有多少数据
};
template <typename T, int size>
SeqList<T, size>::SeqList() : data(new T[size]), 
	index(0)
{

}

template <typename T, int size>
SeqList<T, size>::~SeqList()
{
	delete []data;
}


template <typename T, int size>
bool SeqList<T, size>::addData(T value)
{
	if (index >= size)
	{
		cout << "顺序表满" << endl;
		return false;
	}
	data[index++] = value;
	return true;
}

template <typename T, int size>
bool SeqList<T, size>::delData()
{
	if (index <= 0)
	{
		return false;
	}
	--index;
	return true;
}

template <typename T, int size>
void SeqList<T, size>::show()
{
	for (int i = 0; i < index; i++)
	{
		cout << data[i] << " ";
	}
	cout << endl;
}

template <typename T, int size>
void SeqList<T, size>::clear()
{
	index = 0;
}

int main(void)
{
	SeqList<int, 5> sqlist;
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
