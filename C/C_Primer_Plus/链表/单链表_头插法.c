#include <stdio.h>
#include <stdlib.h>

// ��������
struct Book
{
	char title[128];
	char author[40];
	struct Book* next;
};

void getInput(struct Book* book);

void addBook(struct Book **library);

void printLibrary(struct Book *library);// �ú���ֻ�����library��������ݣ���������ָ��Ԫ�ص����ݣ����Բ���Ҫ**library

void releaseLibrary(struct Book *library);

int main(void)
{
	struct Book *library = NULL; 
	// ����ͷָ��
	// NULL�൱����֮����Ԫ��ͷ�ĵ�ַ��Ҳ����library��ŵ��ǵ�ַ

	int ch;

	while (1)
	{
		printf("Do you want to sign info? (Y/N):");
		do
		{
			ch = getchar();
		} while (ch != 'Y' && ch != 'N');

		if (ch == 'Y')
		{
			addBook(&library);
			// &library��libraryָ������ĵ�ַ
		}
		else
		{
			break;
		}
	}

	printf("Do you want to print info ? (Y/N)");
	do
	{
		ch = getchar();
	} while (ch != 'Y' && ch != 'N');

	if (ch == 'Y')
	{
		printLibrary(library); // �ú���ֻ�����library��������ݣ���������ָ��Ԫ�ص����ݣ����Բ���Ҫ��&library
	}

	releaseLibrary(library);
	
	return 0;
}

// �����鱾��Ϣ
void getInput(struct Book* book)
{
	printf("Enter book name: ");
	scanf("%s", book->title);
	printf("Enter author: ");
	scanf("%s", book->author);
}

// �������в����鱾
void addBook(struct Book **library)
{
    /*  ͷָ��ָ��Ľṹ���ָ����������Ҫ�޸ĵģ�*library�β�����
	    ָ��library�ṹ�屾��**library����ָ�����д�ŵĽṹ���
		��ַ
	*/

	struct Book *book, *temp; 
    /*  ����һ���ṹ�����book�����ڲ����������Ŵ���һ����ʱ������
	    ����֮�����Ԫ��
	*/
	book = (struct Book*)malloc(sizeof(struct Book));
	if (book == NULL)
	{
		printf("malloc error!\n");
		exit(1);
	}

	getInput(book);
	if (*library != NULL)// �����Ƿǿ���������Ԫ����Ҫ��temp��ʱ�������
	{
		temp = *library;
		*library = book;
		book->next = temp;
	}
	else // �����ڲ���Ԫ��ǰΪ����������ֱ��ͷָ��ָ��Ԫ��ͷ��Ԫ��ָ����ָ��βָ�뼴��
	{
		*library = book;  // ͷָ��ָ�������Ԫ�ص�ַ
		book->next = NULL;// ��Ԫ�ص�ָ����ָ��β��ַ
	}
}

// ��ӡ���� 
void printLibrary(struct Book *library)// �ú���ֻ�����library��������ݣ���������ָ��Ԫ�ص����ݣ����Բ���Ҫ**library
{
	struct Book *book;
	int count = 1;

	book = library; // ��ͷָ��library��������ʱ��ӡ����book
	while (book != NULL)
	{
		printf("Book%d", count);
		printf("Book name: %s", book->title);
		printf("Author: %s", book->author);
		book = book->next;
		count++;
	}
}

// �ͷ�����
void releaseLibrary(struct Book *library)
{
	while (library != NULL)
	{
		free(library);
		library = library->next;
	}
}