#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define MAX 4

struct seqlist 
{
	int data[MAX];
	int length;
};

// Initial seqlist
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
	seq.data[0] = 10;
	seq.data[1] = 20;
	seq.data[2] = 30;
	seq.data[3] = 40;
	seq.length = 4;

	printf("Before:\n");
	print_seqlist(&seq);
	insert_pos_val(&seq, 2, 22);
	printf("After:\n");
	print_seqlist(&seq);

	return 0;
}
