#include <assert.h>
#include <stdio.h>

void *My_memmove(void *dest, const void *src, size_t sz)
{
    assert(dest);
    assert(src);

    char *ret = dest;
    if (dest < src)
    {
        while (sz--)
        {
            *((char *)dest) = *((char *)src);
            dest = (char *)dest + 1;
            src = (char *)src + 1;
        }
    }

    else
    {
        while (sz--)
        {
            *((char *)dest + sz) = *((char *)src + sz);
        }
    }

    return ret;
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    My_memmove(arr, arr + 3, 20);
    int i = 0;
    for (i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
        printf("%2d", arr[i]);
    printf("\n");

    printf("--------------------\n");
    My_memmove(arr + 3, arr, 20);

    i = 0;
    for (i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
        printf("%2d", arr[i]);
    printf("\n");

    return 0;
}