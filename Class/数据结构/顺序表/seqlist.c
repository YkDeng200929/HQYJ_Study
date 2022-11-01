#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAXSIZE 10
struct seqlist
{
	int data[MAXSIZE];
	int length;
};

void init_seqlist(struct seqlist *s)//顺序表初始化
{
	memset(s->data, 0, sizeof(s->data));
	s->length = 0;
}

bool insert_pos_val(struct seqlist *s, int pos, int val)
{
	if(s->length == MAXSIZE)//如果当前的顺序表长度达到数组最大长度返回false
	return false;
	if(pos < 0 || pos > s->length)//如果插入位点不对返回false
	return false;
	int i;
	for(i = s->length; i > pos; i--)//插入到中间位置，则把后面的元素依次后移
	{
		s->data[i] = s->data[i-1];
	}
	s->data[pos] = val;//对pos位置进行赋值
	s->length++;//顺序表长度+1
	return true;
}

bool insert_val_newval(struct seqlist *s, int val, int newval)//在对应的值位置插入新的值
{
	int i,pos = -1;
	
	for(i = 0; i < s->length; i++)
	{
		if(s->data[i] == val)
		{
			pos = i;
			break;
		}
	}
	return insert_pos_val(s,pos,newval);
}
void print_seqlist(struct seqlist *s)//遍历顺序表
{
	int i;
	for(i = 0; i < s->length; i++)
	{
		printf("%d\n",s->data[i]);
	}
}

bool insert_many_vals(struct seqlist *s,int pos, int *array, int length )//插入多个元素
{
	int i;
	bool ok;
	if(length > MAXSIZE - s->length)//判断当前顺序表还能插入多少个元素，如果大于那么可能只能插入部分元素或者插入不了新的元素
	{
		length = MAXSIZE - s->length;
	}
	if(pos < 0 || pos > length)
	return false;
	for( i = 0; i < length; i++)
	{
		ok = insert_pos_val(s, pos + i, array[i]);
		if(!ok)
		return false;
	}

	return true;
}

bool delete_pos_val(struct seqlist *s, int pos)//按照位置删除元素
{
	int i;
	if(s->length == 0)//如果顺序表为空则返回false
	return false;
	if(pos < 0 || pos >= s->length)//判断pos是否符合要求
	return false;
	for(i = pos; i < s->length-1;i++)//把pos后面的元素前移
	{
		s->data[i] = s->data[i + 1];
	}
	s->length--;
	return true;
}

bool delete_val_val(struct seqlist *s, int val)//按照值来删除
{
	int i,pos = -1;

	for(i = 0; i < s->length; i++)//遍历顺序表
	{
		if(s->data[i] == val)
		{
			pos = i;
			break;
		}
	}
	return delete_pos_val(s,pos);
}

bool delete_many_vals(struct seqlist *s, int  val)//删除多个重复的值
{
	int i;
	bool ok;
	
	for(i = 0; i < s->length; i++)
	{
		if(s->data[i] == val)
		{
			ok = delete_pos_val(s,i);
			if(!ok)
			return false;
			else//如果删除成功，因为后面的值前移，造成有元素没有遍历到，因此i--
			i--;
		}
	}

	return true;
}
int main()
{
	int arr[] = {60,70,80};
	struct seqlist seq;//定义一个顺序表
	init_seqlist(&seq);
	insert_pos_val(&seq,0,10);
	insert_pos_val(&seq,1,20);
	insert_pos_val(&seq,2,30);
/*	print_seqlist(&seq);*/
/*	insert_val_newval(&seq,20,40);*/
/*	print_seqlist(&seq);*/
/*	insert_many_vals(&seq, 1, arr, sizeof(arr)/sizeof(arr[0]));
	print_seqlist(&seq);*/
/*	delete_pos_val(&seq,1);
	print_seqlist(&seq);*/
/*	delete_val_val(&seq, 30);
	print_seqlist(&seq);*/
	insert_pos_val(&seq,1,20);
	delete_many_vals(&seq,20);
	print_seqlist(&seq);


	return 0;
}
