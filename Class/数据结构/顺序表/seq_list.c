#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define MAX 7

struct seqlist 
{
	int data[MAX];
	int length;
};

// ��ʼ��
void init_seqlist(struct seqlist *s)
{
	//memset(s, 0, sizeof(struct seqlist));
	memset(s->data, 0, sizeof(s->data));
	s->length = 0;
}

/*
bool insert_pos_val(struct seqlist *s, int pos, int val)
{
	// judge whether full
	if (s->length == MAX)
		return false;
	if (pos < 0 || pos > s->length)
		return false;
	int i;

	// Insert in middle or final
	for (i = s->length; i > pos; i--)
	{
		s->data[i] = s->data[i-1];
	}
	s->data[pos] = val;
	s->length++;
	return true;
}
*/

// teacher ����λ�ò���
bool insert_pos_val(struct seqlist *s, int pos, int val)
{
	if (s->length == MAX)
		return false;
	if (pos < 0 || pos > s->length)
		return false;
	int i;
	for (i = s->length; i > pos; i--)
	{
		s->data[i] = s->data[i-1];
	}
	// !!!
	s->data[pos] = val;
	s->length++;
	return true;
}

// my ����ֵ����
bool my_insert_val_newval(struct seqlist *s, int val, int newval)
{
	int pos = 0;
	bool judge = false;
	//for (int i = 0; i < MAX; i++)
	for (int i = 0; i < s->length; i++)
	{
		if (s->data[i] != val)
			judge = false;
		else
		{
			pos = i;
			judge = true;
		}
	}
	insert_pos_val(s, pos, newval);
	return judge;
}

// teacher ��ֵ����
bool insert_val_newval(struct seqlist *s, int val, int newval)
{
	int i, pos;

	for (i = 0; i < s->length; i++)
	{
		if (s->data[i] == val)
		{
			pos = i;
			break;
		}
	}
	return insert_pos_val(s, pos, newval);
}


// my ��������
bool my_insert_many_val(struct seqlist *s, int *arr, int pos)
{
	int len = sizeof(arr)/sizeof(arr[0]);
	if (len > MAX - s->length)
	{
		len = MAX - s->length;
	}
	if (pos < 0 || pos > s->length);
}

// teacher ��������
bool insert_many_val(struct seqlist *s, int pos, int *array, int length)
{
	// �ж�����
	int i;
	// ������鳤�ȴ���˳��������, ���ܲ���������ݾͲ����������
	if (length > MAX - s->length)
	{
		length = MAX - s->length;
	}
	if (pos < 0 || pos > length)
		return false;
	for (i = 0; i < length; i++)
	{
		insert_pos_val(s, pos + i, array[i]);
	}
	return true;
}

// my ��λ��ɾ��
bool my_delete_pos_val(struct seqlist *s, int pos)
{
	int i;
	if (pos < 0 || pos >= s->length)
		return false;
	for (i = pos-1; i < s->length; i++)
	{
		s->data[i] = s->data[i+1];
	}
	s->length--;
	return true;
}

// teacher ɾ��Ԫ��
bool delete_pos_val(struct seqlist *s, int pos)
{
	if (s->length == 0)
		return false;
	// length ��û��Ԫ��, ���Բ��ܵ��� length
	if (pos < 0 || pos >= s->length)
		return false;
	int i;
	// !!! ��Ϊ �ƶ��� length - 1 ��ûԪ����
	for (i = pos; i < s->length - 1; i++)
	{
		s->data[i] = s->data[i+1];
	}
	s->length--;
	return true;
}

// my ��ֵɾ��
bool my_del_by_val(struct seqlist *s, int val)
{
	int i, pos;
	bool judge = false;
	for (i = 0; i < MAX; i++)
	{
		if (s->data[i] !=val)
			judge = false;
		else
		{
			judge = true;
			pos = i;
		}
	}
	return delete_pos_val(s, pos);
}

// teacher ��ֵɾ��Ԫ��
bool delete_val_val(struct seqlist *s, int val)
{
	int i, pos = -1;

	for (i = 0; i < s->length; i++)
	{
		if (s->data[i] == val)
		{
			pos = i;
			break;
		}
	}
	return delete_pos_val(s, pos);
}

// my ɾ�����ֵ
bool my_del_many_val(struct seqlist *s, int val1, int val2)
{
	bool judge = false;
	int j = 0, pos_num[5];
	if (val1 < 0 || val2 < 0)
		return false;
	for (int i = 0; i < s->length; i++)
	{
		if (s->data[i] != val1 && s->data[i] != val2)
			judge = false;
		else
		{
			pos_num[j++] = i;
			judge = true;
		}
	}
	pos_num[j] = '\0';
	for (j = 0; pos_num[j]; j++ )
	{
		delete_pos_val(s, pos_num[j]);
	}
	return judge;
}

// teacher ɾ�����Ԫ��
bool delete_many_vals(struct seqlist *s, int val)
{
	int i;
	bool ok;

	for (i = 0; i < s->length; i++)
	{
		if (s->data[i] == val)
		{
			ok = delete_pos_val(s, i);
			if (!ok)
			return false;
			else
			i--;// ���ɾ���ɹ�, ��Ϊ�����ֵǰ��, ���Ԫ��û�б�����
			// �����Ҫ i-- 
		}
	}
	return true;
}

// my �ı�ֵ
bool my_change_val(struct seqlist *s, int pos, int newval)
{
	if (pos < 0 || pos > s->length)
		return false;
	s->data[pos-1] = newval;
	return true;
}

// ��ӡ
void print_seqlist(struct seqlist *s)
{
	int i;
	for (i = 0; i < s->length; i++)
	{
		printf("%d\n", s->data[i]);
	}
}

int main()
{
	struct seqlist seq;
	init_seqlist(&seq);

	insert_pos_val(&seq, 0, 10);
	insert_pos_val(&seq, 1, 20);
	insert_pos_val(&seq, 2, 30);
	insert_pos_val(&seq, 3, 40);

	printf("Before:\n");
	print_seqlist(&seq);
	del_many_val(&seq, 20, 30);
	printf("After:\n");
	print_seqlist(&seq);

	return 0;
}
