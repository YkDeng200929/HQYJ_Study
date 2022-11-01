
#include <stdio.h>

void swap(int *pa,int *pb)
{
	int t;
	t=*pa;*pa=*pb;*pb=t;
}

void fun(int *ds,int n)
{
	int i,midx;
	midx=0;
	for(i=1;i<n;i++)
		if(ds[i]<ds[midx])midx=i;
	swap(ds,ds+midx);
}

int main()
{
	int data[]={37,31,26,17,61,12},i;
	for(i=0;i<5;i++)
		fun(data+i,6-i);
	for(i=0;i<6;i++)
		printf("%3d",data[i]);
	printf("\n");
}