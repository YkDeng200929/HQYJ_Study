#include <stdio.h>

int main()
{
	int data[] = {10, 20, 31, 40, 50, 62, 73};
	int *p_array[] = {&data[0], &data[1], &data[2], &data[3], &data[4], &data[5], &data[6], NULL};
	int **q = p_array;
	int new_array[10] = {0};
	int i = 0, j = 0, count = 0;

	for(i = 0; q[i] != NULL; i++)
	{
		if(0 == *(q[i]) % 2)
		{
			new_array[j++] = *(q[i]);
			count++;
		}
		//printf("%d ", *(q[i]));
	}

	printf("count:%d\n", count);
	for(i = 0; i < count; i++)
	{
		printf("%d ", new_array[i]);
	}
	putchar('\n');

	return 0;
}
