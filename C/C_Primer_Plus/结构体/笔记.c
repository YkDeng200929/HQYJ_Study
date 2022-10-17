// 1、建立结构声明
struct book // book 称为结构标记
{
    // 结构体模板里可以定义各种数据，作为模板所具有的属性
    /*
    例如：书 有书名， 作者， 价格。
    所以可以定义三个 数据类型 作为 属性
    */
   char book_name[5];
   char book_author[5];
   int book_price;
}
// 以上 (称作 结构布局) 告诉编译器如何表示数据， 但并未为数据分配空间
// 以下创建结构变量 则为变量分配空间

// 2、定义结构变量 (也可以理解为定义一个对象)

struct book library
// struct book 相当于一般声明中的 int float
/*

1)、结构的内存分配
[][][][][] [][][][][] [    ]
book_name  book_author  book_price

2)、也可以这样定义 结构变量
    struct { 无结构标记
        char title[];
        char author[];
        float value;
    } library;
    或
    struct book {
        char title[];
        char author[];
        float value;
    } library;
*/

// 3、以下是初始化结构

struct book library = {
    "The Pious Pirate and Devious Damsel",
    "Renee Vivotte",
    1.95
};
// 指定初始化如下
struct book library = {
    .value = 25.99,
    .author = "James",
}

// 4、访问 结构体中 元素值 (若将结构体看作数组， 则'.' 运算符相当于 数组下标)
// 将 结构体 看作 数组， 则 结构体变量名 相当于 该结构体数组 地址, '->' 用于访问指针



