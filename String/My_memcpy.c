#include <stdio.h>
#include <assert.h>
#include <string.h>
void *My_memcpy(void *dest, const void *src, size_t sz)
{
    assert(dest);
    assert(src);
    char *ret = dest;
    while (sz--)
    {
        *(char *)dest = *(char *)src;
        dest = (char *)dest + 1;
        src = (char *)src + 1;
    }

    return ret;
}
int main()
{
    int arr1[10] = {0};
    int arr2[] = {1, 2, 3, 4, 5};
    My_memcpy(arr1, arr2, 20);
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", arr1[i]);
    }
    return 0;
}
