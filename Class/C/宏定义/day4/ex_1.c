#include <stdio.h>

int main()
{
	printf("%c:%d\n", 'a', 'a');
	printf("%c:%d\n", 'm', 'm');

	printf("%f\n", 3.1415925);
	printf("%e\n", 314159.25);

	//'A' --> 'a'
	printf("%c : %d\n", ('A' + 32), 'A' + 32);

	//'1' --> 1
	printf("'1' --> %d\n", '1' - 48);
	
	return 0;
}
