#include <stdio.h>
/*
	int arr[] = {23,41,10,26,16};
	low = 0  high = 4
	first = 0,last = 4


第一轮:
	first = 0,last = 4
	key = 23;
	23 41 10 26 16 ===> 16 41 10 26 16
	arr[last] = 16 小于 23 ,将这个值赋值给 first,arr[first] = arr[last]

	arr[first] = 16   16 < 23  ====> first++ ;arr[first] = 41   41 > 23

	first = 1,last = 3
	arr[last] = arr[first] ; 
	   f	 l
	16 41 10 26 41
	   f  l
	16 41 10 26 41  10 < 23 arr[first] = arr[last]
	      f l
	16 10 10 26 41  first = 2  last = 2 ,这一轮调整结束

	arr[first] = key
		  f l
	16 10 23 26 41

	排序:[0,first -1]  [last + 1,]
	

	

*/
void quickSort(int arr[], int low, int high)
{
	int first = low;
	int last  = high;

	int key = arr[first];//设置第1个数为 key,备份

	if(low >= high)
		return;
	//一轮的调整(比 key 大的放在右边, 比 key 小的放在左边)
	while(first < last)
	{
		//从右往左,找到比key 小的数放到 first 位置,找到比 key 大的数,继续往左移动
		while(first < last && arr[last] > key)
		{
			last--;
		}
		//将左边比基准值小的赋值到 last 索引位置
		arr[first] = arr[last];
		
		//从左往右,找到比 key 大的数放到 last 位置
		while(first < last && arr[first] < key)
		{
			first++;

		}
		//将右边比基准值大的赋值到 first 索引位置
		arr[last] = arr[first];

	}

	arr[first] = key;//一轮结束后

	quickSort(arr,low,first - 1);//对前面一半进行排序 ,low = 0 [0,first - 1]

	quickSort(arr,first + 1,high);//对后面一半进行排序,high = 4 [first + 1,4]
}

int main(void)
{
	int i;
	int arr[] = {23,41,10,26,16};
	
	quickSort(arr,0,4);
	
	for(i = 0;i < sizeof(arr)/sizeof(arr[0]);i++){
		printf(" %d ",arr[i]);
	}

	printf("\n");

	return 0;
}
