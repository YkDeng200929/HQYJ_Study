#include <stdio.h>
#include <stdlib.h>

struct Book
{
	char title[128];
	char author[40];
	struct Book* next;
};

void getInput(struct Book* book)
{
	printf("请输入书名: ");
	scanf("%s", book->title);
	printf("请输入作者: ");
	scanf("%s", book->author);
}

void addBook(struct Book **library)
{
    /*  头指针指向的结构体的指针是我们需要修改的，*library形参用于
	    指向library结构体本身，**library用于指向其中存放的结构体的
		地址
	*/

	struct Book *book, *temp; 
    /*  创建一个结构体变量book，用于插入链表；接着创建一个临时变量，
	    用于之后插入元素
	*/
	book = (struct Book*)malloc(sizeof(struct Book));
	if (book == NULL)
	{
		printf("内存分配失败!\n");
		exit(1);
	}

	getInput(book); // 录入数据
	if (*library != NULL)// 链表是非空链表，插入元素需要用temp临时存放数据
	{
		temp = *library;
		*library = book;
		book->next = temp;
	}
	else // 链表在插入元素前为空链表，所以直接头指针指向元素头，元素指针域指向尾指针即可
	{
		*library = book;  // 头指针指向待插入元素地址
		book->next = NULL;// 该元素的指针域指向尾地址
	}
}

void printLibrary(struct Book *library)// 该函数只是针对library链表的数据，而不是其指向元素的数据，所以不需要**library
{
	struct Book *book;
	int count = 1;

	book = library; // 将头指针library拷贝给临时打印变量book
	while (book != NULL)
	{
		printf("Book%d", count);
		printf("书名: %s", book->title);
		printf("作者: %s", book->author);
		book = book->next;
		count++;
	}
}

void releaseLibrary(struct Book *library)
{
	while (library != NULL)
	{
		free(library);
		library = library->next;
	}
}

int main(void)
{
	struct Book *library = NULL; 
	// 创建头指针
	// NULL相当于与之链接元素头的地址，也就是library存放的是地址

	int ch;

	while (1)
	{
		printf("是否需要录入信息(Y/N):");
		do
		{
			ch = getchar();
		} while (ch != 'Y' && ch != 'N');

		if (ch == 'Y')
		{
			addBook(&library);
			// &library是library指针变量的地址
		}
		else
		{
			break;
		}
	}

	printf("请问是否需要打印图书信息(Y/N)");
	do
	{
		ch = getchar();
	} while (ch != 'Y' && ch != 'N');

	if (ch == 'Y')
	{
		printLibrary(library); // 该函数只是针对library链表的数据，而不是其指向元素的数据，所以不需要传&library
	}

	releaseLibrary(library);
	
	return 0;
}