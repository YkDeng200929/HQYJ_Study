#include <stdio.h>
#include <string.h>
#define MAXTITL 40
#define MAXAUTL 40

// 个人理解： book 相当于类， 结构体数组(library) 中的每个元素 相当于 对象， 拥有类的属性

struct book             // 建立 book 模板
{
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
};
// 此时 struct book 相当于 一个类别， 类似于 int, float


/*
函数功能： 给结构体数组 每个元素 赋值
函数名： get_book
函数参数： struct book *library
*/
void get_book(struct book *library)
{
    printf("Enter title:\n");
    scanf("%s", library->title);// 因为 字符串数组名 就相当于 字符串地址
    printf("Enter author name:\n");
    scanf("%s", library->author);
    printf("Enter the book price:\n");
    scanf("%f", &library->value);
}

/*
函数功能： 打印 结构体数组内容
函数名： print_struct
函数参数； struct book *library, int len
*/
void print_struct(struct book *library, int len)
{
    int i;
    for (i = 0; i < len; i++)   
    {
        // 因为 title是一个指针，所以需要使用 '->' 来访问元素
        printf("Book name:%s", library->title);
        printf("Book author:%s", library->author);
        printf("Book price:%f", library->value);
    }
}

int main(void)
{ 
    // 定义数组 library, 每个元素都是 struct book 类型
    struct book library[5];
    
    // 以下 为每个 结构体元素 赋予 属性值
    int i;
    for (i = 0; i < 5; i++)
    {
        get_book(library);
    }
    print_struct(library, 5);


    return 0;
}