#include <stdio.h>
#include <assert.h>

char *My_strcat(char *str1, const char *str2)
{
    assert(str2);

    char *ret = str1;
    while (*str1)
    {
        str1++;
    }
    while (*str1++ = *str2++)
    {
        ;
    }
    return ret;
}
int main()
{
    char str1[] = "Hello";
    char str2[] = " bit!";
    printf("%s\n", My_strcat(str1, str2));

    return 0;
}
