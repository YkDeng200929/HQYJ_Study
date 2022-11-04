#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool copy(FILE *org, FILE *dest)
{
	char *ret = NULL;
	char buf[1024] = {0};
	while(1)
	{
		ret = fgets(buf, 1024, org);
		if(ret == NULL)
		{
			// new add
			if (feof(org))
			{
				break;
			}
			else
			{
				fprintf(stderr, "fgets fail\n");
				return -1;
			}
		}
		fputs(buf, dest);
	}
	return true;
}

int main(void)
{
	FILE *org, *dest;

	org = fopen("org.txt","r");
	if (org == NULL)
	{
		perror("org");
		return -1;
	}
	dest = fopen("copy.txt", "w");
	if (dest == NULL)
	{
		perror("dest");
		return -1;
	}
	copy(org, dest);
	fclose(org);
	fclose(dest);


	return 0;
}
