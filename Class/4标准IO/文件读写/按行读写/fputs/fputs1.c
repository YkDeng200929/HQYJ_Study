#include <stdio.h>

int main(void)
{
	FILE *fp;
	fp = fopen("org.txt", "r");
	char buf[1024];
	fgets(buf, 20, fp);
	fputs(buf, stdout);
	fclose(fp);


	return 0;
}
