#ifndef __FUNC_H__
#define __FUNC_H__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 2 // 每个班的最大人数
typedef struct
{
    char name[16];
    int id;
    int score;
    int age;
} Stu;

typedef struct
{
    Stu stu_info[MAX];
    int n;
} Class;

/*
函数名: init_cls
函数功能: 初始化班级信息
函数参数: Class *cls(数据库), int num_cls(班级总数)
*/
void init_cls(Class *cls, int num_cls);

/*
函数名: iput_cls
函数功能: 给班级学生赋值
函数参数: Class *cls(数据库), int num_cls(班级总数)
*/
void iput_cls(Class *cls, int num_cls);

/*
函数名: oput_info
函数功能: 输出所有班级学生的信息
函数参数: Class *cls(数据库), int num_cls(班级总数)
*/
void oput_info(Class *cls, int num_cls);

/*
函数名: del_info
函数功能: 删除指定班级指定学生信息
函数参数: Class *cls(数据库), int cls_num(班级号), int stu_id(学生id)
*/
void del_info(Class *cls, int cls_num, int stu_id);

/*
函数名: mod_info
函数功能: 修改指定班级指定学生信息
函数参数: Class *cls(数据库), int cls_num(班级号), int stu_id(学生if)
*/
void mod_info(Class *cls, int cls_num, int stu_id);

/*
函数名: sort_info
函数功能: 按学生分数高低排列学生信息
函数参数: Class *cls(数据库), int cls_num(班级总数)
*/
void sort_info(Class *cls, int cls_num);

/*
函数名: show_menu
函数功能: 显示数据面板
函数参数: void
*/
void show_menu(void);


#endif