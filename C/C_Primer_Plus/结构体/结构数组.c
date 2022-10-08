#include <stdio.h>

struct linjian {
	char name[40];
	int size;
};

int main(void)
{
	struct linjian luosi[3] = {
		{"六号螺丝", 6},
		{"七号螺丝", 7},
		{"八号螺丝", 8}
	};

	for (int i = 0; i < 3; i++)
	{
		printf("%s %d\n", luosi[i].name, luosi[i].size);
	}

	return 0;
}
