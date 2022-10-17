#include <stdio.h>
#include <string.h>
#define MAXTITL 41 // 书名的最大长度 + 1
#define MAXAUTL 31 // 作者姓名的最大长度 + 1
// 因为 title 是字符串数组
char *s_gets(char *st, int n)
{
    char *ret_val;
    char *find;

    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        find = strchr(st, '\n'); // 查找换行符
        if (find)               // 如果地址不是 NULL
            *find = '\0';       // 在此处放置一个空字符
        else
            while (getchar() != '\n')
            continue;
    }
    return ret_val;
}

struct book {       // 结构模板： 该结构体的标记为book
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
}; /*
    结构体声明完成后记得添加引号，结构体声明方式类似于typedef
*/

int main()
{
    // 该 library 变量 拥有 book 模板的特性
    struct book library; // 把 library 声明为一个 book 类型的变量

    printf("Please enter the book title.\n");
    s_gets(library.title, MAXTITL);     // 访问 title 部分
    printf("Now enter the author.\n");
    s_gets(library.author, MAXAUTL);
    printf("Now enter the value.\n");
    scanf("%f", &library.author);
    printf("%s by %s: $%.2f\n", library.title, library.author, library.value);
    printf("%s: \"%s\" ($%.2f)\n", library.author, library.title, library.value);
    printf("Done\n");

    return 0;
}