#include <stdio.h>
voi mikao(int bah){
	int pooh = 10;

	printf("In mikado(), pooh = %d and &pooh = %p\n", pooh, &pooh);
	printf("In mikado(), bah = 2 and &bah = %p\n", bah, &bah);

	return 0;
}

int main(void)
{
	int pooh = 2, bah = 5;

	printf("In main(), pooh = %d and &pooh = %p\n", pooh, &pooh);
	printf("In main(), bah = %d and &bah = %p\n", bah, &bah);

	return 0;
}
