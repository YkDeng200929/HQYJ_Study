#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

void test(int *option)
{
	scanf("%d", option);
	getchar();
}

int main(void)
{
	int option = 1;
	printf("org: %d\n", option);
	test(&option);
	printf("after: %d\n", option);



	return 0;
}
