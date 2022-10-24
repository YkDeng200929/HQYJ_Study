#include <stdio.h>
const char *get_char(const char *target, const char *compare)
{
    // 因为 NULL 是 空指针 的意思， 所以只能 指针 == NULL， 不能 *指针 == NULL
    if (target == NULL || compare == NULL || *target == '\0' || *compare == '\0')
        return NULL;
    int i, j;
    for (i = 0; *target != '\0'; i++)
    {
        for (j = 0; *compare != '\0'; j++)
        {
            if (*target == *compare)
                return target;
            compare +=  j;
        }
        target += i;
    }

    return NULL;
}

int main()
{
    char strings1[] = "hello";
    char strings2[] = "love";
    printf("%c\n", *get_char(strings1, strings2));

    return 0;
}