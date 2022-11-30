#include <iostream>
/*
顺序表表内元素是通过index参数访问的,
表中的数据是不用重置的，可以但没必要
写成0意味着格式化
*/
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
SeqList<T>::SeqList(T size) : data(new T[size]), 
	size(size),
	index(0)
{

}

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
bool SeqList<T>::addData(T value)
{
	if (index >= size)
	{
		cout << "顺序表满" << endl;
		return false;
	}
	data[index] = value;
	index++;
	return true;
}

template <typename T>
bool SeqList<T>::delData()
{
	if (index <= 0)
	{
		return false;
	}
	--index;
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
