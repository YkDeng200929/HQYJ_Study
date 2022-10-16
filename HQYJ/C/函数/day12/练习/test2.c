//#include <stdio.h>
/*
#include <stdio.h>
void fun(int a[],int n,int flag)
{
	int i=0,j,t;
	for(i=0;i<n-1;i++)
		for(j=i+1;j<n;j++)
		if(flag)
		{
			if(a[i]<a[j])
			{
				t=a[i]; a[i]=a[j]; a[j]=t;
			}
		}
		else
		{
			if(a[i]>a[j])
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
}
void fun(int a[], int n, int flag)
{
    int i = 0, j, t;
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        if (flag)
        {
            if (a[i] < a[j])
            {
                t = a[i];
                a[i] =a[j];
                a[j] = t;
            }
        else
        {
            if (a[i] > a[j])
            {
                t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
        }
        }
    }
}

int main()
{
    int c[10] = {7,9,10,8,3,5,1,6,2,4};
    fun(c,4,1);
    fun(c+4,6,0);
    int i;
    for (i=0; i<10; i++)
        printf("%d ", c[i]);
    printf("\n");

    return 0;
}
*/
#include <stdio.h>

#define  N  4

int fun(int a[][N])
{
	int i,y=0;
	for(i=0;i<N;i++)
		y+=a[0][i]+a[N-1][i];     
	for(i=1;i<N-1;i++)
		y+=a[i][0]+a[i][N-1];    
	return y;
}

int main()
{
	int y,x[N][N]={{1,2,3,4},{2,1,4,3},{4,3,2,1}};
	y=fun(x);
	printf("%d",y);
}	