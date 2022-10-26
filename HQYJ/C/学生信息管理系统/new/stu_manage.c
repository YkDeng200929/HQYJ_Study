#include <stdio.h>
#include "func.h"

int main()
{
    Class *HQYJ = NULL;
    int num_cls = 0;
    printf("How many classes in HQYJ?: ");
    scanf("%d\n", &num_cls);
    init_cls(HQYJ, num_cls);
    show_menu();

    return 0;
}