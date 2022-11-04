#include <stdio.h>

int main(void)
{
	FILE *fp;
	fp = fopen("org.txt", "r");
	char buf[8] = {0};
	fgets(buf, 8, fp);
	printf("%s",buf); 


	return 0;
}
