#include <stdio.h>
#include <assert.h>
#include <ctype.h>

int my_atoi(const char *str)
{
    assert(str);
    char *p = (char *)str;
    long long n = 0;
    int flag = 1;

    // 字符串长度为0
    if (*str == '\0')
    {
        return 0;
    }
    // 字符串前面有空格
    while (*p == ' ')
    {
        p++;
    }
    // 判断符号
    if (*p == '+')
    {
        flag = 1;
        p++;
    }
    else if (*p == '-')
    {
        flag = -1;
        p++;
    }

    while (*p != '\0')
    {
        if (isdigit(*p))
            n = n * 10 + flag * (*p - '0');
        else
            break;
        p++;
    }

    return (int)n;
}

int main()
{
    char str1[] = "123";
    char str2[] = "4a56";
    char str3[] = "+78";
    char str4[] = "   90";
    char str5[] = "-56";
    printf("%d\n", my_atoi(str1));
    printf("%d\n", my_atoi(str2));
    printf("%d\n", my_atoi(str3));
    printf("%d\n", my_atoi(str4));
    printf("%d\n", my_atoi(str5));

    return 0;
}
