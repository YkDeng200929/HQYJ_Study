#include <stdio.h>
#include <stdlib.h> //内存管理用到的头文件
#include <string.h>

/*
常用到的函数
void *calloc(int num, int size); 在内存中动态的分配num个长度为size的空间
                                并将每一个字节都初始化为0.所以他的结果是
                                分配了num*size个字节长度的内存空间，并且
                                每个字节的值都是0
void free(void *address); 该函数释放address所指向的内存块，释放的是动态分配的内存空间
void *malloc(int num); 在堆区分配一块指定大小的内存空间，用来存放数据。这块内存空间在函数
                        执行完成后不会被初始化，他们的值是未知的
void *realloc(void *address, int newsize); 该函数重新分配内存，把内存扩展到newsize

void * 类型表示未确定类型的指针。c/c++规定void*类型可以通过类型转换强制转换为任何其他类型的指针
*/

int main
{
    //实例
    char name[100];
    char *description;

    strcp(name)
    
}