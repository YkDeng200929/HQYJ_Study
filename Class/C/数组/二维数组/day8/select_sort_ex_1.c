#include <stdio.h>
#include <string.h>

int main()
{
	char a[] = "edbca";
	int len = strlen(a);
	int i = 0, j = 0, n = 0;
	char max, temp;

	for(i = 0; i < len - 1; i++)
	{
		max = a[i];
		n = i;
		for(j = i + 1; j < len; j++)
		{
			if(max < a[j])
			{
				max = a[j];
				n = j;
			}
		}
		if(n != i)
		{
			temp = a[n];
			a[n] = a[i];
			a[i] = temp;
		}
	}
	puts(a);

	return 0;
}
