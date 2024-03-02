#include <stdio.h>
#include <assert.h>

char *My_strncpy(char *dest, const char *sorc, size_t n)
{
    assert(dest);
    assert(sorc);
    char *ret = dest;
    while (n--)
    {
        *dest++ = *sorc++;
    }
    return ret;
}
int main()
{
    char ch1[] = "Hello Bit";
    char ch2[20] = {0};
    printf("%s\n", My_strncpy(ch2, ch1, 5));

    return 0;
}