#include <assert.h>
#include <string.h>
#include <stdio.h>

const char *My_strstr(const char *str, const char *substr)
{
    int strLen = strlen(str);
    int substrLen = strlen(substr);

    for (int i = 0; i <= strLen - substrLen; i++)
    {
        int j;
        for (j = 0; j < substrLen; j++)
        {
            if (str[i + j] != substr[j])
            {
                break;
            }
        }
        if (j == substrLen)
            return &str[i];
    }

    return NULL;
}

const char *My_strstr2(const char *str, const char *substr)
{
    assert(str);
    assert(substr);

    const char *cur = str;
    const char *p;
    while (*cur)
    {
        str = cur;
        p = substr;
        while (*str && *p && *str == *p)
        {
            str++;
            p++;
        }
        if (*p == '\0')
            return cur;
        cur++;
    }

    return NULL;
}

int main()
{
    char str1[] = "Hello bi bi btbit!";
    char str2[] = "bit";
    printf("%s\n", My_strstr(str1, str2));
    printf("%s\n", My_strstr2(str1, str2));

    return 0;
}