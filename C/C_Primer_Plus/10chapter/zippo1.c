#include <stdio.h>
int main(void)
{
	int zippo[4][2] = {
		{2, 4},
		{6, 8},
		{1, 3},
		{5, 7}	
	};

	printf("  zippo = %p,     zippo + 1 = %p, &zipo[1][0] = %p\n", zippo, zippo + 1, &zippo[1][0]);           //000001    000005
	printf("zippo[0] = %p, zippo[0] + 1 = %p, &zippo[0][1] = %p\n", zippo[0], zippo[0] + 1, &zippo[0][1]);    //000010    000014
	printf("  *zippo = %p,   *zippo + 1 = %p\n", *zippo, *zippo + 1);        //{2, 4}    {6, 8}
	printf("zippo[0][0] = %d\n", zippo[0][0]);                              //2
	printf("  *zippo[0] = %d\n", *zippo[0]);                                //2
	printf("  **zippo = %d\n", **zippo);                                    //2
	printf("    zippo[2][1] = %d\n", zippo[2][1]);                          //3
	printf("*(*(zippo+2) + 1) = %d\n", *(*(zippo+2) + 1));                  //3

	return 0;
}
