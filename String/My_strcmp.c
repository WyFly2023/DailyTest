#include <stdio.h>
#include <assert.h>

int My_strcmp(const char *str1, const char *str2)
{
    while (*str1 && *str2)
    {
        if (*str1 != *str2)
            return (*str1 - *str2);
        str1++;
        str2++;
    }

    return (*str1 - *str2);
}

int main()
{
    char ch_1[] = "Hello";
    char ch_2[] = "Hello";

    int ret = My_strcmp(ch_1, ch_2);

    if (ret == 0)
        printf("ch_1 = ch_2\n");
    else if (ret > 0)
        printf("ch_1 > ch_2\n");
    else
        printf("ch_1 < ch_2\n");
}