#include <stdio.h>


void heap_sort(int arr[],int len);//堆排序
void adjust_heap(int arr[],int index,int length);//调整
void swap(int arr[],int a,int b);//交换

int main(void)
{
	int arr[] = {45,43,70,22,10};
	int i;
	heap_sort(arr,5);
	for (i = 0;i < 5;i++)
		printf(" %d ",arr[i]);

	printf("\n");

	return 0;
}

/*
	1.先构造堆(升序构造大顶堆,降序构造小顶堆),从最后一个非叶子节点开始,从右到左,从下到上依次进行调整整个堆
	2.堆的根节点与最后一个节点进行交换,调整堆符合堆结构,并且排序一个节点,则长度减1,剩下的节点继续参与交换并调整
*/
void heap_sort(int arr[],int len)
{
	int i,j;
	//第1步,构建堆,len / 2 - 1: 第1个非叶子节点编号(从右到左，从下往上)
	for (i = len / 2 - 1;i >= 0;i--)
	{
	    adjust_heap(arr,i,len);
	}

	//第2步,基于堆进行排序,len - 1 就是最后一个元素的编号
	for (j = len - 1;j > 0;j--)
	{
	   //当前堆的根节点与最后节点进行交换,就是将最大值交换到数组的最后(升序),这样每一次排序都有一个位置变成有序
       swap(arr,0,j);
	   //交换之后要堆重新进行调整,防止交换之后,对应堆结构被破坏(不符合大顶堆  or 小顶堆的规则)
	   adjust_heap(arr,0,j);
	}
}

/*
	调整大顶堆,仅是调整过程,建立在大顶堆已构建的基础上
	@param arr : 数组
	@param index : 堆顶节点的索引
	@param length : 堆的长度(节点的数量)
*/
void adjust_heap(int arr[],int index,int length)
{
	int temp = arr[index];
	int k ;//遍历当前堆的子树节点
	//整个循环要以当前堆的根节点为基准调整当前堆以及子树的堆,
	//要保证从左到右,从上到下调整整颗数包括子树的部分,以保证整颗树都是按照大顶堆或者小顶堆的规律排列
	for(k = index * 2 + 1;k < length;k = k * 2 + 1) //这里需要注意 k 的值变化时按照堆(完全二叉树)节点的编号进行调整,是2 * k + 1 进行变化
	{
		//比较左子节点小于右子节点,k 指向右子节点,保持 k 对应的节点为左/右节点最大值的节点
		if (k + 1 < length && arr[k] < arr[k + 1])
			k++;

		//当子节点的值大于当前堆的根节点时,则进行交换,如果交换之后,导致子树不符合堆的规则,还需要调整子树,否则,循环结束
		//这里注意始终与 temp 进行比较,有交换,temp 的值则交换到子树的根节点上,到调整子树时,还是与 temp 进行比较
		if(arr[k] > temp)
		{
			swap(arr,index,k);
			index = k;//这里主要是防止交换之后堆子树的影响,需要继续判断
		}
		else
			break;
	}

}

void swap(int arr[],int a,int b)
{
	int temp;
	temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}
