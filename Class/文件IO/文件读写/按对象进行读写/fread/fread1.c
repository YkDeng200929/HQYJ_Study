#include <stdio.h>
#include <string.h>

typedef struct book
{
	char name[10];
	int price;
} book;

int main(void)
{
	FILE *fp;
	book Book1 = {"cpp", 16}, Book2;
	fp = fopen("Bookinfo.txt", "w+");
	if (fp == NULL)
	{
		perror("Bookinfo.txt");
		return -1;
	}
	fwrite(&Book1, sizeof(Book1), 1, fp);
	//fseek(fp, -sizeof(Book1), SEEK_CUR);
	fseek(fp, 0, SEEK_SET );
	//fseek(fp, -sizeof(Book1), SEEK_END);
	//fread(&Book2, sizeof(Book2), 1, fp);
	fread(&Book2, 10, 1, fp);
	printf("%s %d\n", Book2.name, Book2.price);
	fclose(fp);
	
	return 0;
}
