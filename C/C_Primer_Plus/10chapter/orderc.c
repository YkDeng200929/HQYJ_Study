#include <stdio.h>
int date[2] = {100, 200};
int moredata[2] = {300, 400};
int main(void)
{
	int *pi, *pi2, *pi3;

	pi = pi2 = date;
	pi3 = moredata;
	printf(" *pi = %d, *pi2 = %d,   *pi3 = %d\n", *pi, *pi2, *pi3);
	printf("*pi++ = %d, *++pi2 = %d, (*pi3)++ = %d\n", *pi++, *++pi2, (*pi3)++);
	printf(" *pi = %d, *pi2 = %d,   *pi3 = %d\n", *pi, *pi2, *pi3);

	return 0;
}
