#include <stdio.h>
#include <string.h>
// foef() function

int main(void)
{
	char *ret = NULL;
	char buf[1024];

	while (1)
	{
		ret = fgets(buf, 1024, stdin);
		if (ret == NULL || strncmp(buf, "quit",4) == 0)
		{
			if (feof(stdin))
			{
				break;
			}
			else
			{
				return -1;
			}
		}
		buf[strlen(buf) - 1] = '\0';
				
		fputs(buf, stdout);
	}


	return 0;
}
