#include "func.h"

/*
������: init_cls
��������: ��ʼ���༶��Ϣ
��������: Class *cls(���ݿ�), int num_cls(�༶����)
*/
void init_cls(Class *cls, int num_cls)
{
    printf("Please waitting. Initialnizing.........\n");
    cls = (Class *)malloc(sizeof(Class)*num_cls);
    if (cls == NULL)
        printf("Malloc error\n");
}

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
void show_menu(void)
{
}