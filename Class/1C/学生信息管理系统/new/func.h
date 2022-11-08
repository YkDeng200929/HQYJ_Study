#ifndef __FUNC_H__
#define __FUNC_H__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 2 // ÿ������������
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
������: init_cls
��������: ��ʼ���༶��Ϣ
��������: Class *cls(���ݿ�), int num_cls(�༶����)
*/
void init_cls(Class *cls, int num_cls);

/*
������: iput_cls
��������: ���༶ѧ����ֵ
��������: Class *cls(���ݿ�), int num_cls(�༶����)
*/
void iput_cls(Class *cls, int num_cls);

/*
������: oput_info
��������: ������а༶ѧ������Ϣ
��������: Class *cls(���ݿ�), int num_cls(�༶����)
*/
void oput_info(Class *cls, int num_cls);

/*
������: del_info
��������: ɾ��ָ���༶ָ��ѧ����Ϣ
��������: Class *cls(���ݿ�), int cls_num(�༶��), int stu_id(ѧ��id)
*/
void del_info(Class *cls, int cls_num, int stu_id);

/*
������: mod_info
��������: �޸�ָ���༶ָ��ѧ����Ϣ
��������: Class *cls(���ݿ�), int cls_num(�༶��), int stu_id(ѧ��if)
*/
void mod_info(Class *cls, int cls_num, int stu_id);

/*
������: sort_info
��������: ��ѧ�������ߵ�����ѧ����Ϣ
��������: Class *cls(���ݿ�), int cls_num(�༶����)
*/
void sort_info(Class *cls, int cls_num);

/*
������: show_menu
��������: ��ʾ�������
��������: void
*/
void show_menu(void);


#endif