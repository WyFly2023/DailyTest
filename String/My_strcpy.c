#include <stdio.h>
#include <assert.h>

char *My_strcpy(char *dest, const char *source)
{
    assert(dest);
    assert(source);

    char *ret = dest;
    while (*dest++ = *source++)
    {
        ;
    }
    return ret;
}
int main()
{
    char arr1[20] = {0};
    char arr2[] = "Hello Bit!";
    printf("%s\n", My_strcpy(arr1, arr2));

    return 0;
}