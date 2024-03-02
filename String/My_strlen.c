#include <stdio.h>
#include <assert.h>

size_t My_strlen_1(const char *str)
{
    assert(str);
    if (*str != '\0')
        return 1 + My_strlen_1(str + 1);
    else
        return 0;
}

size_t My_strlen_2(const char *str)
{
    size_t count = 0;
    while (*str != '\0')
    {
        count++;
        str++;
    }
    return count;
}
int main()
{
    char str[] = "Hello Bit!";
    printf("递归:str = %d\n", My_strlen_1(str));
    printf("非递归:str = %d\n", My_strlen_2(str));

    return 0;
}