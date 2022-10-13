/*
1、有以下程序：
#include <stdio.h>
int f(int x);
int main()
{
	int n=1,m;
	m=f(f(f(n)));
	printf("%d\n",m);
	return 0;
}

int f(int x)
{
	return x*2;
}
程序运行后输出结果是：8



//2、有以下程序：
#include <stdio.h>
void fun(int a[],int n)
{
	int i,t;
	for(i=0;i<n/2;i++)//第 1 2 3
	{
		t=a[i];
		a[i]=a[n-1-i];// 交换
		a[n-1-i]=t;
	}
}

int main()
{
	int k[10]={1,2,3,4,5,6,7,8,9,10},i;
	fun(k,5);
	for(i=2;i<8;i++)
		printf("%d ",k[i]);//第3 4 5 6 7
	printf("\n");
}
//程序运行结果是：3 2 1 6 7 8



3、以下程序的输出结果是 4
#include <stdio.h>
int fun2(int a,int b)
{
	int c;
	c=(a*b)%3;
	return c;
}

int fun1(int a,int b)
{
	int c;
	a+=a;
	b++;
	c=fun2(a,b);
	return c*c; // c=2
}

int main(void)
{
	int x=11,y=19;
	int ret;
	ret=fun1(x,y);
	printf("%d\n",fun1(x,y));
}



//4、有以下程序：
#include <stdio.h>
void fun(char **p)
{
	++p; 
	printf("%s\n",*p);
}
int main()
{	
	char *a[4]={"Morning","Afternoon","Evening","Night"};
	fun(a);

	return 0;
}
//程序运行结果是：（B）
//A  Morning		B  Afternoon		C  orning		D  Evening



//5、有以下程序：
#include <stdio.h>
#define N 4
void fun(int a[][N],int b[])
{
	int i;
	for(i=0; i<N; i++) 
		b[i]= a[i][i]-a[i][N- 1- i];// 将数组y的元素进行处理
}
int main()
{ 
	int x[N][N]={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}},y[N],i;
	fun(x,y);
	for(i=0; i<N; i++) 
		printf("%d, ",y[i]);
	printf("\n");

	return 0;
}
//程序运行后的输出结果是:-3 -1 1 3



//6、有以下程序：
#include <stdio.h>
int f(int x,int y)
{return ((y-x)*x);}

int main()
{
	int a=3,b=4,c=5,d;
	d=f(f(a,b),f(a,c));
	printf("%d\n",d);

	return 0;
}
//程序运行后的输出结果是：9



//7、有以下程序：
#include <stdio.h>
void fun(int a[],int n,int flag)
{
	int i=0,j,t;
	for(i=0;i<n-1;i++)      // 对一维数组的前n个元素进行排序操作
		for(j=i+1;j<n;j++)
		if(flag)            // 大前小后
		{
			if(a[i]<a[j])
			{
				t=a[i]; a[i]=a[j]; a[j]=t;
			}
		}
		else
		{
			if(a[i]>a[j])	// 小前大后
			{
				t=a[i]; a[i]=a[j]; a[j]=t;
			}
		}
}

int main()
{
	int c[10]={7,9,10,8,3,5,1,6,2,4},i;
	fun(c,4,1);
	fun(c+4,6,0);
	for(i=0;i<10;i++)
		printf("%d,",c[i]);
	printf("\n");

	return 0;
}
//程序运行后的输出结果是：10 9 8 7 1 2 3 4 5 6



//8、有以下程序：
#include <stdio.h>

int m1(int x,int y)
{
	if(x<=y)return 2*x+1;
	else return y;
}

int m2(int x,int y)
{
	if(x<=y)return 2*y+1;
	else  return x;
}

int main()
{
	int i,t1=10,t2=0;
	for(i=1;i<=4;i++)
	{
		t1=m1(i,t1); t2=m2(i,t2);
	}
	printf("t1=%d t2=%d\n",t1,t2);
}
//程序运行后的输出结果是：9 4
*/
//9、有以下程序：
#include <stdio.h>

#define  N  4

int fun(int a[][N])
{
	int i,y=0;
	for(i=0;i<N;i++)
		y+=a[0][i]+a[N-1][i];     // 第1行每个元素的值 + 第三行每个元素的值 += 优先级大于 +？
	for(i=1;i<N-1;i++)
		y+=a[i][0]+a[i][N-1];    // 每行第1列的值 + 每行第4列的值
	return y;
}

int main()
{
	int y,x[N][N]={{1,2,3,4},{2,1,4,3},{4,3,2,1}};
	y=fun(x);
	printf("%d",y);
}	
//程序运行后的输出结果是：35


10、有以下程序：
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
程序运行后的输出结果是：
*/